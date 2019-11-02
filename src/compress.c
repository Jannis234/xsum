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

#ifdef XSUM_WITH_ZLIB

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

uint8_t* xsum_decompress_file(char *filename, uint8_t *buf, uint64_t len, uint64_t *len_out) {
	
	z_stream strm;
	strm.zalloc = (alloc_func) Z_NULL;
	strm.zfree = (free_func) Z_NULL;
	strm.opaque = NULL;
	strm.next_in = buf;
	strm.avail_in = len;
	
	uint64_t res_len = len;
	uint8_t *res = malloc(res_len);
	if (res == NULL) {
		fprintf(stderr, "%s: Out of memory\n", filename);
		return NULL;
	}
	strm.next_out = res;
	strm.avail_out = res_len;
	
	if (inflateInit2(&strm, 15 + 16) != Z_OK) {
		fprintf(stderr, "%s: Out of memory\n", filename);
		free(res);
		return NULL;
	}
	
	int ret;
	do {
		ret = inflate(&strm, Z_FINISH);
		if (ret == Z_BUF_ERROR) {
			uint64_t res_pos = strm.next_out - res;
			res_len += len;
			uint8_t *res2 = realloc(res, res_len);
			if (res2 == NULL) {
				fprintf(stderr, "%s: Out of memory\n", filename);
				free(res);
				inflateEnd(&strm);
				return NULL;
			}
			res = res2;
			strm.next_out = res2 + res_pos;
			strm.avail_out += len;
		}
	} while (ret == Z_BUF_ERROR);
	*len_out = strm.total_out;
	inflateEnd(&strm);
	
	if (ret == Z_STREAM_END) {
		return res;
	} else if (ret == Z_DATA_ERROR) {
		fprintf(stderr, "%s: Invalid compressed data\n", filename);
		free(res);
		return NULL;
	} else {
		fprintf(stderr, "%s: Out of memory\n", filename);
		free(res);
		return NULL;
	}
	
}

#endif
