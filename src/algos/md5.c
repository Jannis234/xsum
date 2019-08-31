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
#ifdef XSUM_HAS_MD5

#include <stddef.h>
#include <stdlib.h>
#include "algos.h"

#ifdef XSUM_WITH_NETTLE

#include <nettle/md5.h>

void* xsum_md5_init() {
	
	struct md5_ctx *state = malloc(sizeof(struct md5_ctx));
	if (state == NULL) {
		return NULL;
	}
	md5_init(state);
	return state;
	
}

void xsum_md5_update(void *state, uint8_t *buf, size_t len) {
	
	struct md5_ctx *ctx = (struct md5_ctx*) state;
	md5_update(ctx, len, buf);
	
}

uint8_t* xsum_md5_final(void *state) {
	
	struct md5_ctx *ctx = (struct md5_ctx*) state;
	uint8_t *out = malloc(16);
	if (out == NULL) {
		free(ctx);
		return NULL;
	}
	md5_digest(ctx, 16, out);
	free(ctx);
	return out;
	
}

#endif

xsum_algo_t xsum_algo_md5 = { "MD5", 16, &xsum_md5_init, &xsum_md5_update, &xsum_md5_final };

#endif
