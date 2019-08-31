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
#ifdef XSUM_HAS_GOST94

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#ifdef XSUM_WITH_NETTLE

#include <nettle/gosthash94.h>

void* xsum_gost94_init() {
	
	struct gosthash94_ctx *state = malloc(sizeof(struct gosthash94_ctx));
	if (state == NULL) {
		return NULL;
	}
	gosthash94_init(state);
	return state;
	
}

void xsum_gost94_update(void *state, uint8_t *buf, size_t len) {
	
	struct gosthash94_ctx *ctx = (struct gosthash94_ctx*) state;
	gosthash94_update(ctx, len, buf);
	
}

uint8_t* xsum_gost94_final(void *state) {
	
	struct gosthash94_ctx *ctx = (struct gosthash94_ctx*) state;
	uint8_t *out = malloc(32);
	if (out == NULL) {
		free(ctx);
		return NULL;
	}
	gosthash94_digest(ctx, 32, out);
	free(ctx);
	return out;
	
}

#endif

xsum_algo_t xsum_algo_gost94 = { "GOST94", 32, &xsum_gost94_init, &xsum_gost94_update, &xsum_gost94_final };

#endif
