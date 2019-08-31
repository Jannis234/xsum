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

#ifndef __XSUM_ALGOS_H__
#define __XSUM_ALGOS_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "config.h"

typedef void* (*xsum_func_init_t)(); // Initialize the inernal state, return a pointer to that state
typedef void (*xsum_func_update_t)(void* state, uint8_t* buf, size_t len); // Process len bytes from buf
typedef uint8_t* (*xsum_func_final_t)(void* state); // Finalize calculation, free memory, return the final hash (or NULL on error)

typedef struct {
	char *name; // Algorithm name (for CLI)
	int length; // Output length in bytes
	xsum_func_init_t func_init;
	xsum_func_update_t func_update;
	xsum_func_final_t func_final;
} xsum_algo_t;

extern xsum_algo_t *xsum_algos[];

#ifdef XSUM_HAS_GOST94
extern xsum_algo_t xsum_algo_gost94;
#endif
#ifdef XSUM_HAS_MD2
extern xsum_algo_t xsum_algo_md2;
#endif
#ifdef XSUM_HAS_MD4
extern xsum_algo_t xsum_algo_md4;
#endif
#ifdef XSUM_HAS_MD5
extern xsum_algo_t xsum_algo_md5;
#endif
#ifdef XSUM_HAS_RIPEMD160
extern xsum_algo_t xsum_algo_ripemd160;
#endif
#ifdef XSUM_HAS_SHA1
extern xsum_algo_t xsum_algo_sha1;
#endif
#ifdef XSUM_HAS_SHA224
extern xsum_algo_t xsum_algo_sha224;
#endif
#ifdef XSUM_HAS_SHA256
extern xsum_algo_t xsum_algo_sha256;
#endif
#ifdef XSUM_HAS_SHA384
extern xsum_algo_t xsum_algo_sha384;
#endif
#ifdef XSUM_HAS_SHA512
extern xsum_algo_t xsum_algo_sha512;
#endif
#ifdef XSUM_HAS_SHA512_224
extern xsum_algo_t xsum_algo_sha512_224;
#endif
#ifdef XSUM_HAS_SHA512_256
extern xsum_algo_t xsum_algo_sha512_256;
#endif
#ifdef XSUM_HAS_SHA3_224
extern xsum_algo_t xsum_algo_sha3_224;
#endif
#ifdef XSUM_HAS_SHA3_256
extern xsum_algo_t xsum_algo_sha3_256;
#endif
#ifdef XSUM_HAS_SHA3_384
extern xsum_algo_t xsum_algo_sha3_384;
#endif
#ifdef XSUM_HAS_SHA3_512
extern xsum_algo_t xsum_algo_sha3_512;
#endif

#endif
