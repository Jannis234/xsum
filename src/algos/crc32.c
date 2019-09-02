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
#ifdef XSUM_HAS_CRC32

#include "algo_template.h"
#include "byteswap.h"

#if defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(crc32, GCRY_MD_CRC32, 4)

#elif defined(XSUM_WITH_ZLIB)

#include <zlib.h>

void* xsum_crc32_init() {
	
	uint32_t *crc = malloc(4);
	if (crc == NULL) {
		return NULL;
	}
	*crc = crc32_z(0, NULL, 0);
	return crc;
	
}

void xsum_crc32_update(void *state, uint8_t *buf, size_t len) {
	
	uint32_t *crc = (uint32_t*) state;
	*crc = crc32_z(*crc, buf, len);
	
}

uint8_t* xsum_crc32_final(void *state) {
	
	uint32_t *crc = (uint32_t*) state;
	*crc = xsum_endian32(*crc);
	return (uint8_t*) crc;
	
}

#endif

XSUM_TEMPLATE_ALGO(crc32, "CRC32", 4)

#endif