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

#ifndef __XSUM_H__
#define __XSUM_H__

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	void *state;
	uint8_t *hash;
	bool enabled;
	bool check_ok;
} xsum_algo_result_t;

// Calculate hashes for a file (for all algos with results.enabled = true)
// Will store a pointer if results.hash == NULL or compare the hashes if results.hash != NULL
int xsum_process(char *filename, xsum_algo_result_t *results, int algos_count);
// Parse a file containing hashes and run xsum_process on every line
int xsum_parse(char *filename, uint8_t *buf, uint64_t buflen, xsum_algo_result_t *results, int algos_count, bool ignore_unknown);

#endif
