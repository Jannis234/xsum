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

#include "config.h"
#ifdef XSUM_HAS_SUM

#include "algo_template.h"
#include "endian.h"

void* xsum_sum_init() {
	
	uint64_t *sum = malloc(8);
	if (sum == NULL) {
		return NULL;
	}
	*sum = 0;
	return sum;
	
}

void xsum_sum_update(void *state, uint8_t *buf, size_t len) {
	
	uint64_t *sum = (uint64_t*) state;
	while (len > 0) {
		*sum += *buf;
		buf++;
		len--;
	}
	
}

uint8_t* xsum_sum_final(void *state) {
	
	uint64_t *sum = (uint64_t*) state;
	*sum = xsum_endian64(*sum);
	return (uint8_t*) sum;
	
}

XSUM_TEMPLATE_ALGO(sum, "Sum", 8)

#endif
