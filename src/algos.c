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

#include <stddef.h>
#include "algos.h"
#include "config.h"

xsum_algo_t *xsum_algos[] = {
#ifdef XSUM_HAS_ADLER_32
	&xsum_algo_adler_32,
#endif
#ifdef XSUM_HAS_BLAKE2S_128
	&xsum_algo_blake2s_128,
#endif
#ifdef XSUM_HAS_BLAKE2S_160
	&xsum_algo_blake2s_160,
#endif
#ifdef XSUM_HAS_BLAKE2S_224
	&xsum_algo_blake2s_224,
#endif
#ifdef XSUM_HAS_BLAKE2S_256
	&xsum_algo_blake2s_256,
#endif
#ifdef XSUM_HAS_BLAKE2B_128
	&xsum_algo_blake2b_128,
#endif
#ifdef XSUM_HAS_BLAKE2B_136
	&xsum_algo_blake2b_136,
#endif
#ifdef XSUM_HAS_BLAKE2B_144
	&xsum_algo_blake2b_144,
#endif
#ifdef XSUM_HAS_BLAKE2B_152
	&xsum_algo_blake2b_152,
#endif
#ifdef XSUM_HAS_BLAKE2B_160
	&xsum_algo_blake2b_160,
#endif
#ifdef XSUM_HAS_BLAKE2B_168
	&xsum_algo_blake2b_168,
#endif
#ifdef XSUM_HAS_BLAKE2B_176
	&xsum_algo_blake2b_176,
#endif
#ifdef XSUM_HAS_BLAKE2B_184
	&xsum_algo_blake2b_184,
#endif
#ifdef XSUM_HAS_BLAKE2B_192
	&xsum_algo_blake2b_192,
#endif
#ifdef XSUM_HAS_BLAKE2B_200
	&xsum_algo_blake2b_200,
#endif
#ifdef XSUM_HAS_BLAKE2B_208
	&xsum_algo_blake2b_208,
#endif
#ifdef XSUM_HAS_BLAKE2B_216
	&xsum_algo_blake2b_216,
#endif
#ifdef XSUM_HAS_BLAKE2B_224
	&xsum_algo_blake2b_224,
#endif
#ifdef XSUM_HAS_BLAKE2B_232
	&xsum_algo_blake2b_232,
#endif
#ifdef XSUM_HAS_BLAKE2B_240
	&xsum_algo_blake2b_240,
#endif
#ifdef XSUM_HAS_BLAKE2B_248
	&xsum_algo_blake2b_248,
#endif
#ifdef XSUM_HAS_BLAKE2B_256
	&xsum_algo_blake2b_256,
#endif
#ifdef XSUM_HAS_BLAKE2B_264
	&xsum_algo_blake2b_264,
#endif
#ifdef XSUM_HAS_BLAKE2B_272
	&xsum_algo_blake2b_272,
#endif
#ifdef XSUM_HAS_BLAKE2B_280
	&xsum_algo_blake2b_280,
#endif
#ifdef XSUM_HAS_BLAKE2B_288
	&xsum_algo_blake2b_288,
#endif
#ifdef XSUM_HAS_BLAKE2B_296
	&xsum_algo_blake2b_296,
#endif
#ifdef XSUM_HAS_BLAKE2B_304
	&xsum_algo_blake2b_304,
#endif
#ifdef XSUM_HAS_BLAKE2B_312
	&xsum_algo_blake2b_312,
#endif
#ifdef XSUM_HAS_BLAKE2B_320
	&xsum_algo_blake2b_320,
#endif
#ifdef XSUM_HAS_BLAKE2B_328
	&xsum_algo_blake2b_328,
#endif
#ifdef XSUM_HAS_BLAKE2B_336
	&xsum_algo_blake2b_336,
#endif
#ifdef XSUM_HAS_BLAKE2B_344
	&xsum_algo_blake2b_344,
#endif
#ifdef XSUM_HAS_BLAKE2B_352
	&xsum_algo_blake2b_352,
#endif
#ifdef XSUM_HAS_BLAKE2B_360
	&xsum_algo_blake2b_360,
#endif
#ifdef XSUM_HAS_BLAKE2B_368
	&xsum_algo_blake2b_368,
#endif
#ifdef XSUM_HAS_BLAKE2B_376
	&xsum_algo_blake2b_376,
#endif
#ifdef XSUM_HAS_BLAKE2B_384
	&xsum_algo_blake2b_384,
#endif
#ifdef XSUM_HAS_BLAKE2B_392
	&xsum_algo_blake2b_392,
#endif
#ifdef XSUM_HAS_BLAKE2B_400
	&xsum_algo_blake2b_400,
#endif
#ifdef XSUM_HAS_BLAKE2B_408
	&xsum_algo_blake2b_408,
#endif
#ifdef XSUM_HAS_BLAKE2B_416
	&xsum_algo_blake2b_416,
#endif
#ifdef XSUM_HAS_BLAKE2B_424
	&xsum_algo_blake2b_424,
#endif
#ifdef XSUM_HAS_BLAKE2B_432
	&xsum_algo_blake2b_432,
#endif
#ifdef XSUM_HAS_BLAKE2B_440
	&xsum_algo_blake2b_440,
#endif
#ifdef XSUM_HAS_BLAKE2B_448
	&xsum_algo_blake2b_448,
#endif
#ifdef XSUM_HAS_BLAKE2B_456
	&xsum_algo_blake2b_456,
#endif
#ifdef XSUM_HAS_BLAKE2B_464
	&xsum_algo_blake2b_464,
#endif
#ifdef XSUM_HAS_BLAKE2B_472
	&xsum_algo_blake2b_472,
#endif
#ifdef XSUM_HAS_BLAKE2B_480
	&xsum_algo_blake2b_480,
#endif
#ifdef XSUM_HAS_BLAKE2B_488
	&xsum_algo_blake2b_488,
#endif
#ifdef XSUM_HAS_BLAKE2B_496
	&xsum_algo_blake2b_496,
#endif
#ifdef XSUM_HAS_BLAKE2B_504
	&xsum_algo_blake2b_504,
#endif
#ifdef XSUM_HAS_BLAKE2B_512
	&xsum_algo_blake2b_512,
#endif
#ifdef XSUM_HAS_CRC32
	&xsum_algo_crc32,
#endif
#ifdef XSUM_HAS_CRC64
	&xsum_algo_crc64,
#endif
#ifdef XSUM_HAS_GOST94
	&xsum_algo_gost94,
#endif
#ifdef XSUM_HAS_GOST94_CRYPTOPRO
	&xsum_algo_gost94_cryptopro,
#endif
#ifdef XSUM_HAS_MD2
	&xsum_algo_md2,
#endif
#ifdef XSUM_HAS_MD4
	&xsum_algo_md4,
#endif
#ifdef XSUM_HAS_MD5
	&xsum_algo_md5,
#endif
#ifdef XSUM_HAS_RIPEMD160
	&xsum_algo_ripemd160,
#endif
#ifdef XSUM_HAS_SHA1
	&xsum_algo_sha1,
#endif
#ifdef XSUM_HAS_SHA224
	&xsum_algo_sha224,
#endif
#ifdef XSUM_HAS_SHA256
	&xsum_algo_sha256,
#endif
#ifdef XSUM_HAS_SHA384
	&xsum_algo_sha384,
#endif
#ifdef XSUM_HAS_SHA512
	&xsum_algo_sha512,
#endif
#ifdef XSUM_HAS_SHA512_224
	&xsum_algo_sha512_224,
#endif
#ifdef XSUM_HAS_SHA512_256
	&xsum_algo_sha512_256,
#endif
#ifdef XSUM_HAS_SHA3_224
	&xsum_algo_sha3_224,
#endif
#ifdef XSUM_HAS_SHA3_256
	&xsum_algo_sha3_256,
#endif
#ifdef XSUM_HAS_SHA3_384
	&xsum_algo_sha3_384,
#endif
#ifdef XSUM_HAS_SHA3_512
	&xsum_algo_sha3_512,
#endif
#ifdef XSUM_HAS_STREEBOG_256
	&xsum_algo_streebog_256,
#endif
#ifdef XSUM_HAS_STREEBOG_512
	&xsum_algo_streebog_512,
#endif
#ifdef XSUM_HAS_SUM
	&xsum_algo_sum,
#endif
#ifdef XSUM_HAS_TIGER
	&xsum_algo_tiger,
#endif
#ifdef XSUM_HAS_TIGER2
	&xsum_algo_tiger2,
#endif
#ifdef XSUM_HAS_WHIRLPOOL
	&xsum_algo_whirlpool,
#endif
#ifdef XSUM_HAS_XOR
	&xsum_algo_xor,
#endif
	NULL // End of array indicator
};
