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
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"
#include "cli.h"
#include "compress.h"
#include "config.h"
#include "xsum.h"

#define BUFSIZE (1024 * 100)

#ifdef XSUM_WITH_OPENMP
#include <omp.h>
uint32_t xsum_threads;
#endif

char* output_string(char *filename, xsum_algo_result_t *results, int algos_count) {
	
	if (filename == NULL) {
		filename = "-";
	}
	size_t len = 0;
	for (int i = 0; i < algos_count; i++) {
		if (results[i].enabled) {
			len += strlen(xsum_algos[i]->name);
			len += xsum_algos[i]->length * 2;
			len += 2; // Space and colon
		}
	}
	len += strlen(filename);
	len++; // NULL terminator
	
	char *res = malloc(len);
	if (res == NULL) {
		return NULL;
	}
	char *buf = res;
	char *hex_chars = "0123456789abcdef";
	for (int i = 0; i < algos_count; i++) {
		if (results[i].enabled) {
			strcpy(buf, xsum_algos[i]->name);
			buf += strlen(xsum_algos[i]->name);
			*buf = ':';
			buf++;
			for (int j = 0; j < xsum_algos[i]->length; j++) {
				*buf = hex_chars[results[i].hash[j] / 16];
				buf++;
				*buf = hex_chars[results[i].hash[j] % 16];
				buf++;
			}
			free(results[i].hash);
			results[i].hash = NULL; // Reset for the next file
			*buf = ' ';
			buf++;
		}
	}
	strcpy(buf, filename);
	return res;
	
}

int check_file(char *filename, xsum_algo_result_t *results, int algos_count, bool ignore_unknown, bool ignore_missing, bool quiet) {
	
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
	
	uint64_t pos = 0;
	uint8_t *buf = malloc(BUFSIZE);
	if (buf == NULL) {
		fprintf(stderr, "%s: Out of memory\n", filename);
		fclose(fd);
		return RETURN_FILE_ERROR;
	}
	size_t bytes_read;
	do {
		bytes_read = fread(buf + pos, 1, BUFSIZE, fd);
		pos += bytes_read;
		if (bytes_read == BUFSIZE) {
			uint8_t *buf2 = realloc(buf, pos + BUFSIZE);
			if (buf2 == NULL) {
				free(buf);
				fclose(fd);
				fprintf(stderr, "%s: Out of memory\n", filename);
				return RETURN_FILE_ERROR;
			}
			buf = buf2;
		}
	} while (bytes_read > 0 && !feof(fd));
	if (!feof(fd)) {
		fprintf(stderr, "%s: Unable to read file", filename);
		free(buf);
		fclose(fd);
		return RETURN_FILE_ERROR;
	}
	fclose(fd);
	
	if (buf[0] == 0x1F && buf[1] == 0x8B) {
#ifdef XSUM_WITH_ZLIB_COMPRESS
		uint64_t pos2;
		uint8_t *buf2 = xsum_decompress_file(filename, buf, pos, &pos2);
		free(buf);
		if (buf2 == NULL) {
			return RETURN_FILE_ERROR;
		}
		buf = buf2;
		pos = pos2;
#else
		fprintf(stderr, "%s: Compressed file (not supported by this build of xsum)\n", filename);
		free(buf);
		return RETURN_FILE_ERROR;
#endif
	}
	
	int ret = xsum_parse(filename, buf, pos, results, algos_count, ignore_unknown, ignore_missing, quiet);
	free(buf);
	return ret;
	
}

bool compare_case(char *buf1, char *buf2, size_t len) {
	
	while (len > 0) {
		char c1 = *buf1;
		char c2 = *buf2;
		if (c1 >= 'a') {
			c1 -= ('a' - 'A');
		}
		if (c2 >= 'a') {
			c2 -= ('a' - 'A');
		}
		if (c1 != c2) {
			return false;
		}
		buf1++;
		buf2++;
		len--;
	}
	return true;
	
}

int main(int argc, char **argv) {
	
	int ret = xsum_lib_init();
	if (ret != RETURN_OK) {
		return ret;
	}
	
	xsum_argparse_t options[] = {
		XSUM_ARGPARSE_ENTRY("help", 'h', false)
		XSUM_ARGPARSE_ENTRY("version", 'v', false)
		XSUM_ARGPARSE_ENTRY("debug", 0, false)
		XSUM_ARGPARSE_ENTRY("check", 'c', false)
		XSUM_ARGPARSE_ENTRY("quiet", 'q', false)
		XSUM_ARGPARSE_ENTRY("algos", 'a', true)
		XSUM_ARGPARSE_ENTRY("exclude-algos", 'e', true)
		XSUM_ARGPARSE_ENTRY("ignore-unknown", 0, false)
		XSUM_ARGPARSE_ENTRY("ignore-missing", 0, false)
		XSUM_ARGPARSE_ENTRY("list-algos", 0, false)
#ifdef XSUM_WITH_OPENMP
		XSUM_ARGPARSE_ENTRY("threads", 't', true)
#endif
#ifdef XSUM_WITH_ZLIB_COMPRESS
		XSUM_ARGPARSE_ENTRY("compress", 'z', false)
#endif
	};
	size_t options_count = sizeof(options) / sizeof(xsum_argparse_t);
	bool *argv_filenames = malloc(sizeof(bool) * (argc + 1));
	if (argv_filenames == NULL) {
		fprintf(stderr, "Out of memory\n");
		return RETURN_ERROR;
	}
	if (!xsum_argparse(options, options_count, argv, argc, argv_filenames)) {
		free(argv_filenames);
		return RETURN_ERROR;
	}
	
	int algos_count = 0;
	while (xsum_algos[algos_count] != NULL) {
		algos_count++;
	}
	
	if (options[xsum_find_option(options, options_count, false, "h")].found) {
		xsum_print_help();
		free(argv_filenames);
		return RETURN_OK;
	} else if (options[xsum_find_option(options, options_count, false, "v")].found) {
		xsum_print_version();
		free(argv_filenames);
		return RETURN_OK;
	} else if (options[xsum_find_option(options, options_count, true, "debug")].found) {
		xsum_build_info();
		free(argv_filenames);
		return RETURN_OK;
	} else if (options[xsum_find_option(options, options_count, true, "list-algos")].found) {
		printf("Supported algorithms:\n");
		for (int i = 0; i < algos_count; i++) {
			printf("  %s\n", xsum_algos[i]->name);
		}
		free(argv_filenames);
		return RETURN_OK;
	}
	int option_algos = xsum_find_option(options, options_count, false, "a");
	int option_exclude = xsum_find_option(options, options_count, false, "e");
	int option_check = xsum_find_option(options, options_count, false, "c");
	if (options[option_algos].found && options[option_exclude].found) {
		fprintf(stderr, "Can not use --algos and --exclude-algos at the same time\n");
		free(argv_filenames);
		return RETURN_ERROR;
	}
	if ((options[option_algos].found || options[option_exclude].found) && options[option_check].found) {
		fprintf(stderr, "Can not use --check and --algos/--exclude-algos at the same time\n");
		free(argv_filenames);
		return RETURN_ERROR;
	}
#ifdef XSUM_WITH_ZLIB_COMPRESS
	int option_compress = xsum_find_option(options, options_count, false, "z");
	if (options[option_check].found && options[option_compress].found) {
		fprintf(stderr, "Can not use --check and --compress at the same time\n");
		free(argv_filenames);
		return RETURN_ERROR;
	}
#endif
#ifdef XSUM_WITH_OPENMP
	xsum_threads = 0;
	int option_threads = xsum_find_option(options, options_count, false, "t");
	if (options[option_threads].found) {
		char *endptr;
		xsum_threads = strtol(options[option_threads].arg_out, &endptr, 10);
		if (*endptr != 0) {
			fprintf(stderr, "Invalid argument for --threads\n");
			free(argv_filenames);
			return RETURN_ERROR;
		}
		if (xsum_threads > omp_get_thread_limit()) {
			fprintf(stderr, "Invalid number of threads\n");
			free(argv_filenames);
			return RETURN_ERROR;
		}
		if (xsum_threads != 0) {
			omp_set_num_threads(xsum_threads);
		}
	}
#endif
	
	xsum_algo_result_t *results = malloc(sizeof(xsum_algo_result_t) * algos_count);
	if (results == NULL) {
		free(argv_filenames);
		return RETURN_ERROR;
	}
	
	if (options[option_algos].found || options[option_exclude].found) {
		for (int i = 0; i < algos_count; i++) {
			results[i].enabled = options[option_exclude].found; // Default everything to enabled with --exclude-algos, disabled with --algos
		}
		char *arg_out = (options[option_algos].found) ? options[option_algos].arg_out : options[option_exclude].arg_out;
		size_t arg_len = strlen(arg_out);
		size_t item_start = 0;
		size_t item_end = 0;
		while (item_end < arg_len) {
			while (item_end < arg_len && arg_out[item_end] != ',') {
				item_end++;
			}
			size_t item_len = item_end - item_start;
			int algo_index = -1;
			for (int i = 0; i < algos_count; i++) {
				if (compare_case(arg_out + item_start, xsum_algos[i]->name, item_len)) {
					algo_index = i;
					break;
				}
			}
			if (algo_index == -1) {
				fprintf(stderr, "Unknown algorithm \"");
				for (size_t i = item_start; i < item_end; i++) {
					fputc(arg_out[i], stderr);
				}
				fprintf(stderr, "\"\n");
				free(results);
				return RETURN_ERROR;
			}
			results[algo_index].enabled = options[option_algos].found; // Enable with --algos, disable with --exclude-algos
			item_end++;
			item_start = item_end;
		}
	} else {
		for (int i = 0; i < algos_count; i++) {
			results[i].enabled = true;
		}
	}
	
	bool ignore_missing = options[xsum_find_option(options, options_count, true, "ignore-missing")].found;
	ret = RETURN_OK;
	if (options[option_check].found) {
		bool ignore_unknown = options[xsum_find_option(options, options_count, true, "ignore-unknown")].found;
		bool quiet = options[xsum_find_option(options, options_count, false, "q")].found;
		for (int i = 1; i < argc; i++) {
			if (argv_filenames[i]) {
				int ret2 = check_file(argv[i], results, algos_count, ignore_unknown, ignore_missing, quiet);
				if (ret2 > ret) {
					ret = ret2;
				}
			}
		}
	} else {
#ifdef XSUM_WITH_ZLIB_COMPRESS
		void *compress_state = NULL;
		if (options[option_compress].found) {
			compress_state = xsum_compress_init();
			if (compress_state == NULL) {
				fprintf(stderr, "Out of memory\n");
				free(argv_filenames);
				free(results);
				return RETURN_FILE_ERROR;
			}
		}
#endif
		for (int i = 0; i < algos_count; i++) {
			results[i].hash = NULL;
		}
		for (int i = 1; i < argc; i++) {
			if (argv_filenames[i]) {
				int ret2 = xsum_process(argv[i], results, algos_count, ignore_missing);
				if (ret2 == -1) { // File not found with ignore_missing = true
					ret2 = RETURN_OK;
				} else if (ret2 == RETURN_OK) {
					char *str = output_string(argv[i], results, algos_count);
					if (str == NULL) {
						ret2 = RETURN_FILE_ERROR;
					} else {
#ifdef XSUM_WITH_ZLIB_COMPRESS
						if (options[option_compress].found) {
							xsum_compress_string(compress_state, str);
						} else {
#endif
							printf("%s\n", str);
#ifdef XSUM_WITH_ZLIB_COMPRESS
						}
#endif
						free(str);
					}
				}
				if (ret2 > ret) {
					ret = ret2;
				}
			}
		}
#ifdef XSUM_WITH_ZLIB_COMPRESS
		if (options[option_compress].found) {
			xsum_compress_end(compress_state);
		}
#endif
	}
	
	free(argv_filenames);
	free(results);
	return ret;
	
}
