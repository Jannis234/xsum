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

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"
#include "cli.h"
#include "xsum.h"

void print_string(uint8_t *buf, uint64_t start, uint64_t end) {
	
	for (uint64_t i = start; i <= end; i++) {
		fputc(buf[i], stderr);
	}
	
}

void results_cleanup(xsum_algo_result_t *results, int algos_count) {
	
	for (int i = 0; i < algos_count; i++) {
		if (results[i].hash != NULL) {
			free(results[i].hash);
		}
	}
	
}

bool parse_hex_char(char c, int *out) {
	
	if (c >= '0' && c <= '9') {
		*out = c - '0';
		return true;
	} else if (c >= 'a' && c <= 'f') {
		*out = c - 'a' + 10;
		return true;
	} else if (c >= 'A' && c <= 'F') {
		*out = c - 'A' + 10;
		return true;
	} else {
		return false;
	}
	
}

int parse_line(char *filename, uint8_t *buf, uint64_t len, xsum_algo_result_t *results, int algos_count, bool ignore_unknown, bool ignore_missing, bool quiet) {
	
	uint64_t filename_end = len - 1;
	while (filename_end > 0 && buf[filename_end] == ' ') {
		filename_end--;
	}
	if (filename_end == 0) {
		return -1; // Skip empty line
	}
	uint64_t filename_start = filename_end - 1;
	while (filename_start > 0 && buf[filename_start] != ' ') {
		filename_start--;
	}
	if (filename_start != 0) {
		filename_start++;
	}
	char *filename_buf = malloc(filename_end - filename_start + 2);
	if (filename_buf == NULL) {
		fprintf(stderr, "%s: Out of memory\n", filename);
		return RETURN_FILE_ERROR;
	}
	memcpy(filename_buf, buf + filename_start, filename_end - filename_start + 1);
	filename_buf[filename_end - filename_start + 1] = 0;
	if (filename_start == 0) {
		fprintf(stderr, "%s: No hashes found\n", filename_buf);
		free(filename_buf);
		return RETURN_CHECK_MALFORMED;
	}
	
	for (int i = 0; i < algos_count; i++) {
		results[i].enabled = false;
		results[i].hash = NULL;
	}
	bool found_unknown = false;
	uint64_t pos = filename_start - 1;
	while (pos > 0) {
		while (buf[pos] == ' ' && pos > 0) {
			pos--;
		}
		uint64_t hash_end = pos;
		while (pos > 0 && buf[pos] != ' ') {
			pos--;
		}
		uint64_t hash_start = pos;
		if (hash_start != 0) { // If this is not the start of the line, hash_start would point to a space character
			hash_start++;
		}
		if (hash_start < hash_end) { // Make sure that there is a hash and we haven't found the end of the buffer
			uint64_t hash_sep = hash_start;
			while (hash_sep < hash_end && buf[hash_sep] != ':') {
				hash_sep++;
			}
			if (hash_sep == hash_start || hash_sep == hash_end) {
				fprintf(stderr, "%s: Invalid line format\n", filename_buf);
				free(filename_buf);
				results_cleanup(results, algos_count);
				return RETURN_CHECK_MALFORMED;
			}
			uint64_t hash_name_length = hash_sep - hash_start;
			int algo_index = -1;
			for (int i = 0; i < algos_count; i++) {
				char *name = xsum_algos[i]->name;
				// EDON-R-512 workaround (see output_string() in main.c)
				if (strcmp(name, "EDON-R-512") == 0) {
					name = "EDON-R-512_";
				}
				
				if (hash_name_length == strlen(name)) {
					if (strncmp((char*) (buf + hash_start), name, hash_name_length) == 0) {
						algo_index = i;
						break;
					}
				}
			}
			if (algo_index == -1) {
				fprintf(stderr, "%s: Unknown hash \"", filename_buf);
				print_string(buf, hash_start, hash_sep - 1);
				fprintf(stderr, "\"\n");
				found_unknown = true;
			} else {
				if (results[algo_index].enabled) { // Same hash found twice in the same line
					fprintf(stderr, "%s: Invalid line format\n", filename_buf);
					free(filename_buf);
					results_cleanup(results, algos_count);
					return RETURN_CHECK_MALFORMED;
				}
				results[algo_index].enabled = true;
				if ((hash_end - hash_sep) / 2 != xsum_algos[algo_index]->length) {
					fprintf(stderr, "%s: Invalid line format\n", filename_buf);
					free(filename_buf);
					results_cleanup(results, algos_count);
					return RETURN_CHECK_MALFORMED;
				}
				results[algo_index].hash = malloc(xsum_algos[algo_index]->length);
				if (results[algo_index].hash == NULL) {
					fprintf(stderr, "%s: Out of memory\n", filename_buf);
					free(filename_buf);
					results_cleanup(results, algos_count);
					return RETURN_FILE_ERROR;
				}
				for (int i = 0; i < xsum_algos[algo_index]->length; i ++) {
					int tmp1, tmp2;
					if (!parse_hex_char(buf[hash_sep + (i * 2) + 1], &tmp1) || !parse_hex_char(buf[hash_sep + (i * 2) + 2], &tmp2)) {
						fprintf(stderr, "%s: Invalid line format\n", filename_buf);
						free(filename_buf);
						results_cleanup(results, algos_count);
						return RETURN_CHECK_MALFORMED;
					}
					results[algo_index].hash[i] = (tmp1 * 16) + tmp2;
				}
			}
		}
	}
	
	bool found = false;
	for (int i = 0; i < algos_count; i++) {
		if (results[i].enabled) {
			found = true;
			break;
		}
	}
	if (!found && (found_unknown && !ignore_unknown)) {
		fprintf(stderr, "%s: No hashes found\n", filename_buf);
		free(filename_buf);
		results_cleanup(results, algos_count);
		return RETURN_CHECK_MALFORMED;
	}
	int ret;
	if (strcmp(filename_buf, "-") == 0) {
		ret = xsum_process(NULL, results, algos_count, ignore_missing);
	} else {
		ret = xsum_process(filename_buf, results, algos_count, ignore_missing);
	}
	results_cleanup(results, algos_count);
	if (ret == RETURN_OK) {
		if (!quiet) {
			printf("%s: OK\n", filename_buf);
		}
		if (found_unknown && !ignore_unknown) {
			ret = RETURN_CHECK_UNKNOWN;
		}
	} else if (ret == RETURN_CHECK_INVALID && !quiet) {
		printf("%s: FAILED\n", filename_buf);
	} else if (ret == -1) { // File not found with ignore_missing = true
		ret = RETURN_OK;
	}
	free(filename_buf);
	return ret;
	
}

int xsum_parse(char *filename, uint8_t *buf, uint64_t buflen, xsum_algo_result_t *results, int algos_count, bool ignore_unknown, bool ignore_missing, bool quiet) {
	
	uint64_t line_start = 0;
	uint64_t line_end = 0;
	int ret = 0;
	bool hash_found = false;
	while (line_end < buflen) {
		while (line_end < buflen && buf[line_end] != '\n' && buf[line_end] != '\r') {
			line_end++;
		}
		int ret2 = parse_line(filename, buf + line_start, line_end - line_start, results, algos_count, ignore_unknown, ignore_missing, quiet);
		if (ret2 != -1) {
			if (ret2 > ret) {
				ret = ret2;
			}
			hash_found = true;
		}
		line_end++;
		line_start = line_end;
	}
	if (!hash_found) {
		fprintf(stderr, "%s: No hashes found\n", filename);
		return RETURN_CHECK_MALFORMED;
	} else {
		return ret;
	}
	
}
