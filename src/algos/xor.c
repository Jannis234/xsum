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
#ifdef XSUM_HAS_XOR

#include "algo_template.h"

void* xsum_xor_init() {
	
	uint8_t *b = malloc(1);
	if (b == NULL) {
		return NULL;
	}
	*b = 0;
	return b;
	
}

void xsum_xor_update(void *state, uint8_t *buf, size_t len) {
	
	uint8_t *b = (uint8_t*) state;
	while (len > 0) {
		*b ^= *buf;
		buf++;
		len--;
	}
	
}

uint8_t* xsum_xor_final(void *state) {
	
	return state;
	
}

XSUM_TEMPLATE_ALGO(xor, "XOR", 1)

#endif
