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

#ifndef __XSUM_COMPRESS_H__
#define __XSUM_COMPRESS_H__

#include "config.h"

#ifdef XSUM_WITH_ZLIB_COMPRESS

#include <stdint.h>

uint8_t* xsum_decompress_file(char *filename, uint8_t *buf, uint64_t len, uint64_t *len_out);
void* xsum_compress_init();
void xsum_compress_end(void *state);
void xsum_compress_string(void *state, char *str);

#endif

#endif
