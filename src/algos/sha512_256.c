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
#ifdef XSUM_HAS_SHA512_256

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#ifdef XSUM_WITH_NETTLE

#include <nettle/sha2.h>

void* xsum_sha512_256_init() {
	
	struct sha512_256_ctx *state = malloc(sizeof(struct sha512_256_ctx));
	if (state == NULL) {
		return NULL;
	}
	sha512_256_init(state);
	return state;
	
}

void xsum_sha512_256_update(void *state, uint8_t *buf, size_t len) {
	
	struct sha512_256_ctx *ctx = (struct sha512_256_ctx*) state;
	sha512_256_update(ctx, len, buf);
	
}

uint8_t* xsum_sha512_256_final(void *state) {
	
	struct sha512_256_ctx *ctx = (struct sha512_256_ctx*) state;
	uint8_t *out = malloc(32);
	if (out == NULL) {
		free(ctx);
		return NULL;
	}
	sha512_256_digest(ctx, 32, out);
	free(ctx);
	return out;
	
}

#endif

xsum_algo_t xsum_algo_sha512_256 = { "SHA512-256", 32, &xsum_sha512_256_init, &xsum_sha512_256_update, &xsum_sha512_256_final };

#endif
