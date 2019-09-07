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
#include "config.h"
#include "xsum.h"

#define BUFSIZE (1024 * 100)

int print_file(char *filename, xsum_algo_result_t *results, int algos_count, bool ignore_missing) {
	
	int ret = xsum_process(filename, results, algos_count, ignore_missing);
	if (ret == -1) { // File not found with ignore_missing = true
		return RETURN_OK;
	} else if (ret != RETURN_OK) {
		return ret;
	}
	for (int i = 0; i < algos_count; i++) {
		if (results[i].enabled) {
			printf("%s:", xsum_algos[i]->name);
			for (int j = 0; j < xsum_algos[i]->length; j++) {
				printf("%02x", results[i].hash[j]);
			}
			printf(" ");
			free(results[i].hash);
			results[i].hash = NULL; // Reset for the next file
		}
	}
	if (filename == NULL) {
		printf(" -\n");
	} else {
		printf(" %s\n", filename);
	}
	return ret;
	
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
		{ "help", 'h', false, false, NULL },
		{ "version", 'v', false, false, NULL },
		{ "check", 'c', false, false, NULL },
		{ "quiet", 'q', false, false, NULL },
		{ "algo", 'a', true, false, NULL },
		{ "ignore-unknown", 0, false, false, NULL },
		{ "ignore-missing", 0, false, false, NULL },
		{ "list-algos", 0, false, false, NULL }
	};
	size_t options_count = sizeof(options) / sizeof(xsum_argparse_t);
	bool *argv_filenames = malloc(sizeof(bool) * (argc + 1));
	if (argv_filenames == NULL) {
		fprintf(stderr, "Out of memory\n");
		return RETURN_ERROR;
	}
	if (!xsum_argparse(options, options_count, argv, argc, argv_filenames)) {
		return RETURN_ERROR;
	}
	
	int algos_count = 0;
	while (xsum_algos[algos_count] != NULL) {
		algos_count++;
	}
	
	if (options[xsum_find_option(options, options_count, false, "h")].found) {
		xsum_print_help();
		return RETURN_OK;
	} else if (options[xsum_find_option(options, options_count, false, "v")].found) {
		xsum_print_version();
		return RETURN_OK;
	} else if (options[xsum_find_option(options, options_count, true, "list-algos")].found) {
		printf("Supported algorithms:\n");
		for (int i = 0; i < algos_count; i++) {
			printf("  %s\n", xsum_algos[i]->name);
		}
		return RETURN_OK;
	}
	
	xsum_algo_result_t *results = malloc(sizeof(xsum_algo_result_t) * algos_count);
	if (results == NULL) {
		free(argv_filenames);
		return RETURN_ERROR;
	}
	
	int option_algos = xsum_find_option(options, options_count, false, "a");
	if (options[option_algos].found) {
		if (options[xsum_find_option(options, options_count, false, "c")].found) {
			fprintf(stderr, "Can not use --check and --algo at the same time\n");
			return RETURN_ERROR;
		}
		for (int i = 0; i < algos_count; i++) {
			results[i].enabled = false;
		}
		char *arg_out = options[option_algos].arg_out;
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
				return RETURN_ERROR;
			}
			results[algo_index].enabled = true;
			item_end++;
			item_start = item_end;
		}
	} else {
		for (int i = 0; i < algos_count; i++) {
			results[i].enabled = true;
		}
	}
	
	int files_count = 0;
	for (int i = 1; i < argc; i++) {
		if (argv_filenames[i]) {
			files_count++;
		}
	}
	bool ignore_missing = options[xsum_find_option(options, options_count, true, "ignore-missing")].found;
	ret = RETURN_OK;
	if (options[xsum_find_option(options, options_count, false, "c")].found) {
		bool ignore_unknown = options[xsum_find_option(options, options_count, true, "ignore-unknown")].found;
		bool quiet = options[xsum_find_option(options, options_count, false, "q")].found;
		if (files_count == 0) {
			ret = check_file(NULL, results, algos_count, ignore_unknown, ignore_missing, quiet);
		} else {
			for (int i = 1; i < argc; i++) {
				if (argv_filenames[i]) {
					int ret2 = check_file(argv[i], results, algos_count, ignore_unknown, ignore_missing, quiet);
					if (ret2 > ret) {
						ret = ret2;
					}
				}
			}
		}
	} else {
		for (int i = 0; i < algos_count; i++) {
			results[i].hash = NULL;
		}
		if (files_count == 0) {
			ret = print_file(NULL, results, algos_count, ignore_missing);
		} else {
			for (int i = 1; i < argc; i++) {
				if (argv_filenames[i]) {
					int ret2 = print_file(argv[i], results, algos_count, ignore_missing);
					if (ret2 > ret) {
						ret = ret2;
					}
				}
			}
		}
	}
	
	free(argv_filenames);
	free(results);
	return ret;
	
}
