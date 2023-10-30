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

#ifdef XSUM_HAS_ADLER_32
extern xsum_algo_t xsum_algo_adler_32;
#endif
#ifdef XSUM_HAS_BLAKE_224
extern xsum_algo_t xsum_algo_blake_224;
#endif
#ifdef XSUM_HAS_BLAKE_256
extern xsum_algo_t xsum_algo_blake_256;
#endif
#ifdef XSUM_HAS_BLAKE_384
extern xsum_algo_t xsum_algo_blake_384;
#endif
#ifdef XSUM_HAS_BLAKE_512
extern xsum_algo_t xsum_algo_blake_512;
#endif
#ifdef XSUM_HAS_BLAKE2S_FULL
extern xsum_algo_t xsum_algo_blake2s_8;
extern xsum_algo_t xsum_algo_blake2s_16;
extern xsum_algo_t xsum_algo_blake2s_24;
extern xsum_algo_t xsum_algo_blake2s_32;
extern xsum_algo_t xsum_algo_blake2s_40;
extern xsum_algo_t xsum_algo_blake2s_48;
extern xsum_algo_t xsum_algo_blake2s_56;
extern xsum_algo_t xsum_algo_blake2s_64;
extern xsum_algo_t xsum_algo_blake2s_72;
extern xsum_algo_t xsum_algo_blake2s_80;
extern xsum_algo_t xsum_algo_blake2s_88;
extern xsum_algo_t xsum_algo_blake2s_96;
extern xsum_algo_t xsum_algo_blake2s_104;
extern xsum_algo_t xsum_algo_blake2s_112;
extern xsum_algo_t xsum_algo_blake2s_120;
extern xsum_algo_t xsum_algo_blake2s_136;
extern xsum_algo_t xsum_algo_blake2s_144;
extern xsum_algo_t xsum_algo_blake2s_152;
extern xsum_algo_t xsum_algo_blake2s_168;
extern xsum_algo_t xsum_algo_blake2s_176;
extern xsum_algo_t xsum_algo_blake2s_184;
extern xsum_algo_t xsum_algo_blake2s_192;
extern xsum_algo_t xsum_algo_blake2s_200;
extern xsum_algo_t xsum_algo_blake2s_208;
extern xsum_algo_t xsum_algo_blake2s_216;
extern xsum_algo_t xsum_algo_blake2s_232;
extern xsum_algo_t xsum_algo_blake2s_240;
extern xsum_algo_t xsum_algo_blake2s_248;
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
#ifdef XSUM_HAS_BLAKE2SP_FULL
extern xsum_algo_t xsum_algo_blake2sp_8;
extern xsum_algo_t xsum_algo_blake2sp_16;
extern xsum_algo_t xsum_algo_blake2sp_24;
extern xsum_algo_t xsum_algo_blake2sp_32;
extern xsum_algo_t xsum_algo_blake2sp_40;
extern xsum_algo_t xsum_algo_blake2sp_48;
extern xsum_algo_t xsum_algo_blake2sp_56;
extern xsum_algo_t xsum_algo_blake2sp_64;
extern xsum_algo_t xsum_algo_blake2sp_72;
extern xsum_algo_t xsum_algo_blake2sp_80;
extern xsum_algo_t xsum_algo_blake2sp_88;
extern xsum_algo_t xsum_algo_blake2sp_96;
extern xsum_algo_t xsum_algo_blake2sp_104;
extern xsum_algo_t xsum_algo_blake2sp_112;
extern xsum_algo_t xsum_algo_blake2sp_120;
extern xsum_algo_t xsum_algo_blake2sp_128;
extern xsum_algo_t xsum_algo_blake2sp_136;
extern xsum_algo_t xsum_algo_blake2sp_144;
extern xsum_algo_t xsum_algo_blake2sp_152;
extern xsum_algo_t xsum_algo_blake2sp_160;
extern xsum_algo_t xsum_algo_blake2sp_168;
extern xsum_algo_t xsum_algo_blake2sp_176;
extern xsum_algo_t xsum_algo_blake2sp_184;
extern xsum_algo_t xsum_algo_blake2sp_192;
extern xsum_algo_t xsum_algo_blake2sp_200;
extern xsum_algo_t xsum_algo_blake2sp_208;
extern xsum_algo_t xsum_algo_blake2sp_216;
extern xsum_algo_t xsum_algo_blake2sp_224;
extern xsum_algo_t xsum_algo_blake2sp_232;
extern xsum_algo_t xsum_algo_blake2sp_240;
extern xsum_algo_t xsum_algo_blake2sp_248;
extern xsum_algo_t xsum_algo_blake2sp_256;
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
#ifdef XSUM_HAS_BLAKE2BP_FULL
extern xsum_algo_t xsum_algo_blake2bp_8;
extern xsum_algo_t xsum_algo_blake2bp_16;
extern xsum_algo_t xsum_algo_blake2bp_24;
extern xsum_algo_t xsum_algo_blake2bp_32;
extern xsum_algo_t xsum_algo_blake2bp_40;
extern xsum_algo_t xsum_algo_blake2bp_48;
extern xsum_algo_t xsum_algo_blake2bp_56;
extern xsum_algo_t xsum_algo_blake2bp_64;
extern xsum_algo_t xsum_algo_blake2bp_72;
extern xsum_algo_t xsum_algo_blake2bp_80;
extern xsum_algo_t xsum_algo_blake2bp_88;
extern xsum_algo_t xsum_algo_blake2bp_96;
extern xsum_algo_t xsum_algo_blake2bp_104;
extern xsum_algo_t xsum_algo_blake2bp_112;
extern xsum_algo_t xsum_algo_blake2bp_120;
extern xsum_algo_t xsum_algo_blake2bp_128;
extern xsum_algo_t xsum_algo_blake2bp_136;
extern xsum_algo_t xsum_algo_blake2bp_144;
extern xsum_algo_t xsum_algo_blake2bp_152;
extern xsum_algo_t xsum_algo_blake2bp_160;
extern xsum_algo_t xsum_algo_blake2bp_168;
extern xsum_algo_t xsum_algo_blake2bp_176;
extern xsum_algo_t xsum_algo_blake2bp_184;
extern xsum_algo_t xsum_algo_blake2bp_192;
extern xsum_algo_t xsum_algo_blake2bp_200;
extern xsum_algo_t xsum_algo_blake2bp_208;
extern xsum_algo_t xsum_algo_blake2bp_216;
extern xsum_algo_t xsum_algo_blake2bp_224;
extern xsum_algo_t xsum_algo_blake2bp_232;
extern xsum_algo_t xsum_algo_blake2bp_240;
extern xsum_algo_t xsum_algo_blake2bp_248;
extern xsum_algo_t xsum_algo_blake2bp_256;
extern xsum_algo_t xsum_algo_blake2bp_264;
extern xsum_algo_t xsum_algo_blake2bp_272;
extern xsum_algo_t xsum_algo_blake2bp_280;
extern xsum_algo_t xsum_algo_blake2bp_288;
extern xsum_algo_t xsum_algo_blake2bp_296;
extern xsum_algo_t xsum_algo_blake2bp_304;
extern xsum_algo_t xsum_algo_blake2bp_312;
extern xsum_algo_t xsum_algo_blake2bp_320;
extern xsum_algo_t xsum_algo_blake2bp_328;
extern xsum_algo_t xsum_algo_blake2bp_336;
extern xsum_algo_t xsum_algo_blake2bp_344;
extern xsum_algo_t xsum_algo_blake2bp_352;
extern xsum_algo_t xsum_algo_blake2bp_360;
extern xsum_algo_t xsum_algo_blake2bp_368;
extern xsum_algo_t xsum_algo_blake2bp_376;
extern xsum_algo_t xsum_algo_blake2bp_384;
extern xsum_algo_t xsum_algo_blake2bp_392;
extern xsum_algo_t xsum_algo_blake2bp_400;
extern xsum_algo_t xsum_algo_blake2bp_408;
extern xsum_algo_t xsum_algo_blake2bp_416;
extern xsum_algo_t xsum_algo_blake2bp_424;
extern xsum_algo_t xsum_algo_blake2bp_432;
extern xsum_algo_t xsum_algo_blake2bp_440;
extern xsum_algo_t xsum_algo_blake2bp_448;
extern xsum_algo_t xsum_algo_blake2bp_456;
extern xsum_algo_t xsum_algo_blake2bp_464;
extern xsum_algo_t xsum_algo_blake2bp_472;
extern xsum_algo_t xsum_algo_blake2bp_480;
extern xsum_algo_t xsum_algo_blake2bp_488;
extern xsum_algo_t xsum_algo_blake2bp_496;
extern xsum_algo_t xsum_algo_blake2bp_504;
extern xsum_algo_t xsum_algo_blake2bp_512;
#endif
#ifdef XSUM_HAS_CRC24
extern xsum_algo_t xsum_algo_crc24;
#endif
#ifdef XSUM_HAS_CRC32
extern xsum_algo_t xsum_algo_crc32;
#endif
#ifdef XSUM_HAS_CRC64
extern xsum_algo_t xsum_algo_crc64;
#endif
#ifdef XSUM_HAS_ECHO_FULL
extern xsum_algo_t xsum_algo_echo_8;
extern xsum_algo_t xsum_algo_echo_16;
extern xsum_algo_t xsum_algo_echo_24;
extern xsum_algo_t xsum_algo_echo_32;
extern xsum_algo_t xsum_algo_echo_40;
extern xsum_algo_t xsum_algo_echo_48;
extern xsum_algo_t xsum_algo_echo_56;
extern xsum_algo_t xsum_algo_echo_64;
extern xsum_algo_t xsum_algo_echo_72;
extern xsum_algo_t xsum_algo_echo_80;
extern xsum_algo_t xsum_algo_echo_88;
extern xsum_algo_t xsum_algo_echo_96;
extern xsum_algo_t xsum_algo_echo_104;
extern xsum_algo_t xsum_algo_echo_112;
extern xsum_algo_t xsum_algo_echo_120;
extern xsum_algo_t xsum_algo_echo_128;
extern xsum_algo_t xsum_algo_echo_136;
extern xsum_algo_t xsum_algo_echo_144;
extern xsum_algo_t xsum_algo_echo_152;
extern xsum_algo_t xsum_algo_echo_160;
extern xsum_algo_t xsum_algo_echo_168;
extern xsum_algo_t xsum_algo_echo_176;
extern xsum_algo_t xsum_algo_echo_184;
extern xsum_algo_t xsum_algo_echo_192;
extern xsum_algo_t xsum_algo_echo_200;
extern xsum_algo_t xsum_algo_echo_208;
extern xsum_algo_t xsum_algo_echo_216;
extern xsum_algo_t xsum_algo_echo_224;
extern xsum_algo_t xsum_algo_echo_232;
extern xsum_algo_t xsum_algo_echo_240;
extern xsum_algo_t xsum_algo_echo_248;
extern xsum_algo_t xsum_algo_echo_256;
extern xsum_algo_t xsum_algo_echo_264;
extern xsum_algo_t xsum_algo_echo_272;
extern xsum_algo_t xsum_algo_echo_280;
extern xsum_algo_t xsum_algo_echo_288;
extern xsum_algo_t xsum_algo_echo_296;
extern xsum_algo_t xsum_algo_echo_304;
extern xsum_algo_t xsum_algo_echo_312;
extern xsum_algo_t xsum_algo_echo_320;
extern xsum_algo_t xsum_algo_echo_328;
extern xsum_algo_t xsum_algo_echo_336;
extern xsum_algo_t xsum_algo_echo_344;
extern xsum_algo_t xsum_algo_echo_352;
extern xsum_algo_t xsum_algo_echo_360;
extern xsum_algo_t xsum_algo_echo_368;
extern xsum_algo_t xsum_algo_echo_376;
extern xsum_algo_t xsum_algo_echo_384;
extern xsum_algo_t xsum_algo_echo_392;
extern xsum_algo_t xsum_algo_echo_400;
extern xsum_algo_t xsum_algo_echo_408;
extern xsum_algo_t xsum_algo_echo_416;
extern xsum_algo_t xsum_algo_echo_424;
extern xsum_algo_t xsum_algo_echo_432;
extern xsum_algo_t xsum_algo_echo_440;
extern xsum_algo_t xsum_algo_echo_448;
extern xsum_algo_t xsum_algo_echo_456;
extern xsum_algo_t xsum_algo_echo_464;
extern xsum_algo_t xsum_algo_echo_472;
extern xsum_algo_t xsum_algo_echo_480;
extern xsum_algo_t xsum_algo_echo_488;
extern xsum_algo_t xsum_algo_echo_496;
extern xsum_algo_t xsum_algo_echo_504;
extern xsum_algo_t xsum_algo_echo_512;
#endif
#ifdef XSUM_HAS_EDON_R_256
extern xsum_algo_t xsum_algo_edon_r_256;
#endif
#ifdef XSUM_HAS_EDON_R_512
extern xsum_algo_t xsum_algo_edon_r_512;
#endif
#ifdef XSUM_HAS_ESCH_256
extern xsum_algo_t xsum_algo_esch_256;
#endif
#ifdef XSUM_HAS_ESCH_384
extern xsum_algo_t xsum_algo_esch_384;
#endif
#ifdef XSUM_HAS_GOST94
extern xsum_algo_t xsum_algo_gost94;
#endif
#ifdef XSUM_HAS_GOST94_CRYPTOPRO
extern xsum_algo_t xsum_algo_gost94_cryptopro;
#endif
#ifdef XSUM_HAS_GROESTL_FULL
extern xsum_algo_t xsum_algo_groestl_8;
extern xsum_algo_t xsum_algo_groestl_16;
extern xsum_algo_t xsum_algo_groestl_24;
extern xsum_algo_t xsum_algo_groestl_32;
extern xsum_algo_t xsum_algo_groestl_40;
extern xsum_algo_t xsum_algo_groestl_48;
extern xsum_algo_t xsum_algo_groestl_56;
extern xsum_algo_t xsum_algo_groestl_64;
extern xsum_algo_t xsum_algo_groestl_72;
extern xsum_algo_t xsum_algo_groestl_80;
extern xsum_algo_t xsum_algo_groestl_88;
extern xsum_algo_t xsum_algo_groestl_96;
extern xsum_algo_t xsum_algo_groestl_104;
extern xsum_algo_t xsum_algo_groestl_112;
extern xsum_algo_t xsum_algo_groestl_120;
extern xsum_algo_t xsum_algo_groestl_128;
extern xsum_algo_t xsum_algo_groestl_136;
extern xsum_algo_t xsum_algo_groestl_144;
extern xsum_algo_t xsum_algo_groestl_152;
extern xsum_algo_t xsum_algo_groestl_160;
extern xsum_algo_t xsum_algo_groestl_168;
extern xsum_algo_t xsum_algo_groestl_176;
extern xsum_algo_t xsum_algo_groestl_184;
extern xsum_algo_t xsum_algo_groestl_192;
extern xsum_algo_t xsum_algo_groestl_200;
extern xsum_algo_t xsum_algo_groestl_208;
extern xsum_algo_t xsum_algo_groestl_216;
extern xsum_algo_t xsum_algo_groestl_224;
extern xsum_algo_t xsum_algo_groestl_232;
extern xsum_algo_t xsum_algo_groestl_240;
extern xsum_algo_t xsum_algo_groestl_248;
extern xsum_algo_t xsum_algo_groestl_256;
extern xsum_algo_t xsum_algo_groestl_264;
extern xsum_algo_t xsum_algo_groestl_272;
extern xsum_algo_t xsum_algo_groestl_280;
extern xsum_algo_t xsum_algo_groestl_288;
extern xsum_algo_t xsum_algo_groestl_296;
extern xsum_algo_t xsum_algo_groestl_304;
extern xsum_algo_t xsum_algo_groestl_312;
extern xsum_algo_t xsum_algo_groestl_320;
extern xsum_algo_t xsum_algo_groestl_328;
extern xsum_algo_t xsum_algo_groestl_336;
extern xsum_algo_t xsum_algo_groestl_344;
extern xsum_algo_t xsum_algo_groestl_352;
extern xsum_algo_t xsum_algo_groestl_360;
extern xsum_algo_t xsum_algo_groestl_368;
extern xsum_algo_t xsum_algo_groestl_376;
extern xsum_algo_t xsum_algo_groestl_384;
extern xsum_algo_t xsum_algo_groestl_392;
extern xsum_algo_t xsum_algo_groestl_400;
extern xsum_algo_t xsum_algo_groestl_408;
extern xsum_algo_t xsum_algo_groestl_416;
extern xsum_algo_t xsum_algo_groestl_424;
extern xsum_algo_t xsum_algo_groestl_432;
extern xsum_algo_t xsum_algo_groestl_440;
extern xsum_algo_t xsum_algo_groestl_448;
extern xsum_algo_t xsum_algo_groestl_456;
extern xsum_algo_t xsum_algo_groestl_464;
extern xsum_algo_t xsum_algo_groestl_472;
extern xsum_algo_t xsum_algo_groestl_480;
extern xsum_algo_t xsum_algo_groestl_488;
extern xsum_algo_t xsum_algo_groestl_496;
extern xsum_algo_t xsum_algo_groestl_504;
extern xsum_algo_t xsum_algo_groestl_512;
#endif
#ifdef XSUM_HAS_HAS160
extern xsum_algo_t xsum_algo_has160;
#endif
#ifdef XSUM_HAS_HAVAL_128
extern xsum_algo_t xsum_algo_haval_128;
#endif
#ifdef XSUM_HAS_HAVAL_160
extern xsum_algo_t xsum_algo_haval_160;
#endif
#ifdef XSUM_HAS_HAVAL_192
extern xsum_algo_t xsum_algo_haval_192;
#endif
#ifdef XSUM_HAS_HAVAL_224
extern xsum_algo_t xsum_algo_haval_224;
#endif
#ifdef XSUM_HAS_HAVAL_256
extern xsum_algo_t xsum_algo_haval_256;
#endif
#ifdef XSUM_HAS_JH_224
extern xsum_algo_t xsum_algo_jh_224;
#endif
#ifdef XSUM_HAS_JH_256
extern xsum_algo_t xsum_algo_jh_256;
#endif
#ifdef XSUM_HAS_JH_384
extern xsum_algo_t xsum_algo_jh_384;
#endif
#ifdef XSUM_HAS_JH_512
extern xsum_algo_t xsum_algo_jh_512;
#endif
#ifdef XSUM_HAS_KECCAK_224
extern xsum_algo_t xsum_algo_keccak_224;
#endif
#ifdef XSUM_HAS_KECCAK_256
extern xsum_algo_t xsum_algo_keccak_256;
#endif
#ifdef XSUM_HAS_KECCAK_384
extern xsum_algo_t xsum_algo_keccak_384;
#endif
#ifdef XSUM_HAS_KECCAK_512
extern xsum_algo_t xsum_algo_keccak_512;
#endif
#ifdef XSUM_HAS_KUPYNA_256
extern xsum_algo_t xsum_algo_kupyna_256;
#endif
#ifdef XSUM_HAS_KUPYNA_512
extern xsum_algo_t xsum_algo_kupyna_512;
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
#ifdef XSUM_HAS_MDC2
extern xsum_algo_t xsum_algo_mdc2;
#endif
#ifdef XSUM_HAS_RIPEMD128
extern xsum_algo_t xsum_algo_ripemd128;
#endif
#ifdef XSUM_HAS_RIPEMD160
extern xsum_algo_t xsum_algo_ripemd160;
#endif
#ifdef XSUM_HAS_RIPEMD256
extern xsum_algo_t xsum_algo_ripemd256;
#endif
#ifdef XSUM_HAS_RIPEMD320
extern xsum_algo_t xsum_algo_ripemd320;
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
#ifdef XSUM_HAS_SKEIN_256
extern xsum_algo_t xsum_algo_skein_256_8;
extern xsum_algo_t xsum_algo_skein_256_16;
extern xsum_algo_t xsum_algo_skein_256_24;
extern xsum_algo_t xsum_algo_skein_256_32;
extern xsum_algo_t xsum_algo_skein_256_40;
extern xsum_algo_t xsum_algo_skein_256_48;
extern xsum_algo_t xsum_algo_skein_256_56;
extern xsum_algo_t xsum_algo_skein_256_64;
extern xsum_algo_t xsum_algo_skein_256_72;
extern xsum_algo_t xsum_algo_skein_256_80;
extern xsum_algo_t xsum_algo_skein_256_88;
extern xsum_algo_t xsum_algo_skein_256_96;
extern xsum_algo_t xsum_algo_skein_256_104;
extern xsum_algo_t xsum_algo_skein_256_112;
extern xsum_algo_t xsum_algo_skein_256_120;
extern xsum_algo_t xsum_algo_skein_256_128;
extern xsum_algo_t xsum_algo_skein_256_136;
extern xsum_algo_t xsum_algo_skein_256_144;
extern xsum_algo_t xsum_algo_skein_256_152;
extern xsum_algo_t xsum_algo_skein_256_160;
extern xsum_algo_t xsum_algo_skein_256_168;
extern xsum_algo_t xsum_algo_skein_256_176;
extern xsum_algo_t xsum_algo_skein_256_184;
extern xsum_algo_t xsum_algo_skein_256_192;
extern xsum_algo_t xsum_algo_skein_256_200;
extern xsum_algo_t xsum_algo_skein_256_208;
extern xsum_algo_t xsum_algo_skein_256_216;
extern xsum_algo_t xsum_algo_skein_256_224;
extern xsum_algo_t xsum_algo_skein_256_232;
extern xsum_algo_t xsum_algo_skein_256_240;
extern xsum_algo_t xsum_algo_skein_256_248;
extern xsum_algo_t xsum_algo_skein_256_256;
#endif
#ifdef XSUM_HAS_SKEIN_512
extern xsum_algo_t xsum_algo_skein_512_8;
extern xsum_algo_t xsum_algo_skein_512_16;
extern xsum_algo_t xsum_algo_skein_512_24;
extern xsum_algo_t xsum_algo_skein_512_32;
extern xsum_algo_t xsum_algo_skein_512_40;
extern xsum_algo_t xsum_algo_skein_512_48;
extern xsum_algo_t xsum_algo_skein_512_56;
extern xsum_algo_t xsum_algo_skein_512_64;
extern xsum_algo_t xsum_algo_skein_512_72;
extern xsum_algo_t xsum_algo_skein_512_80;
extern xsum_algo_t xsum_algo_skein_512_88;
extern xsum_algo_t xsum_algo_skein_512_96;
extern xsum_algo_t xsum_algo_skein_512_104;
extern xsum_algo_t xsum_algo_skein_512_112;
extern xsum_algo_t xsum_algo_skein_512_120;
extern xsum_algo_t xsum_algo_skein_512_128;
extern xsum_algo_t xsum_algo_skein_512_136;
extern xsum_algo_t xsum_algo_skein_512_144;
extern xsum_algo_t xsum_algo_skein_512_152;
extern xsum_algo_t xsum_algo_skein_512_160;
extern xsum_algo_t xsum_algo_skein_512_168;
extern xsum_algo_t xsum_algo_skein_512_176;
extern xsum_algo_t xsum_algo_skein_512_184;
extern xsum_algo_t xsum_algo_skein_512_192;
extern xsum_algo_t xsum_algo_skein_512_200;
extern xsum_algo_t xsum_algo_skein_512_208;
extern xsum_algo_t xsum_algo_skein_512_216;
extern xsum_algo_t xsum_algo_skein_512_224;
extern xsum_algo_t xsum_algo_skein_512_232;
extern xsum_algo_t xsum_algo_skein_512_240;
extern xsum_algo_t xsum_algo_skein_512_248;
extern xsum_algo_t xsum_algo_skein_512_256;
extern xsum_algo_t xsum_algo_skein_512_264;
extern xsum_algo_t xsum_algo_skein_512_272;
extern xsum_algo_t xsum_algo_skein_512_280;
extern xsum_algo_t xsum_algo_skein_512_288;
extern xsum_algo_t xsum_algo_skein_512_296;
extern xsum_algo_t xsum_algo_skein_512_304;
extern xsum_algo_t xsum_algo_skein_512_312;
extern xsum_algo_t xsum_algo_skein_512_320;
extern xsum_algo_t xsum_algo_skein_512_328;
extern xsum_algo_t xsum_algo_skein_512_336;
extern xsum_algo_t xsum_algo_skein_512_344;
extern xsum_algo_t xsum_algo_skein_512_352;
extern xsum_algo_t xsum_algo_skein_512_360;
extern xsum_algo_t xsum_algo_skein_512_368;
extern xsum_algo_t xsum_algo_skein_512_376;
extern xsum_algo_t xsum_algo_skein_512_384;
extern xsum_algo_t xsum_algo_skein_512_392;
extern xsum_algo_t xsum_algo_skein_512_400;
extern xsum_algo_t xsum_algo_skein_512_408;
extern xsum_algo_t xsum_algo_skein_512_416;
extern xsum_algo_t xsum_algo_skein_512_424;
extern xsum_algo_t xsum_algo_skein_512_432;
extern xsum_algo_t xsum_algo_skein_512_440;
extern xsum_algo_t xsum_algo_skein_512_448;
extern xsum_algo_t xsum_algo_skein_512_456;
extern xsum_algo_t xsum_algo_skein_512_464;
extern xsum_algo_t xsum_algo_skein_512_472;
extern xsum_algo_t xsum_algo_skein_512_480;
extern xsum_algo_t xsum_algo_skein_512_488;
extern xsum_algo_t xsum_algo_skein_512_496;
extern xsum_algo_t xsum_algo_skein_512_504;
extern xsum_algo_t xsum_algo_skein_512_512;
#endif
#ifdef XSUM_HAS_SKEIN_1024
extern xsum_algo_t xsum_algo_skein_1024_8;
extern xsum_algo_t xsum_algo_skein_1024_16;
extern xsum_algo_t xsum_algo_skein_1024_24;
extern xsum_algo_t xsum_algo_skein_1024_32;
extern xsum_algo_t xsum_algo_skein_1024_40;
extern xsum_algo_t xsum_algo_skein_1024_48;
extern xsum_algo_t xsum_algo_skein_1024_56;
extern xsum_algo_t xsum_algo_skein_1024_64;
extern xsum_algo_t xsum_algo_skein_1024_72;
extern xsum_algo_t xsum_algo_skein_1024_80;
extern xsum_algo_t xsum_algo_skein_1024_88;
extern xsum_algo_t xsum_algo_skein_1024_96;
extern xsum_algo_t xsum_algo_skein_1024_104;
extern xsum_algo_t xsum_algo_skein_1024_112;
extern xsum_algo_t xsum_algo_skein_1024_120;
extern xsum_algo_t xsum_algo_skein_1024_128;
extern xsum_algo_t xsum_algo_skein_1024_136;
extern xsum_algo_t xsum_algo_skein_1024_144;
extern xsum_algo_t xsum_algo_skein_1024_152;
extern xsum_algo_t xsum_algo_skein_1024_160;
extern xsum_algo_t xsum_algo_skein_1024_168;
extern xsum_algo_t xsum_algo_skein_1024_176;
extern xsum_algo_t xsum_algo_skein_1024_184;
extern xsum_algo_t xsum_algo_skein_1024_192;
extern xsum_algo_t xsum_algo_skein_1024_200;
extern xsum_algo_t xsum_algo_skein_1024_208;
extern xsum_algo_t xsum_algo_skein_1024_216;
extern xsum_algo_t xsum_algo_skein_1024_224;
extern xsum_algo_t xsum_algo_skein_1024_232;
extern xsum_algo_t xsum_algo_skein_1024_240;
extern xsum_algo_t xsum_algo_skein_1024_248;
extern xsum_algo_t xsum_algo_skein_1024_256;
extern xsum_algo_t xsum_algo_skein_1024_264;
extern xsum_algo_t xsum_algo_skein_1024_272;
extern xsum_algo_t xsum_algo_skein_1024_280;
extern xsum_algo_t xsum_algo_skein_1024_288;
extern xsum_algo_t xsum_algo_skein_1024_296;
extern xsum_algo_t xsum_algo_skein_1024_304;
extern xsum_algo_t xsum_algo_skein_1024_312;
extern xsum_algo_t xsum_algo_skein_1024_320;
extern xsum_algo_t xsum_algo_skein_1024_328;
extern xsum_algo_t xsum_algo_skein_1024_336;
extern xsum_algo_t xsum_algo_skein_1024_344;
extern xsum_algo_t xsum_algo_skein_1024_352;
extern xsum_algo_t xsum_algo_skein_1024_360;
extern xsum_algo_t xsum_algo_skein_1024_368;
extern xsum_algo_t xsum_algo_skein_1024_376;
extern xsum_algo_t xsum_algo_skein_1024_384;
extern xsum_algo_t xsum_algo_skein_1024_392;
extern xsum_algo_t xsum_algo_skein_1024_400;
extern xsum_algo_t xsum_algo_skein_1024_408;
extern xsum_algo_t xsum_algo_skein_1024_416;
extern xsum_algo_t xsum_algo_skein_1024_424;
extern xsum_algo_t xsum_algo_skein_1024_432;
extern xsum_algo_t xsum_algo_skein_1024_440;
extern xsum_algo_t xsum_algo_skein_1024_448;
extern xsum_algo_t xsum_algo_skein_1024_456;
extern xsum_algo_t xsum_algo_skein_1024_464;
extern xsum_algo_t xsum_algo_skein_1024_472;
extern xsum_algo_t xsum_algo_skein_1024_480;
extern xsum_algo_t xsum_algo_skein_1024_488;
extern xsum_algo_t xsum_algo_skein_1024_496;
extern xsum_algo_t xsum_algo_skein_1024_504;
extern xsum_algo_t xsum_algo_skein_1024_512;
extern xsum_algo_t xsum_algo_skein_1024_520;
extern xsum_algo_t xsum_algo_skein_1024_528;
extern xsum_algo_t xsum_algo_skein_1024_536;
extern xsum_algo_t xsum_algo_skein_1024_544;
extern xsum_algo_t xsum_algo_skein_1024_552;
extern xsum_algo_t xsum_algo_skein_1024_560;
extern xsum_algo_t xsum_algo_skein_1024_568;
extern xsum_algo_t xsum_algo_skein_1024_576;
extern xsum_algo_t xsum_algo_skein_1024_584;
extern xsum_algo_t xsum_algo_skein_1024_592;
extern xsum_algo_t xsum_algo_skein_1024_600;
extern xsum_algo_t xsum_algo_skein_1024_608;
extern xsum_algo_t xsum_algo_skein_1024_616;
extern xsum_algo_t xsum_algo_skein_1024_624;
extern xsum_algo_t xsum_algo_skein_1024_632;
extern xsum_algo_t xsum_algo_skein_1024_640;
extern xsum_algo_t xsum_algo_skein_1024_648;
extern xsum_algo_t xsum_algo_skein_1024_656;
extern xsum_algo_t xsum_algo_skein_1024_664;
extern xsum_algo_t xsum_algo_skein_1024_672;
extern xsum_algo_t xsum_algo_skein_1024_680;
extern xsum_algo_t xsum_algo_skein_1024_688;
extern xsum_algo_t xsum_algo_skein_1024_696;
extern xsum_algo_t xsum_algo_skein_1024_704;
extern xsum_algo_t xsum_algo_skein_1024_712;
extern xsum_algo_t xsum_algo_skein_1024_720;
extern xsum_algo_t xsum_algo_skein_1024_728;
extern xsum_algo_t xsum_algo_skein_1024_736;
extern xsum_algo_t xsum_algo_skein_1024_744;
extern xsum_algo_t xsum_algo_skein_1024_752;
extern xsum_algo_t xsum_algo_skein_1024_760;
extern xsum_algo_t xsum_algo_skein_1024_768;
extern xsum_algo_t xsum_algo_skein_1024_776;
extern xsum_algo_t xsum_algo_skein_1024_784;
extern xsum_algo_t xsum_algo_skein_1024_792;
extern xsum_algo_t xsum_algo_skein_1024_800;
extern xsum_algo_t xsum_algo_skein_1024_808;
extern xsum_algo_t xsum_algo_skein_1024_816;
extern xsum_algo_t xsum_algo_skein_1024_824;
extern xsum_algo_t xsum_algo_skein_1024_832;
extern xsum_algo_t xsum_algo_skein_1024_840;
extern xsum_algo_t xsum_algo_skein_1024_848;
extern xsum_algo_t xsum_algo_skein_1024_856;
extern xsum_algo_t xsum_algo_skein_1024_864;
extern xsum_algo_t xsum_algo_skein_1024_872;
extern xsum_algo_t xsum_algo_skein_1024_880;
extern xsum_algo_t xsum_algo_skein_1024_888;
extern xsum_algo_t xsum_algo_skein_1024_896;
extern xsum_algo_t xsum_algo_skein_1024_904;
extern xsum_algo_t xsum_algo_skein_1024_912;
extern xsum_algo_t xsum_algo_skein_1024_920;
extern xsum_algo_t xsum_algo_skein_1024_928;
extern xsum_algo_t xsum_algo_skein_1024_936;
extern xsum_algo_t xsum_algo_skein_1024_944;
extern xsum_algo_t xsum_algo_skein_1024_952;
extern xsum_algo_t xsum_algo_skein_1024_960;
extern xsum_algo_t xsum_algo_skein_1024_968;
extern xsum_algo_t xsum_algo_skein_1024_976;
extern xsum_algo_t xsum_algo_skein_1024_984;
extern xsum_algo_t xsum_algo_skein_1024_992;
extern xsum_algo_t xsum_algo_skein_1024_1000;
extern xsum_algo_t xsum_algo_skein_1024_1008;
extern xsum_algo_t xsum_algo_skein_1024_1016;
extern xsum_algo_t xsum_algo_skein_1024_1024;
#endif
#ifdef XSUM_HAS_SM3
extern xsum_algo_t xsum_algo_sm3;
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
#ifdef XSUM_HAS_XXHASH32
extern xsum_algo_t xsum_algo_xxhash32;
#endif
#ifdef XSUM_HAS_XXHASH64
extern xsum_algo_t xsum_algo_xxhash64;
#endif
#ifdef XSUM_HAS_XXHASH3_64
extern xsum_algo_t xsum_algo_xxhash3_64;
#endif
#ifdef XSUM_HAS_XXHASH3_128
extern xsum_algo_t xsum_algo_xxhash3_128;
#endif

xsum_algo_t *xsum_algos[] = {
#ifdef XSUM_HAS_ADLER_32
	&xsum_algo_adler_32,
#endif
#ifdef XSUM_HAS_BLAKE_224
	&xsum_algo_blake_224,
#endif
#ifdef XSUM_HAS_BLAKE_256
	&xsum_algo_blake_256,
#endif
#ifdef XSUM_HAS_BLAKE_384
	&xsum_algo_blake_384,
#endif
#ifdef XSUM_HAS_BLAKE_512
	&xsum_algo_blake_512,
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
#ifdef XSUM_HAS_CRC24
	&xsum_algo_crc24,
#endif
#ifdef XSUM_HAS_CRC32
	&xsum_algo_crc32,
#endif
#ifdef XSUM_HAS_CRC64
	&xsum_algo_crc64,
#endif
#ifdef XSUM_HAS_ECHO_FULL
	&xsum_algo_echo_8,
	&xsum_algo_echo_16,
	&xsum_algo_echo_24,
	&xsum_algo_echo_32,
	&xsum_algo_echo_40,
	&xsum_algo_echo_48,
	&xsum_algo_echo_56,
	&xsum_algo_echo_64,
	&xsum_algo_echo_72,
	&xsum_algo_echo_80,
	&xsum_algo_echo_88,
	&xsum_algo_echo_96,
	&xsum_algo_echo_104,
	&xsum_algo_echo_112,
	&xsum_algo_echo_120,
	&xsum_algo_echo_128,
	&xsum_algo_echo_136,
	&xsum_algo_echo_144,
	&xsum_algo_echo_152,
	&xsum_algo_echo_160,
	&xsum_algo_echo_168,
	&xsum_algo_echo_176,
	&xsum_algo_echo_184,
	&xsum_algo_echo_192,
	&xsum_algo_echo_200,
	&xsum_algo_echo_208,
	&xsum_algo_echo_216,
	&xsum_algo_echo_224,
	&xsum_algo_echo_232,
	&xsum_algo_echo_240,
	&xsum_algo_echo_248,
	&xsum_algo_echo_256,
	&xsum_algo_echo_264,
	&xsum_algo_echo_272,
	&xsum_algo_echo_280,
	&xsum_algo_echo_288,
	&xsum_algo_echo_296,
	&xsum_algo_echo_304,
	&xsum_algo_echo_312,
	&xsum_algo_echo_320,
	&xsum_algo_echo_328,
	&xsum_algo_echo_336,
	&xsum_algo_echo_344,
	&xsum_algo_echo_352,
	&xsum_algo_echo_360,
	&xsum_algo_echo_368,
	&xsum_algo_echo_376,
	&xsum_algo_echo_384,
	&xsum_algo_echo_392,
	&xsum_algo_echo_400,
	&xsum_algo_echo_408,
	&xsum_algo_echo_416,
	&xsum_algo_echo_424,
	&xsum_algo_echo_432,
	&xsum_algo_echo_440,
	&xsum_algo_echo_448,
	&xsum_algo_echo_456,
	&xsum_algo_echo_464,
	&xsum_algo_echo_472,
	&xsum_algo_echo_480,
	&xsum_algo_echo_488,
	&xsum_algo_echo_496,
	&xsum_algo_echo_504,
	&xsum_algo_echo_512,
#endif
#ifdef XSUM_HAS_EDON_R_256
	&xsum_algo_edon_r_256,
#endif
#ifdef XSUM_HAS_EDON_R_512
	&xsum_algo_edon_r_512,
#endif
#ifdef XSUM_HAS_ESCH_256
	&xsum_algo_esch_256,
#endif
#ifdef XSUM_HAS_ESCH_384
	&xsum_algo_esch_384,
#endif
#ifdef XSUM_HAS_GOST94
	&xsum_algo_gost94,
#endif
#ifdef XSUM_HAS_GOST94_CRYPTOPRO
	&xsum_algo_gost94_cryptopro,
#endif
#ifdef XSUM_HAS_GROESTL_FULL
	&xsum_algo_groestl_8,
	&xsum_algo_groestl_16,
	&xsum_algo_groestl_24,
	&xsum_algo_groestl_32,
	&xsum_algo_groestl_40,
	&xsum_algo_groestl_48,
	&xsum_algo_groestl_56,
	&xsum_algo_groestl_64,
	&xsum_algo_groestl_72,
	&xsum_algo_groestl_80,
	&xsum_algo_groestl_88,
	&xsum_algo_groestl_96,
	&xsum_algo_groestl_104,
	&xsum_algo_groestl_112,
	&xsum_algo_groestl_120,
	&xsum_algo_groestl_128,
	&xsum_algo_groestl_136,
	&xsum_algo_groestl_144,
	&xsum_algo_groestl_152,
	&xsum_algo_groestl_160,
	&xsum_algo_groestl_168,
	&xsum_algo_groestl_176,
	&xsum_algo_groestl_184,
	&xsum_algo_groestl_192,
	&xsum_algo_groestl_200,
	&xsum_algo_groestl_208,
	&xsum_algo_groestl_216,
	&xsum_algo_groestl_224,
	&xsum_algo_groestl_232,
	&xsum_algo_groestl_240,
	&xsum_algo_groestl_248,
	&xsum_algo_groestl_256,
	&xsum_algo_groestl_264,
	&xsum_algo_groestl_272,
	&xsum_algo_groestl_280,
	&xsum_algo_groestl_288,
	&xsum_algo_groestl_296,
	&xsum_algo_groestl_304,
	&xsum_algo_groestl_312,
	&xsum_algo_groestl_320,
	&xsum_algo_groestl_328,
	&xsum_algo_groestl_336,
	&xsum_algo_groestl_344,
	&xsum_algo_groestl_352,
	&xsum_algo_groestl_360,
	&xsum_algo_groestl_368,
	&xsum_algo_groestl_376,
	&xsum_algo_groestl_384,
	&xsum_algo_groestl_392,
	&xsum_algo_groestl_400,
	&xsum_algo_groestl_408,
	&xsum_algo_groestl_416,
	&xsum_algo_groestl_424,
	&xsum_algo_groestl_432,
	&xsum_algo_groestl_440,
	&xsum_algo_groestl_448,
	&xsum_algo_groestl_456,
	&xsum_algo_groestl_464,
	&xsum_algo_groestl_472,
	&xsum_algo_groestl_480,
	&xsum_algo_groestl_488,
	&xsum_algo_groestl_496,
	&xsum_algo_groestl_504,
	&xsum_algo_groestl_512,
#endif
#ifdef XSUM_HAS_HAS160
	&xsum_algo_has160,
#endif
#ifdef XSUM_HAS_HAVAL_128
	&xsum_algo_haval_128,
#endif
#ifdef XSUM_HAS_HAVAL_160
	&xsum_algo_haval_160,
#endif
#ifdef XSUM_HAS_HAVAL_192
	&xsum_algo_haval_192,
#endif
#ifdef XSUM_HAS_HAVAL_224
	&xsum_algo_haval_224,
#endif
#ifdef XSUM_HAS_HAVAL_256
	&xsum_algo_haval_256,
#endif
#ifdef XSUM_HAS_JH_224
	&xsum_algo_jh_224,
#endif
#ifdef XSUM_HAS_JH_256
	&xsum_algo_jh_256,
#endif
#ifdef XSUM_HAS_JH_384
	&xsum_algo_jh_384,
#endif
#ifdef XSUM_HAS_JH_512
	&xsum_algo_jh_512,
#endif
#ifdef XSUM_HAS_KECCAK_224
	&xsum_algo_keccak_224,
#endif
#ifdef XSUM_HAS_KECCAK_256
	&xsum_algo_keccak_256,
#endif
#ifdef XSUM_HAS_KECCAK_384
	&xsum_algo_keccak_384,
#endif
#ifdef XSUM_HAS_KECCAK_512
	&xsum_algo_keccak_512,
#endif
#ifdef XSUM_HAS_KUPYNA_256
	&xsum_algo_kupyna_256,
#endif
#ifdef XSUM_HAS_KUPYNA_512
	&xsum_algo_kupyna_512,
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
#ifdef XSUM_HAS_MDC2
	&xsum_algo_mdc2,
#endif
#ifdef XSUM_HAS_RIPEMD128
	&xsum_algo_ripemd128,
#endif
#ifdef XSUM_HAS_RIPEMD160
	&xsum_algo_ripemd160,
#endif
#ifdef XSUM_HAS_RIPEMD256
	&xsum_algo_ripemd256,
#endif
#ifdef XSUM_HAS_RIPEMD320
	&xsum_algo_ripemd320,
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
#ifdef XSUM_HAS_SKEIN_256
	&xsum_algo_skein_256_8,
	&xsum_algo_skein_256_16,
	&xsum_algo_skein_256_24,
	&xsum_algo_skein_256_32,
	&xsum_algo_skein_256_40,
	&xsum_algo_skein_256_48,
	&xsum_algo_skein_256_56,
	&xsum_algo_skein_256_64,
	&xsum_algo_skein_256_72,
	&xsum_algo_skein_256_80,
	&xsum_algo_skein_256_88,
	&xsum_algo_skein_256_96,
	&xsum_algo_skein_256_104,
	&xsum_algo_skein_256_112,
	&xsum_algo_skein_256_120,
	&xsum_algo_skein_256_128,
	&xsum_algo_skein_256_136,
	&xsum_algo_skein_256_144,
	&xsum_algo_skein_256_152,
	&xsum_algo_skein_256_160,
	&xsum_algo_skein_256_168,
	&xsum_algo_skein_256_176,
	&xsum_algo_skein_256_184,
	&xsum_algo_skein_256_192,
	&xsum_algo_skein_256_200,
	&xsum_algo_skein_256_208,
	&xsum_algo_skein_256_216,
	&xsum_algo_skein_256_224,
	&xsum_algo_skein_256_232,
	&xsum_algo_skein_256_240,
	&xsum_algo_skein_256_248,
	&xsum_algo_skein_256_256,
#endif
#ifdef XSUM_HAS_SKEIN_512
	&xsum_algo_skein_512_8,
	&xsum_algo_skein_512_16,
	&xsum_algo_skein_512_24,
	&xsum_algo_skein_512_32,
	&xsum_algo_skein_512_40,
	&xsum_algo_skein_512_48,
	&xsum_algo_skein_512_56,
	&xsum_algo_skein_512_64,
	&xsum_algo_skein_512_72,
	&xsum_algo_skein_512_80,
	&xsum_algo_skein_512_88,
	&xsum_algo_skein_512_96,
	&xsum_algo_skein_512_104,
	&xsum_algo_skein_512_112,
	&xsum_algo_skein_512_120,
	&xsum_algo_skein_512_128,
	&xsum_algo_skein_512_136,
	&xsum_algo_skein_512_144,
	&xsum_algo_skein_512_152,
	&xsum_algo_skein_512_160,
	&xsum_algo_skein_512_168,
	&xsum_algo_skein_512_176,
	&xsum_algo_skein_512_184,
	&xsum_algo_skein_512_192,
	&xsum_algo_skein_512_200,
	&xsum_algo_skein_512_208,
	&xsum_algo_skein_512_216,
	&xsum_algo_skein_512_224,
	&xsum_algo_skein_512_232,
	&xsum_algo_skein_512_240,
	&xsum_algo_skein_512_248,
	&xsum_algo_skein_512_256,
	&xsum_algo_skein_512_264,
	&xsum_algo_skein_512_272,
	&xsum_algo_skein_512_280,
	&xsum_algo_skein_512_288,
	&xsum_algo_skein_512_296,
	&xsum_algo_skein_512_304,
	&xsum_algo_skein_512_312,
	&xsum_algo_skein_512_320,
	&xsum_algo_skein_512_328,
	&xsum_algo_skein_512_336,
	&xsum_algo_skein_512_344,
	&xsum_algo_skein_512_352,
	&xsum_algo_skein_512_360,
	&xsum_algo_skein_512_368,
	&xsum_algo_skein_512_376,
	&xsum_algo_skein_512_384,
	&xsum_algo_skein_512_392,
	&xsum_algo_skein_512_400,
	&xsum_algo_skein_512_408,
	&xsum_algo_skein_512_416,
	&xsum_algo_skein_512_424,
	&xsum_algo_skein_512_432,
	&xsum_algo_skein_512_440,
	&xsum_algo_skein_512_448,
	&xsum_algo_skein_512_456,
	&xsum_algo_skein_512_464,
	&xsum_algo_skein_512_472,
	&xsum_algo_skein_512_480,
	&xsum_algo_skein_512_488,
	&xsum_algo_skein_512_496,
	&xsum_algo_skein_512_504,
	&xsum_algo_skein_512_512,
#endif
#ifdef XSUM_HAS_SKEIN_1024
	&xsum_algo_skein_1024_8,
	&xsum_algo_skein_1024_16,
	&xsum_algo_skein_1024_24,
	&xsum_algo_skein_1024_32,
	&xsum_algo_skein_1024_40,
	&xsum_algo_skein_1024_48,
	&xsum_algo_skein_1024_56,
	&xsum_algo_skein_1024_64,
	&xsum_algo_skein_1024_72,
	&xsum_algo_skein_1024_80,
	&xsum_algo_skein_1024_88,
	&xsum_algo_skein_1024_96,
	&xsum_algo_skein_1024_104,
	&xsum_algo_skein_1024_112,
	&xsum_algo_skein_1024_120,
	&xsum_algo_skein_1024_128,
	&xsum_algo_skein_1024_136,
	&xsum_algo_skein_1024_144,
	&xsum_algo_skein_1024_152,
	&xsum_algo_skein_1024_160,
	&xsum_algo_skein_1024_168,
	&xsum_algo_skein_1024_176,
	&xsum_algo_skein_1024_184,
	&xsum_algo_skein_1024_192,
	&xsum_algo_skein_1024_200,
	&xsum_algo_skein_1024_208,
	&xsum_algo_skein_1024_216,
	&xsum_algo_skein_1024_224,
	&xsum_algo_skein_1024_232,
	&xsum_algo_skein_1024_240,
	&xsum_algo_skein_1024_248,
	&xsum_algo_skein_1024_256,
	&xsum_algo_skein_1024_264,
	&xsum_algo_skein_1024_272,
	&xsum_algo_skein_1024_280,
	&xsum_algo_skein_1024_288,
	&xsum_algo_skein_1024_296,
	&xsum_algo_skein_1024_304,
	&xsum_algo_skein_1024_312,
	&xsum_algo_skein_1024_320,
	&xsum_algo_skein_1024_328,
	&xsum_algo_skein_1024_336,
	&xsum_algo_skein_1024_344,
	&xsum_algo_skein_1024_352,
	&xsum_algo_skein_1024_360,
	&xsum_algo_skein_1024_368,
	&xsum_algo_skein_1024_376,
	&xsum_algo_skein_1024_384,
	&xsum_algo_skein_1024_392,
	&xsum_algo_skein_1024_400,
	&xsum_algo_skein_1024_408,
	&xsum_algo_skein_1024_416,
	&xsum_algo_skein_1024_424,
	&xsum_algo_skein_1024_432,
	&xsum_algo_skein_1024_440,
	&xsum_algo_skein_1024_448,
	&xsum_algo_skein_1024_456,
	&xsum_algo_skein_1024_464,
	&xsum_algo_skein_1024_472,
	&xsum_algo_skein_1024_480,
	&xsum_algo_skein_1024_488,
	&xsum_algo_skein_1024_496,
	&xsum_algo_skein_1024_504,
	&xsum_algo_skein_1024_512,
	&xsum_algo_skein_1024_520,
	&xsum_algo_skein_1024_528,
	&xsum_algo_skein_1024_536,
	&xsum_algo_skein_1024_544,
	&xsum_algo_skein_1024_552,
	&xsum_algo_skein_1024_560,
	&xsum_algo_skein_1024_568,
	&xsum_algo_skein_1024_576,
	&xsum_algo_skein_1024_584,
	&xsum_algo_skein_1024_592,
	&xsum_algo_skein_1024_600,
	&xsum_algo_skein_1024_608,
	&xsum_algo_skein_1024_616,
	&xsum_algo_skein_1024_624,
	&xsum_algo_skein_1024_632,
	&xsum_algo_skein_1024_640,
	&xsum_algo_skein_1024_648,
	&xsum_algo_skein_1024_656,
	&xsum_algo_skein_1024_664,
	&xsum_algo_skein_1024_672,
	&xsum_algo_skein_1024_680,
	&xsum_algo_skein_1024_688,
	&xsum_algo_skein_1024_696,
	&xsum_algo_skein_1024_704,
	&xsum_algo_skein_1024_712,
	&xsum_algo_skein_1024_720,
	&xsum_algo_skein_1024_728,
	&xsum_algo_skein_1024_736,
	&xsum_algo_skein_1024_744,
	&xsum_algo_skein_1024_752,
	&xsum_algo_skein_1024_760,
	&xsum_algo_skein_1024_768,
	&xsum_algo_skein_1024_776,
	&xsum_algo_skein_1024_784,
	&xsum_algo_skein_1024_792,
	&xsum_algo_skein_1024_800,
	&xsum_algo_skein_1024_808,
	&xsum_algo_skein_1024_816,
	&xsum_algo_skein_1024_824,
	&xsum_algo_skein_1024_832,
	&xsum_algo_skein_1024_840,
	&xsum_algo_skein_1024_848,
	&xsum_algo_skein_1024_856,
	&xsum_algo_skein_1024_864,
	&xsum_algo_skein_1024_872,
	&xsum_algo_skein_1024_880,
	&xsum_algo_skein_1024_888,
	&xsum_algo_skein_1024_896,
	&xsum_algo_skein_1024_904,
	&xsum_algo_skein_1024_912,
	&xsum_algo_skein_1024_920,
	&xsum_algo_skein_1024_928,
	&xsum_algo_skein_1024_936,
	&xsum_algo_skein_1024_944,
	&xsum_algo_skein_1024_952,
	&xsum_algo_skein_1024_960,
	&xsum_algo_skein_1024_968,
	&xsum_algo_skein_1024_976,
	&xsum_algo_skein_1024_984,
	&xsum_algo_skein_1024_992,
	&xsum_algo_skein_1024_1000,
	&xsum_algo_skein_1024_1008,
	&xsum_algo_skein_1024_1016,
	&xsum_algo_skein_1024_1024,
#endif
#ifdef XSUM_HAS_SM3
	&xsum_algo_sm3,
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
#ifdef XSUM_HAS_XXHASH32
	&xsum_algo_xxhash32,
#endif
#ifdef XSUM_HAS_XXHASH64
	&xsum_algo_xxhash64,
#endif
#ifdef XSUM_HAS_XXHASH3_64
	&xsum_algo_xxhash3_64,
#endif
#ifdef XSUM_HAS_XXHASH3_128
	&xsum_algo_xxhash3_128,
#endif
	NULL // End of array indicator
};
