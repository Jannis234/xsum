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
#ifdef XSUM_HAS_RIPEMD160

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#ifdef XSUM_WITH_NETTLE

#include <nettle/ripemd160.h>

void* xsum_ripemd160_init() {
	
	struct ripemd160_ctx *state = malloc(sizeof(struct ripemd160_ctx));
	if (state == NULL) {
		return NULL;
	}
	ripemd160_init(state);
	return state;
	
}

void xsum_ripemd160_update(void *state, uint8_t *buf, size_t len) {
	
	struct ripemd160_ctx *ctx = (struct ripemd160_ctx*) state;
	ripemd160_update(ctx, len, buf);
	
}

uint8_t* xsum_ripemd160_final(void *state) {
	
	struct ripemd160_ctx *ctx = (struct ripemd160_ctx*) state;
	uint8_t *out = malloc(20);
	if (out == NULL) {
		free(ctx);
		return NULL;
	}
	ripemd160_digest(ctx, 20, out);
	free(ctx);
	return out;
	
}

#endif

xsum_algo_t xsum_algo_ripemd160 = { "RIPEMD160", 20, &xsum_ripemd160_init, &xsum_ripemd160_update, &xsum_ripemd160_final };

#endif
