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

#ifndef __XSUM_CONFIG_H__
#define __XSUM_CONFIG_H__

#include "config_generated.h"

#if (XSUM_CONFIG_GNUTLS == 1)
#define XSUM_WITH_GNUTLS
#endif

#if (XSUM_CONFIG_MBEDTLS == 1)
#define XSUM_WITH_MBEDTLS
#include <mbedtls/config.h>
#ifdef MBEDTLS_MD2_C
#define XSUM_WITH_MBEDTLS_MD2
#endif
#ifdef MBEDTLS_MD4_C
#define XSUM_WITH_MBEDTLS_MD4
#endif
#ifdef MBEDTLS_MD5_C
#define XSUM_WITH_MBEDTLS_MD5
#endif
#ifdef MBEDTLS_RIPEMD160_C
#define XSUM_WITH_MBEDTLS_RIPEMD160
#endif
#ifdef MBEDTLS_SHA1_C
#define XSUM_WITH_MBEDTLS_SHA1
#endif
#ifdef MBEDTLS_SHA256_C
#define XSUM_WITH_MBEDTLS_SHA256
#endif
#ifdef MBEDTLS_SHA512_C
#define XSUM_WITH_MBEDTLS_SHA512
#endif
#endif

#if (XSUM_CONFIG_NETTLE == 1)
#define XSUM_WITH_NETTLE
#include <nettle/sha3.h>
#ifdef NETTLE_SHA3_FIPS202
#define XSUM_WITH_NETTLE_SHA3
#endif
#endif

#if (XSUM_CONFIG_LIBGCRYPT == 1)
#define XSUM_WITH_LIBGCRYPT
#include <gcrypt.h>
#if (GCRYPT_VERSION_NUMBER >= 0x010800)
#define XSUM_WITH_LIBGCRYPT_BLAKE2
#define XSUM_LIBGCRYPT_MIN_VERSION "1.8.0"
#else
#define XSUM_LIBGCRYPT_MIN_VERSION "1.7.0"
#endif
#endif

#if (XSUM_CONFIG_LIBLZMA == 1)
#define XSUM_WITH_LIBLZMA
#endif

#if (XSUM_CONFIG_LIBSODIUM == 1)
#define XSUM_WITH_LIBSODIUM
#endif

#if (XSUM_CONFIG_RHASH == 1)
#define XSUM_WITH_RHASH
#endif

#if (XSUM_CONFIG_ZLIB == 1)
#define XSUM_WITH_ZLIB
#endif

// Simple built-in algorithms
#define XSUM_HAS_SUM
#define XSUM_HAS_XOR

#if defined(XSUM_WITH_ZLIB)
#define XSUM_HAS_ADLER_32
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)
#define XSUM_HAS_BLAKE2S_128
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)
#define XSUM_HAS_BLAKE2S_160
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)
#define XSUM_HAS_BLAKE2S_224
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)
#define XSUM_HAS_BLAKE2S_256
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_128
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_136
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_144
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_152
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_160
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_168
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_176
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_184
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_192
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_200
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_208
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_216
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_224
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_232
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_240
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_248
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_256
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_264
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_272
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_280
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_288
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_296
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_304
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_312
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_320
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_328
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_336
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_344
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_352
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_360
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_368
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_376
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)  || defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_384
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_392
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_400
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_408
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_416
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_424
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_432
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_440
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_448
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_456
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_464
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_472
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_480
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_488
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_496
#endif

#if defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_504
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)  || defined(XSUM_WITH_LIBSODIUM)
#define XSUM_HAS_BLAKE2B_512
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_ZLIB) || defined(XSUM_WITH_LIBLZMA) || defined(XSUM_WITH_RHASH)
#define XSUM_HAS_CRC32
#endif

#if defined(XSUM_WITH_LIBLZMA)
#define XSUM_HAS_CRC64
#endif

#if defined(XSUM_WITH_RHASH)
#define XSUM_HAS_EDON_R_256
#endif

#if defined(XSUM_WITH_RHASH)
#define XSUM_HAS_EDON_R_512
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH)
#define XSUM_HAS_GOST94
#endif

#if defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_GOST94_CRYPTOPRO
#endif

#if defined(XSUM_WITH_RHASH)
#define XSUM_HAS_HAS160
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_MBEDTLS_MD2)
#define XSUM_HAS_MD2
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_MD4) || defined(XSUM_WITH_RHASH)
#define XSUM_HAS_MD4
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_MD5) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_MD5
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_RIPEMD160) || defined(XSUM_WITH_RHASH)
#define XSUM_HAS_RIPEMD160
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA1) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA1
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA256) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA224
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA256) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA256
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA512) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA384
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA512) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA512
#endif

#if defined(XSUM_WITH_NETTLE)
#define XSUM_HAS_SHA512_224
#endif

#if defined(XSUM_WITH_NETTLE)
#define XSUM_HAS_SHA512_256
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA3_224
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA3_256
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA3_384
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_SHA3_512
#endif

#if defined(XSUM_WITH_RHASH)
#define XSUM_HAS_SNEFRU_128
#endif

#if defined(XSUM_WITH_RHASH)
#define XSUM_HAS_SNEFRU_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_STREEBOG_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_GNUTLS)
#define XSUM_HAS_STREEBOG_512
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH)
#define XSUM_HAS_TIGER
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_TIGER2
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_WHIRLPOOL)
#define XSUM_HAS_WHIRLPOOL
#endif

#endif
