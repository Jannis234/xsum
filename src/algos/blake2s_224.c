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
#ifdef XSUM_HAS_BLAKE2S_224

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#if defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>

void* xsum_blake2s_224_init() {
	
	gcry_md_hd_t *hd = malloc(sizeof(gcry_md_hd_t));
	if (hd == NULL) {
		return NULL;
	}
	gcry_md_open(hd, GCRY_MD_BLAKE2S_224, 0);
	if (*hd == NULL) {
		free(hd);
		return NULL;
	}
	return hd;
	
}

void xsum_blake2s_224_update(void *state, uint8_t *buf, size_t len) {
	
	gcry_md_hd_t *hd = (gcry_md_hd_t*) state;
	gcry_md_write(*hd, buf, len);
	
}

uint8_t* xsum_blake2s_224_final(void *state) {
	
	gcry_md_hd_t *hd = (gcry_md_hd_t*) state;
	unsigned char *out = gcry_md_read(*hd, 0);
	uint8_t *out2 = malloc(28);
	if (out2 == NULL) {
		free(hd);
		return NULL;
	}
	memcpy(out2, out, 28);
	free(hd);
	return out2;
	
}

#endif

xsum_algo_t xsum_algo_blake2s_224 = { "BLAKE2s-224", 28, &xsum_blake2s_224_init, &xsum_blake2s_224_update, &xsum_blake2s_224_final };

#endif
