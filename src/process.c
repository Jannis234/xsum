/* This file is part of xsum.
 *
 * xsum is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xsum is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xsum. If not, see <http://www.gnu.org/licenses/>. */

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"
#include "cli.h"
#include "config.h"
#include "xsum.h"
#ifdef XSUM_WITH_MMAP
#include <sys/mman.h>
#include <sys/stat.h>
#endif

#define BUFSIZE (1024 * 1024)

#ifdef XSUM_WITH_OPENMP
#define BUFSIZE_MAX (1024 * 1024 * 128) // Maximum amount of memory with openmp enabled (no significant performance benefit from using more)
extern uint32_t xsum_threads;
#endif

int xsum_process(char *filename, xsum_algo_result_t *results, int algos_count, bool ignore_missing) {
	
	FILE *fd = stdin;
	if (filename == NULL) {
		filename = "-";
	} else {
		fd = fopen(filename, "rb+"); // Request writing to check if filename points to a directory
		if (fd == NULL && errno != EISDIR) { // Not a directory, retry without write access (in case the file is read only)
			fd = fopen(filename, "rb");
		}
	}
	if (fd == NULL) {
		if (ignore_missing && errno == ENOENT) {
			return -1;
		}
		fprintf(stderr, "%s: Unable to open file", filename);
		if (errno == ENOENT) {
			fprintf(stderr, ": No such file or directory");
		} else if (errno == EACCES) {
			fprintf(stderr, ": Permission denied");
		} else if (errno == EISDIR) {
			fprintf(stderr, ": Is a directory");
		}
		fprintf(stderr, "\n");
		return RETURN_FILE_ERROR;
	}
	
	bool use_mmap = false;
	uint8_t *buf = NULL;
	size_t bytes_read = 0;
#ifdef XSUM_WITH_MMAP
	if (fd != stdin) {
		int fd2 = fileno(fd);
		struct stat s;
		if (fstat(fd2, &s) == 0) {
			buf = mmap(NULL, s.st_size, PROT_READ, MAP_SHARED, fd2, 0);
			if (buf != MAP_FAILED) {
				use_mmap = true;
				bytes_read = s.st_size;
			}
		}
	}
#endif
	
	if (!use_mmap) {
		buf = malloc(BUFSIZE);
		if (buf == NULL) {
			fprintf(stderr, "%s: Out of memory\n", filename);
			fclose(fd);
			return RETURN_FILE_ERROR;
		}
	}
	
	for (int i = 0; i < algos_count; i++) {
		if (results[i].enabled) {
			results[i].state = xsum_algos[i]->func_init();
			if (results[i].state == NULL) {
				fprintf(stderr, "%s: Out of memory\n", filename);
				for (int j = 0; j < i; j++) {
					if (results[j].enabled) {
						uint8_t *hash = xsum_algos[j]->func_final(results[j].state); // Free any previous states
						if (hash != NULL) { // func_final might allocate memory for the hash, free that too
							free(hash);
						}
					}
				}
				fclose(fd);
				free(buf);
				return RETURN_FILE_ERROR;
			}
		}
	}
	
#if defined(XSUM_WITH_OPENMP) && defined(XSUM_WITH_LIBB2)
	// libb2 uses OpenMP for BLAKE2sp/BLAKE2bp and produces incorrect output when called from a thread that also uses OpenMP
	// Remember what is enabled now and run it from a regular (single-threaded) loop later
	bool blake2sp_enabled[32];
	bool blake2bp_enabled[64];
	int blake2sp_offset = 0;
	int blake2bp_offset = 0;
	for (int i = 0; i < algos_count; i++) {
		if (strcmp(xsum_algos[i]->name, "BLAKE2sp-8") == 0) {
			blake2sp_offset = i;
			i += 32;
		} else if (strcmp(xsum_algos[i]->name, "BLAKE2bp-8") == 0) {
			blake2bp_offset = i;
			i += 64;
		}
	}
	for (int i = 0; i < 32; i++) {
		blake2sp_enabled[i] = results[blake2sp_offset + i].enabled;
		results[blake2sp_offset + i].enabled = false;
	}
	for (int i = 0; i < 64; i++) {
		blake2bp_enabled[i] = results[blake2bp_offset + i].enabled;
		results[blake2bp_offset + i].enabled = false;
	}
#endif
	
	size_t bufsize = BUFSIZE;
	do {
		if (!use_mmap) {
			bytes_read = fread(buf, 1, bufsize, fd);
		}
		if (bytes_read > 0) {
#ifdef XSUM_WITH_OPENMP
			#pragma omp parallel for
#endif
			for (int i = 0; i < algos_count; i++) {
				if (results[i].enabled) {
					xsum_algos[i]->func_update(results[i].state, buf, bytes_read);
				}
			}
#if defined(XSUM_WITH_OPENMP) && defined(XSUM_WITH_LIBB2)
			for (int i = 0; i < 32; i++) {
				if (blake2sp_enabled[i]) {
					xsum_algos[blake2sp_offset + i]->func_update(results[blake2sp_offset + i].state, buf, bytes_read);
				}
			}
			for (int i = 0; i < 64; i++) {
				if (blake2bp_enabled[i]) {
					xsum_algos[blake2bp_offset + i]->func_update(results[blake2bp_offset + i].state, buf, bytes_read);
				}
			}
#endif
		}
#ifdef XSUM_WITH_OPENMP
		if (xsum_threads != 1 && !use_mmap) {
			if (bufsize < BUFSIZE_MAX) { // With a small buffer, we get bottlenecked by the slowest algorithm(s), slowly grow it when processing a large file
				uint8_t *newbuf = realloc(buf, bufsize * 2);
				if (newbuf != NULL) {
					buf = newbuf;
					bufsize *= 2;
				}
			}
		}
		if (use_mmap) {
			break; // Only do a single loop iteration with mmap
		}
#endif
	} while (bytes_read > 0);
#if defined(XSUM_WITH_OPENMP) && defined(XSUM_WITH_LIBB2)
	for (int i = 0; i < 32; i++) {
		results[blake2sp_offset + i].enabled = blake2sp_enabled[i];
	}
	for (int i = 0; i < 64; i++) {
		results[blake2bp_offset + i].enabled = blake2bp_enabled[i];
	}
#endif
	if (!use_mmap) {
		free(buf);
		if (!feof(fd)) {
			fprintf(stderr, "%s: Unable to read file\n", filename);
			fclose(fd);
			return RETURN_FILE_ERROR;
		}
	}
#ifdef XSUM_WITH_MMAP
	if (use_mmap) {
		munmap(buf, bytes_read);
	}
#endif
	fclose(fd);
	
	bool error_memory = false;
	bool error_compare = false;
	for (int i = 0; i < algos_count; i++) {
		if (results[i].enabled) {
			uint8_t *hash = xsum_algos[i]->func_final(results[i].state);
			if (hash == NULL) {
				error_memory = true;
			}
			if (results[i].hash == NULL) {
				results[i].hash = hash;
			} else if (hash != NULL) {
				if (memcmp(results[i].hash, hash, xsum_algos[i]->length) != 0) {
					error_compare = true;
				}
				free(hash);
			}
		}
	}
	if (error_memory) {
		fprintf(stderr, "%s: Out of memory\n", filename);
		for (int i = 0; i < algos_count; i++) {
			if (results[i].enabled && results[i].hash != NULL) {
				free(results[i].hash);
				results[i].hash = NULL;
			}
		}
		return RETURN_FILE_ERROR;
	}
	if (error_compare) {
		return RETURN_CHECK_INVALID;
	}
	return RETURN_OK;
	
}
