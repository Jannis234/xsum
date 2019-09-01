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
#ifdef XSUM_HAS_MD2

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/md2.h>

void* xsum_md2_init() {
	
	struct md2_ctx *state = malloc(sizeof(struct md2_ctx));
	if (state == NULL) {
		return NULL;
	}
	md2_init(state);
	return state;
	
}

void xsum_md2_update(void *state, uint8_t *buf, size_t len) {
	
	struct md2_ctx *ctx = (struct md2_ctx*) state;
	md2_update(ctx, len, buf);
	
}

uint8_t* xsum_md2_final(void *state) {
	
	struct md2_ctx *ctx = (struct md2_ctx*) state;
	uint8_t *out = malloc(16);
	if (out == NULL) {
		free(ctx);
		return NULL;
	}
	md2_digest(ctx, 16, out);
	free(ctx);
	return out;
	
}

#endif

xsum_algo_t xsum_algo_md2 = { "MD2", 16, &xsum_md2_init, &xsum_md2_update, &xsum_md2_final };

#endif
