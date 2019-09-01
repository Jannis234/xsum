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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"
#include "cli.h"
#include "xsum.h"

#define BUFSIZE (1024 * 1024)

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
				return RETURN_FILE_ERROR;
			}
		}
	}
	
	uint8_t *buf = malloc(BUFSIZE);
	if (buf == NULL) {
		fprintf(stderr, "%s: Out of memory\n", filename);
		fclose(fd);
		return RETURN_FILE_ERROR;
	}
	
	size_t bytes_read = 0;
	do {
		bytes_read = fread(buf, 1, BUFSIZE, fd);
		if (bytes_read > 0) {
			for (int i = 0; i < algos_count; i++) {
				if (results[i].enabled) {
					xsum_algos[i]->func_update(results[i].state, buf, bytes_read);
				}
			}
		}
	} while (bytes_read > 0);
	free(buf);
	if (!feof(fd)) {
		fprintf(stderr, "%s: Unable to read file\n", filename);
		fclose(fd);
		return RETURN_FILE_ERROR;
	}
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
