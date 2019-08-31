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
#ifdef XSUM_HAS_SHA384

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#ifdef XSUM_WITH_NETTLE

#include <nettle/sha2.h>

void* xsum_sha384_init() {
	
	struct sha384_ctx *state = malloc(sizeof(struct sha384_ctx));
	if (state == NULL) {
		return NULL;
	}
	sha384_init(state);
	return state;
	
}

void xsum_sha384_update(void *state, uint8_t *buf, size_t len) {
	
	struct sha384_ctx *ctx = (struct sha384_ctx*) state;
	sha384_update(ctx, len, buf);
	
}

uint8_t* xsum_sha384_final(void *state) {
	
	struct sha384_ctx *ctx = (struct sha384_ctx*) state;
	uint8_t *out = malloc(48);
	if (out == NULL) {
		free(ctx);
		return NULL;
	}
	sha384_digest(ctx, 48, out);
	free(ctx);
	return out;
	
}

#endif

xsum_algo_t xsum_algo_sha384 = { "SHA384", 48, &xsum_sha384_init, &xsum_sha384_update, &xsum_sha384_final };

#endif
