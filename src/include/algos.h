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

#ifdef XSUM_HAS_ADLER_32
extern xsum_algo_t xsum_algo_adler_32;
#endif
#ifdef XSUM_HAS_BLAKE2S_128
extern xsum_algo_t xsum_algo_blake2s_128;
#endif
#ifdef XSUM_HAS_BLAKE2S_160
extern xsum_algo_t xsum_algo_blake2s_160;
#endif
#ifdef XSUM_HAS_BLAKE2S_224
extern xsum_algo_t xsum_algo_blake2s_224;
#endif
#ifdef XSUM_HAS_BLAKE2S_256
extern xsum_algo_t xsum_algo_blake2s_256;
#endif
#ifdef XSUM_HAS_BLAKE2B_FULL
extern xsum_algo_t xsum_algo_blake2b_8;
extern xsum_algo_t xsum_algo_blake2b_16;
extern xsum_algo_t xsum_algo_blake2b_24;
extern xsum_algo_t xsum_algo_blake2b_32;
extern xsum_algo_t xsum_algo_blake2b_40;
extern xsum_algo_t xsum_algo_blake2b_48;
extern xsum_algo_t xsum_algo_blake2b_56;
extern xsum_algo_t xsum_algo_blake2b_64;
extern xsum_algo_t xsum_algo_blake2b_72;
extern xsum_algo_t xsum_algo_blake2b_80;
extern xsum_algo_t xsum_algo_blake2b_88;
extern xsum_algo_t xsum_algo_blake2b_96;
extern xsum_algo_t xsum_algo_blake2b_104;
extern xsum_algo_t xsum_algo_blake2b_112;
extern xsum_algo_t xsum_algo_blake2b_120;
extern xsum_algo_t xsum_algo_blake2b_128;
extern xsum_algo_t xsum_algo_blake2b_136;
extern xsum_algo_t xsum_algo_blake2b_144;
extern xsum_algo_t xsum_algo_blake2b_152;
extern xsum_algo_t xsum_algo_blake2b_168;
extern xsum_algo_t xsum_algo_blake2b_176;
extern xsum_algo_t xsum_algo_blake2b_184;
extern xsum_algo_t xsum_algo_blake2b_192;
extern xsum_algo_t xsum_algo_blake2b_200;
extern xsum_algo_t xsum_algo_blake2b_208;
extern xsum_algo_t xsum_algo_blake2b_216;
extern xsum_algo_t xsum_algo_blake2b_224;
extern xsum_algo_t xsum_algo_blake2b_232;
extern xsum_algo_t xsum_algo_blake2b_240;
extern xsum_algo_t xsum_algo_blake2b_248;
extern xsum_algo_t xsum_algo_blake2b_264;
extern xsum_algo_t xsum_algo_blake2b_272;
extern xsum_algo_t xsum_algo_blake2b_280;
extern xsum_algo_t xsum_algo_blake2b_288;
extern xsum_algo_t xsum_algo_blake2b_296;
extern xsum_algo_t xsum_algo_blake2b_304;
extern xsum_algo_t xsum_algo_blake2b_312;
extern xsum_algo_t xsum_algo_blake2b_320;
extern xsum_algo_t xsum_algo_blake2b_328;
extern xsum_algo_t xsum_algo_blake2b_336;
extern xsum_algo_t xsum_algo_blake2b_344;
extern xsum_algo_t xsum_algo_blake2b_352;
extern xsum_algo_t xsum_algo_blake2b_360;
extern xsum_algo_t xsum_algo_blake2b_368;
extern xsum_algo_t xsum_algo_blake2b_376;
extern xsum_algo_t xsum_algo_blake2b_392;
extern xsum_algo_t xsum_algo_blake2b_400;
extern xsum_algo_t xsum_algo_blake2b_408;
extern xsum_algo_t xsum_algo_blake2b_416;
extern xsum_algo_t xsum_algo_blake2b_424;
extern xsum_algo_t xsum_algo_blake2b_432;
extern xsum_algo_t xsum_algo_blake2b_440;
extern xsum_algo_t xsum_algo_blake2b_448;
extern xsum_algo_t xsum_algo_blake2b_456;
extern xsum_algo_t xsum_algo_blake2b_464;
extern xsum_algo_t xsum_algo_blake2b_472;
extern xsum_algo_t xsum_algo_blake2b_480;
extern xsum_algo_t xsum_algo_blake2b_488;
extern xsum_algo_t xsum_algo_blake2b_496;
extern xsum_algo_t xsum_algo_blake2b_504;
#endif
#ifdef XSUM_HAS_BLAKE2B_160
extern xsum_algo_t xsum_algo_blake2b_160;
#endif
#ifdef XSUM_HAS_BLAKE2B_256
extern xsum_algo_t xsum_algo_blake2b_256;
#endif
#ifdef XSUM_HAS_BLAKE2B_384
extern xsum_algo_t xsum_algo_blake2b_384;
#endif
#ifdef XSUM_HAS_BLAKE2B_512
extern xsum_algo_t xsum_algo_blake2b_512;
#endif
#ifdef XSUM_HAS_CRC32
extern xsum_algo_t xsum_algo_crc32;
#endif
#ifdef XSUM_HAS_CRC64
extern xsum_algo_t xsum_algo_crc64;
#endif
#ifdef XSUM_HAS_EDON_R_256
extern xsum_algo_t xsum_algo_edon_r_256;
#endif
#ifdef XSUM_HAS_EDON_R_512
extern xsum_algo_t xsum_algo_edon_r_512;
#endif
#ifdef XSUM_HAS_GOST94
extern xsum_algo_t xsum_algo_gost94;
#endif
#ifdef XSUM_HAS_GOST94_CRYPTOPRO
extern xsum_algo_t xsum_algo_gost94_cryptopro;
#endif
#ifdef XSUM_HAS_HAS160
extern xsum_algo_t xsum_algo_has160;
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
#ifdef XSUM_HAS_SNEFRU_128
extern xsum_algo_t xsum_algo_snefru_128;
#endif
#ifdef XSUM_HAS_SNEFRU_256
extern xsum_algo_t xsum_algo_snefru_256;
#endif
#ifdef XSUM_HAS_STREEBOG_256
extern xsum_algo_t xsum_algo_streebog_256;
#endif
#ifdef XSUM_HAS_STREEBOG_512
extern xsum_algo_t xsum_algo_streebog_512;
#endif
#ifdef XSUM_HAS_SUM
extern xsum_algo_t xsum_algo_sum;
#endif
#ifdef XSUM_HAS_TIGER
extern xsum_algo_t xsum_algo_tiger;
#endif
#ifdef XSUM_HAS_TIGER2
extern xsum_algo_t xsum_algo_tiger2;
#endif
#ifdef XSUM_HAS_WHIRLPOOL
extern xsum_algo_t xsum_algo_whirlpool;
#endif
#ifdef XSUM_HAS_XOR
extern xsum_algo_t xsum_algo_xor;
#endif

#endif
