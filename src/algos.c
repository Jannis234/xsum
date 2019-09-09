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
#ifdef XSUM_HAS_BLAKE2S_FULL
	&xsum_algo_blake2s_8,
	&xsum_algo_blake2s_16,
	&xsum_algo_blake2s_24,
	&xsum_algo_blake2s_32,
	&xsum_algo_blake2s_40,
	&xsum_algo_blake2s_48,
	&xsum_algo_blake2s_56,
	&xsum_algo_blake2s_64,
	&xsum_algo_blake2s_72,
	&xsum_algo_blake2s_80,
	&xsum_algo_blake2s_88,
	&xsum_algo_blake2s_96,
	&xsum_algo_blake2s_104,
	&xsum_algo_blake2s_112,
	&xsum_algo_blake2s_120,
#endif
#ifdef XSUM_HAS_BLAKE2S_128
	&xsum_algo_blake2s_128,
#endif
#ifdef XSUM_HAS_BLAKE2S_FULL
	&xsum_algo_blake2s_136,
	&xsum_algo_blake2s_144,
	&xsum_algo_blake2s_152,
#endif
#ifdef XSUM_HAS_BLAKE2S_160
	&xsum_algo_blake2s_160,
#endif
#ifdef XSUM_HAS_BLAKE2S_FULL
	&xsum_algo_blake2s_168,
	&xsum_algo_blake2s_176,
	&xsum_algo_blake2s_184,
	&xsum_algo_blake2s_192,
	&xsum_algo_blake2s_200,
	&xsum_algo_blake2s_208,
	&xsum_algo_blake2s_216,
#endif
#ifdef XSUM_HAS_BLAKE2S_224
	&xsum_algo_blake2s_224,
#endif
#ifdef XSUM_HAS_BLAKE2S_FULL
	&xsum_algo_blake2s_232,
	&xsum_algo_blake2s_240,
	&xsum_algo_blake2s_248,
#endif
#ifdef XSUM_HAS_BLAKE2S_256
	&xsum_algo_blake2s_256,
#endif
#ifdef XSUM_HAS_BLAKE2SP_FULL
	&xsum_algo_blake2sp_8,
	&xsum_algo_blake2sp_16,
	&xsum_algo_blake2sp_24,
	&xsum_algo_blake2sp_32,
	&xsum_algo_blake2sp_40,
	&xsum_algo_blake2sp_48,
	&xsum_algo_blake2sp_56,
	&xsum_algo_blake2sp_64,
	&xsum_algo_blake2sp_72,
	&xsum_algo_blake2sp_80,
	&xsum_algo_blake2sp_88,
	&xsum_algo_blake2sp_96,
	&xsum_algo_blake2sp_104,
	&xsum_algo_blake2sp_112,
	&xsum_algo_blake2sp_120,
	&xsum_algo_blake2sp_128,
	&xsum_algo_blake2sp_136,
	&xsum_algo_blake2sp_144,
	&xsum_algo_blake2sp_152,
	&xsum_algo_blake2sp_160,
	&xsum_algo_blake2sp_168,
	&xsum_algo_blake2sp_176,
	&xsum_algo_blake2sp_184,
	&xsum_algo_blake2sp_192,
	&xsum_algo_blake2sp_200,
	&xsum_algo_blake2sp_208,
	&xsum_algo_blake2sp_216,
	&xsum_algo_blake2sp_224,
	&xsum_algo_blake2sp_232,
	&xsum_algo_blake2sp_240,
	&xsum_algo_blake2sp_248,
	&xsum_algo_blake2sp_256,
#endif
#ifdef XSUM_HAS_BLAKE2B_FULL
	&xsum_algo_blake2b_8,
	&xsum_algo_blake2b_16,
	&xsum_algo_blake2b_24,
	&xsum_algo_blake2b_32,
	&xsum_algo_blake2b_40,
	&xsum_algo_blake2b_48,
	&xsum_algo_blake2b_56,
	&xsum_algo_blake2b_64,
	&xsum_algo_blake2b_72,
	&xsum_algo_blake2b_80,
	&xsum_algo_blake2b_88,
	&xsum_algo_blake2b_96,
	&xsum_algo_blake2b_104,
	&xsum_algo_blake2b_112,
	&xsum_algo_blake2b_120,
	&xsum_algo_blake2b_128,
	&xsum_algo_blake2b_136,
	&xsum_algo_blake2b_144,
	&xsum_algo_blake2b_152,
#endif
#ifdef XSUM_HAS_BLAKE2B_160
	&xsum_algo_blake2b_160,
#endif
#ifdef XSUM_HAS_BLAKE2B_FULL
	&xsum_algo_blake2b_168,
	&xsum_algo_blake2b_176,
	&xsum_algo_blake2b_184,
	&xsum_algo_blake2b_192,
	&xsum_algo_blake2b_200,
	&xsum_algo_blake2b_208,
	&xsum_algo_blake2b_216,
	&xsum_algo_blake2b_224,
	&xsum_algo_blake2b_232,
	&xsum_algo_blake2b_240,
	&xsum_algo_blake2b_248,
#endif
#ifdef XSUM_HAS_BLAKE2B_256
	&xsum_algo_blake2b_256,
#endif
#ifdef XSUM_HAS_BLAKE2B_FULL
	&xsum_algo_blake2b_264,
	&xsum_algo_blake2b_272,
	&xsum_algo_blake2b_280,
	&xsum_algo_blake2b_288,
	&xsum_algo_blake2b_296,
	&xsum_algo_blake2b_304,
	&xsum_algo_blake2b_312,
	&xsum_algo_blake2b_320,
	&xsum_algo_blake2b_328,
	&xsum_algo_blake2b_336,
	&xsum_algo_blake2b_344,
	&xsum_algo_blake2b_352,
	&xsum_algo_blake2b_360,
	&xsum_algo_blake2b_368,
	&xsum_algo_blake2b_376,
#endif
#ifdef XSUM_HAS_BLAKE2B_384
	&xsum_algo_blake2b_384,
#endif
#ifdef XSUM_HAS_BLAKE2B_FULL
	&xsum_algo_blake2b_392,
	&xsum_algo_blake2b_400,
	&xsum_algo_blake2b_408,
	&xsum_algo_blake2b_416,
	&xsum_algo_blake2b_424,
	&xsum_algo_blake2b_432,
	&xsum_algo_blake2b_440,
	&xsum_algo_blake2b_448,
	&xsum_algo_blake2b_456,
	&xsum_algo_blake2b_464,
	&xsum_algo_blake2b_472,
	&xsum_algo_blake2b_480,
	&xsum_algo_blake2b_488,
	&xsum_algo_blake2b_496,
	&xsum_algo_blake2b_504,
#endif
#ifdef XSUM_HAS_BLAKE2B_512
	&xsum_algo_blake2b_512,
#endif
#ifdef XSUM_HAS_BLAKE2BP_FULL
	&xsum_algo_blake2bp_8,
	&xsum_algo_blake2bp_16,
	&xsum_algo_blake2bp_24,
	&xsum_algo_blake2bp_32,
	&xsum_algo_blake2bp_40,
	&xsum_algo_blake2bp_48,
	&xsum_algo_blake2bp_56,
	&xsum_algo_blake2bp_64,
	&xsum_algo_blake2bp_72,
	&xsum_algo_blake2bp_80,
	&xsum_algo_blake2bp_88,
	&xsum_algo_blake2bp_96,
	&xsum_algo_blake2bp_104,
	&xsum_algo_blake2bp_112,
	&xsum_algo_blake2bp_120,
	&xsum_algo_blake2bp_128,
	&xsum_algo_blake2bp_136,
	&xsum_algo_blake2bp_144,
	&xsum_algo_blake2bp_152,
	&xsum_algo_blake2bp_160,
	&xsum_algo_blake2bp_168,
	&xsum_algo_blake2bp_176,
	&xsum_algo_blake2bp_184,
	&xsum_algo_blake2bp_192,
	&xsum_algo_blake2bp_200,
	&xsum_algo_blake2bp_208,
	&xsum_algo_blake2bp_216,
	&xsum_algo_blake2bp_224,
	&xsum_algo_blake2bp_232,
	&xsum_algo_blake2bp_240,
	&xsum_algo_blake2bp_248,
	&xsum_algo_blake2bp_256,
	&xsum_algo_blake2bp_264,
	&xsum_algo_blake2bp_272,
	&xsum_algo_blake2bp_280,
	&xsum_algo_blake2bp_288,
	&xsum_algo_blake2bp_296,
	&xsum_algo_blake2bp_304,
	&xsum_algo_blake2bp_312,
	&xsum_algo_blake2bp_320,
	&xsum_algo_blake2bp_328,
	&xsum_algo_blake2bp_336,
	&xsum_algo_blake2bp_344,
	&xsum_algo_blake2bp_352,
	&xsum_algo_blake2bp_360,
	&xsum_algo_blake2bp_368,
	&xsum_algo_blake2bp_376,
	&xsum_algo_blake2bp_384,
	&xsum_algo_blake2bp_392,
	&xsum_algo_blake2bp_400,
	&xsum_algo_blake2bp_408,
	&xsum_algo_blake2bp_416,
	&xsum_algo_blake2bp_424,
	&xsum_algo_blake2bp_432,
	&xsum_algo_blake2bp_440,
	&xsum_algo_blake2bp_448,
	&xsum_algo_blake2bp_456,
	&xsum_algo_blake2bp_464,
	&xsum_algo_blake2bp_472,
	&xsum_algo_blake2bp_480,
	&xsum_algo_blake2bp_488,
	&xsum_algo_blake2bp_496,
	&xsum_algo_blake2bp_504,
	&xsum_algo_blake2bp_512,
#endif
#ifdef XSUM_HAS_CRC32
	&xsum_algo_crc32,
#endif
#ifdef XSUM_HAS_CRC64
	&xsum_algo_crc64,
#endif
#ifdef XSUM_HAS_EDON_R_256
	&xsum_algo_edon_r_256,
#endif
#ifdef XSUM_HAS_EDON_R_512
	&xsum_algo_edon_r_512,
#endif
#ifdef XSUM_HAS_GOST94
	&xsum_algo_gost94,
#endif
#ifdef XSUM_HAS_GOST94_CRYPTOPRO
	&xsum_algo_gost94_cryptopro,
#endif
#ifdef XSUM_HAS_HAS160
	&xsum_algo_has160,
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
#ifdef XSUM_HAS_SNEFRU_128
	&xsum_algo_snefru_128,
#endif
#ifdef XSUM_HAS_SNEFRU_256
	&xsum_algo_snefru_256,
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
