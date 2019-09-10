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
#ifdef XSUM_HAS_ADLER_32

#include "algo_template.h"
#include "byteswap.h"

#ifdef XSUM_WITH_ZLIB

#include <zlib.h>

void* xsum_adler_32_init() {
	
	uint32_t *adler = malloc(4);
	if (adler == NULL) {
		return NULL;
	}
	*adler = adler32_z(0, NULL, 0);
	return adler;
	
}

void xsum_adler_32_update(void *state, uint8_t *buf, size_t len) {
	
	uint32_t *adler = (uint32_t*) state;
	*adler = adler32_z(*adler, buf, len);
	
}

uint8_t* xsum_adler_32_final(void *state) {
	
	uint32_t *adler = (uint32_t*) state;
	*adler = xsum_endian32(*adler);
	return (uint8_t*) adler;
	
}

#elif defined(XSUM_WITH_BOTAN_ADLER_32)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(adler_32, "Adler32", 4)

#endif

XSUM_TEMPLATE_ALGO(adler_32, "Adler-32", 4)

#endif
