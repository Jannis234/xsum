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

#ifdef XSUM_WITH_ZLIB_COMPRESS

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <zlib.h>

#define OUTBUFSIZE 1024

typedef struct {
	z_stream strm;
	gz_header gzhead;
	uint8_t outbuf[OUTBUFSIZE];
} xsum_compress_state_t;

char *gzip_comment = "xsum "XSUM_VERSION_STRING;

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
	
	if (inflateInit2(&strm, 15 + 16) != Z_OK) { // windowBits + 16 for gzip instead of raw deflate
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

void* xsum_compress_init() {
	
	xsum_compress_state_t *state = malloc(sizeof(xsum_compress_state_t));
	if (state == NULL) {
		return NULL;
	}
	state->strm.zalloc = (alloc_func) Z_NULL;
	state->strm.zfree = (free_func) Z_NULL;
	state->strm.opaque = NULL;
	if (deflateInit2(&state->strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 15 + 16, 8, Z_DEFAULT_STRATEGY) != Z_OK) { // windowBits + 16 for gzip instead of raw deflate
		free(state);
		return NULL;
	}
	state->strm.next_out = state->outbuf;
	state->strm.avail_out = OUTBUFSIZE;
	
	state->gzhead.text = true;
	state->gzhead.time = time(NULL);
	state->gzhead.os = 0xFF; // "Unknown"
	state->gzhead.extra = Z_NULL;
	state->gzhead.name = Z_NULL;
	state->gzhead.comment = (Bytef*) gzip_comment;
	state->gzhead.hcrc = false;
	deflateSetHeader(&state->strm, &state->gzhead);
	
	return state;
	
}

void xsum_compress_end(void *state) {
	
	xsum_compress_state_t *s = (xsum_compress_state_t*) state;
	s->strm.avail_in = 0;
	
	int ret;
	do {
		ret = deflate(&s->strm, Z_FINISH);
		if (s->strm.avail_out != OUTBUFSIZE) {
			fwrite(s->outbuf, 1, OUTBUFSIZE - s->strm.avail_out, stdout);
			s->strm.next_out = s->outbuf;
			s->strm.avail_out = OUTBUFSIZE;
		}
	} while (ret != Z_STREAM_END);
	
	deflateEnd(&s->strm);
	free(s);
	
}

void xsum_compress_string(void *state, char *str) {
	
	xsum_compress_state_t *s = (xsum_compress_state_t*) state;
	size_t len = strlen(str);
	str[len] = '\n'; // Re-use the NULL terminator for a newline
	
	s->strm.next_in = (uint8_t*) str;
	s->strm.avail_in = len + 1;
	int ret;
	do {
		ret = deflate(&s->strm, Z_NO_FLUSH);
		if (s->strm.avail_out == 0) {
			fwrite(s->outbuf, 1, OUTBUFSIZE, stdout);
			s->strm.next_out = s->outbuf;
			s->strm.avail_out = OUTBUFSIZE;
		}
	} while (ret == Z_OK);
	
}

#endif
