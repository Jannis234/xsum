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

#include <unistd.h>
#ifdef _POSIX_MAPPED_FILES
	#if (_POSIX_MAPPED_FILES > 0)
		#define XSUM_WITH_MMAP
	#endif
#endif

#if (XSUM_CONFIG_OPENMP == 1)
	#define XSUM_WITH_OPENMP
#endif

#if (XSUM_CONFIG_BOTAN == 1)
	#include <botan/build.h>
	#define XSUM_WITH_BOTAN
	#ifdef BOTAN_HAS_ADLER32
		#define XSUM_WITH_BOTAN_ADLER_32
	#endif
	#ifdef BOTAN_HAS_BLAKE2B
		#define XSUM_WITH_BOTAN_BLAKE2B
	#endif
	#ifdef BOTAN_HAS_CRC24
		#define XSUM_WITH_BOTAN_CRC24
	#endif
	#ifdef BOTAN_HAS_CRC32
		#define XSUM_WITH_BOTAN_CRC32
	#endif
	#ifdef BOTAN_HAS_GOST_34_11
		#define XSUM_WITH_BOTAN_GOST94
	#endif
	#ifdef BOTAN_HAS_KECCAK
		#define XSUM_WITH_BOTAN_KECCAK
	#endif
	#ifdef BOTAN_HAS_MD4
		#define XSUM_WITH_BOTAN_MD4
	#endif
	#ifdef BOTAN_HAS_MD5
		#define XSUM_WITH_BOTAN_MD5
	#endif
	#ifdef BOTAN_HAS_RIPEMD160
		#define XSUM_WITH_BOTAN_RIPEMD160
	#endif
	#ifdef BOTAN_HAS_SHA1
		#define XSUM_WITH_BOTAN_SHA1
	#endif
	#ifdef BOTAN_HAS_SHA2_32
		#define XSUM_WITH_BOTAN_SHA2_256
	#endif
	#ifdef BOTAN_HAS_SHA2_64
		#define XSUM_WITH_BOTAN_SHA2_512
	#endif
	#ifdef BOTAN_HAS_SHA3
		#define XSUM_WITH_BOTAN_SHA3
	#endif
	#ifdef BOTAN_HAS_SM3
		#define XSUM_WITH_BOTAN_SM3
	#endif
	#ifdef BOTAN_HAS_SKEIN_512
		#define XSUM_WITH_BOTAN_SKEIN
	#endif
	#ifdef BOTAN_HAS_STREEBOG
		#define XSUM_WITH_BOTAN_STREEBOG
	#endif
	#ifdef BOTAN_HAS_TIGER
		#define XSUM_WITH_BOTAN_TIGER
	#endif
	#ifdef BOTAN_HAS_WHIRLPOOL
		#define XSUM_WITH_BOTAN_WHIRLPOOL
	#endif
#endif

#if (XSUM_CONFIG_CPPCRYPTO == 1)
	#define XSUM_WITH_CPPCRYPTO
#endif

#if (XSUM_CONFIG_CRYPTOPP == 1)
	#define XSUM_WITH_CRYPTOPP
#endif

#if (XSUM_CONFIG_GLIB == 1)
	#include <glib.h>
	#define XSUM_WITH_GLIB
	#if (GLIB_MAJOR_VERSION > 2) || (GLIB_MINOR_VERSION >= 36)
		#define XSUM_WITH_GLIB_SHA512
	#endif
	#if (GLIB_MAJOR_VERSION > 2) || (GLIB_MINOR_VERSION >= 51)
		#define XSUM_WITH_GLIB_SHA384
	#endif
#endif

#if (XSUM_CONFIG_GNUTLS == 1)
	#define XSUM_WITH_GNUTLS
	#include <gnutls/gnutls.h>
	// Streebog is broken in gnutls < 3.6.8
	#if (GNUTLS_VERSION_NUMBER >= 0x030608)
		#define XSUM_WITH_GNUTLS_STREEBOG
	#endif
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

#if (XSUM_CONFIG_MHASH == 1)
	#include <mhash.h>
	#define XSUM_WITH_MHASH
	#ifdef ENABLE_ADLER32
		#define XSUM_WITH_MHASH_ADLER32
	#endif
	#ifdef ENABLE_CRC32
		#define XSUM_WITH_MHASH_CRC32
	#endif
	#ifdef ENABLE_HAVAL
		#define XSUM_WITH_MHASH_HAVAL
	#endif
	#ifdef ENABLE_MD2
		#define XSUM_WITH_MHASH_MD2
	#endif
	#ifdef ENABLE_MD4
		#define XSUM_WITH_MHASH_MD4
	#endif
	#ifdef ENABLE_MD5
		#define XSUM_WITH_MHASH_MD5
	#endif
	#ifdef ENABLE_RIPEMD
		#define XSUM_WITH_MHASH_RIPEMD
	#endif
	#ifdef ENABLE_SHA1
		#define XSUM_WITH_MHASH_SHA1
	#endif
	#ifdef ENABLE_SHA256_SHA224
		#define XSUM_WITH_MHASH_SHA256
	#endif
	#ifdef ENABLE_SHA512_SHA384
		#define XSUM_WITH_MHASH_SHA512
	#endif
	#ifdef ENABLE_SNEFRU
		#define XSUM_WITH_MHASH_SNEFRU
	#endif
	#ifdef ENABLE_TIGER
		#define XSUM_WITH_MHASH_TIGER
	#endif
	#ifdef ENABLE_WHIRLPOOL
		#define XSUM_WITH_MHASH_WHIRLPOOL
	#endif
#endif

#if (XSUM_CONFIG_NETTLE == 1)
	#define XSUM_WITH_NETTLE
	#include <nettle/sha3.h>
	#ifdef NETTLE_SHA3_FIPS202
		#define XSUM_WITH_NETTLE_SHA3
	#endif
#endif

#if (XSUM_CONFIG_NSS == 1)
	#define XSUM_WITH_NSS
#endif

#if (XSUM_CONFIG_LIBB2 == 1)
	#define XSUM_WITH_LIBB2
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
	// libgcrypt currently produces incorrect streebog hashes (tested with 1.8.5)
	//#define XSUM_WITH_LIBGCRYPT_STREEBOG
#endif

#if (XSUM_CONFIG_LIBLZMA == 1)
	#define XSUM_WITH_LIBLZMA
#endif

#if (XSUM_CONFIG_LIBSODIUM == 1)
	#define XSUM_WITH_LIBSODIUM
#endif

#if (XSUM_CONFIG_OPENSSL == 1)
	#include <openssl/opensslv.h>
	#include <openssl/evp.h>
	#define XSUM_WITH_OPENSSL
	#if !defined(OPENSSL_NO_BLAKE2) && !defined(LIBRESSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x1010000)
		#define XSUM_WITH_OPENSSL_BLAKE2
	#endif
	#if !defined(OPENSSL_NO_GOST)
		#if defined(LIBRESSL_VERSION_NUMBER) || (OPENSSL_VERSION_NUMBER < 0x1010000)
			#define XSUM_WITH_OPENSSL_GOST94
		#endif
		#if defined(LIBRESSL_VERSION_NUMBER)
			// Streebog is broken in libressl < 3.0.0
			#if (LIBRESSL_VERSION_NUMBER >= 0x3000000)
				#define XSUM_WITH_OPENSSL_STREEBOG
			#endif
		#endif
	#endif
	#if !defined(OPENSSL_NO_MD2)
		#define XSUM_WITH_OPENSSL_MD2
	#endif
	#if !defined(OPENSSL_NO_MD4)
		#define XSUM_WITH_OPENSSL_MD4
	#endif
	#if !defined(OPENSSL_NO_MD5)
		#define XSUM_WITH_OPENSSL_MD5
	#endif
	#if !defined(OPENSSL_NO_MDC2)
		#define XSUM_WITH_OPENSSL_MDC2
	#endif
	#if !defined(OPENSSL_NO_RIPEMD)
		#define XSUM_WITH_OPENSSL_RIPEMD160
	#endif
	#if !defined(OPENSSL_NO_SHA)
		#define XSUM_WITH_OPENSSL_SHA1
	#endif
	#if !defined(OPENSSL_NO_SHA256)
		#define XSUM_WITH_OPENSSL_SHA256
	#endif
	#if !defined(OPENSSL_NO_SHA512)
		#define XSUM_WITH_OPENSSL_SHA512
	#endif
	#if !defined(LIBRESSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x1010100)
		#define XSUM_WITH_OPENSSL_SHA512_256
		#define XSUM_WITH_OPENSSL_SHA3
	#endif
	#if !defined(OPENSSL_NO_SM3)
		#if defined(LIBRESSL_VERSION_NUMBER)
			#if (LIBRESSL_VERSION_NUMBER >= 0x2090000)
				#define XSUM_WITH_OPENSSL_SM3
			#endif
		#else
			#if (OPENSSL_VERSION_NUMBER >= 0x1010100)
				#define XSUM_WITH_OPENSSL_SM3
			#endif
		#endif
	#endif
	#if !defined(OPENSSL_NO_WHIRLPOOL)
		#define XSUM_WITH_OPENSSL_WHIRLPOOL
	#endif
#endif

#if (XSUM_CONFIG_RHASH == 1)
	#define XSUM_WITH_RHASH
#endif

#if (XSUM_CONFIG_XXHASH == 1)
	#define XSUM_WITH_XXHASH
#endif

#if (XSUM_CONFIG_ZLIB == 1)
	#define XSUM_WITH_ZLIB
	#define XSUM_WITH_ZLIB_COMPRESS
#endif

#if (XSUM_CONFIG_WIN_CNG == 1)
	#define XSUM_WITH_WIN_CNG
#endif

// Simple built-in algorithms
#define XSUM_HAS_SUM
#define XSUM_HAS_XOR

#if defined(XSUM_WITH_ZLIB) || defined(XSUM_WITH_BOTAN_ADLER_32) || defined(XSUM_WITH_MHASH_ADLER32) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_ADLER_32
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE_224
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE_256
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE_384
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE_512
#endif

#if defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2S_FULL
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2S_128
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2S_160
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2S_224
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_OPENSSL_BLAKE2) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2S_256
#endif

#if defined(XSUM_WITH_LIBB2)
	#define XSUM_HAS_BLAKE2SP_FULL
#endif

#if defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_BOTAN_BLAKE2B) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2B_FULL
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_BOTAN_BLAKE2B) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2B_160
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_BOTAN_BLAKE2B) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2B_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2)  || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_BOTAN_BLAKE2B) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2B_384
#endif

#if defined(XSUM_WITH_LIBGCRYPT_BLAKE2) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_LIBB2) || defined(XSUM_WITH_BOTAN_BLAKE2B) || defined(XSUM_WITH_OPENSSL_BLAKE2) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_BLAKE2B_512
#endif

#if defined(XSUM_WITH_LIBB2)
	#define XSUM_HAS_BLAKE2BP_FULL
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_BOTAN_CRC24)
	#define XSUM_HAS_CRC24
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_ZLIB) || defined(XSUM_WITH_LIBLZMA) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_BOTAN_CRC32) || defined(XSUM_WITH_MHASH_CRC32) || defined(XSUM_WITH_CRYPTOPP)
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

#if defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_BOTAN_GOST94) || defined(XSUM_WITH_OPENSSL_GOST94)
	#define XSUM_HAS_GOST94_CRYPTOPRO
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_GROESTL_FULL
#endif

#if defined(XSUM_WITH_RHASH)
	#define XSUM_HAS_HAS160
#endif

#if defined(XSUM_WITH_MHASH_HAVAL)
	#define XSUM_HAS_HAVAL_128
#endif

#if defined(XSUM_WITH_MHASH_HAVAL)
	#define XSUM_HAS_HAVAL_160
#endif

#if defined(XSUM_WITH_MHASH_HAVAL)
	#define XSUM_HAS_HAVAL_192
#endif

#if defined(XSUM_WITH_MHASH_HAVAL)
	#define XSUM_HAS_HAVAL_224
#endif

#if defined(XSUM_WITH_MHASH_HAVAL)
	#define XSUM_HAS_HAVAL_256
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_JH_224
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_JH_256
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_JH_384
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_JH_512
#endif

#if defined(XSUM_WITH_BOTAN_KECCAK) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_KECCAK_224
#endif

#if defined(XSUM_WITH_BOTAN_KECCAK) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_KECCAK_256
#endif

#if defined(XSUM_WITH_BOTAN_KECCAK) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_KECCAK_384
#endif

#if defined(XSUM_WITH_BOTAN_KECCAK) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_KECCAK_512
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_KUPYNA_256
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_KUPYNA_512
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_MBEDTLS_MD2) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_OPENSSL_MD2) || defined(XSUM_WITH_MHASH_MD2) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_MD2
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_MD4) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_BOTAN_MD4) || defined(XSUM_WITH_OPENSSL_MD4) || defined(XSUM_WITH_MHASH_MD4) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_MD4
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_MD5) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_BOTAN_MD5) || defined(XSUM_WITH_OPENSSL_MD5) || defined(XSUM_WITH_MHASH_MD5) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_GLIB) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_MD5
#endif

#if defined(XSUM_WITH_OPENSSL_MDC2)
	#define XSUM_HAS_MDC2
#endif

#if defined(XSUM_WITH_MHASH_RIPEMD) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_RIPEMD128
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_RIPEMD160) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_BOTAN_RIPEMD160) || defined(XSUM_WITH_OPENSSL_RIPEMD160) || defined(XSUM_WITH_MHASH_RIPEMD) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_RIPEMD160
#endif

#if defined(XSUM_WITH_MHASH_RIPEMD) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_RIPEMD256
#endif

#if defined(XSUM_WITH_MHASH_RIPEMD) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_RIPEMD320
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA1) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_BOTAN_SHA1) || defined(XSUM_WITH_OPENSSL_SHA1) || defined(XSUM_WITH_MHASH_SHA1) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_GLIB) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA1
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA256) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_BOTAN_SHA2_256) || defined(XSUM_WITH_OPENSSL_SHA256) || defined(XSUM_WITH_MHASH_SHA256) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA224
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA256) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_BOTAN_SHA2_256) || defined(XSUM_WITH_OPENSSL_SHA256) || defined(XSUM_WITH_MHASH_SHA256) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_GLIB) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA256
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA512) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_BOTAN_SHA2_512) || defined(XSUM_WITH_OPENSSL_SHA512) || defined(XSUM_WITH_MHASH_SHA512) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_GLIB_SHA384) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA384
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_MBEDTLS_SHA512) || defined(XSUM_WITH_LIBSODIUM) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_NSS) || defined(XSUM_WITH_BOTAN_SHA2_512) || defined(XSUM_WITH_OPENSSL_SHA512) || defined(XSUM_WITH_MHASH_SHA512) || defined(XSUM_WITH_WIN_CNG) || defined(XSUM_WITH_GLIB_SHA512) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA512
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_OPENSSL_SHA512_256) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA512_224
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_OPENSSL_SHA512_256) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA512_256
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_BOTAN_SHA3) || defined(XSUM_WITH_OPENSSL_SHA3) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA3_224
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_BOTAN_SHA3) || defined(XSUM_WITH_OPENSSL_SHA3) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA3_256
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_BOTAN_SHA3) || defined(XSUM_WITH_OPENSSL_SHA3) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA3_384
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_GNUTLS) || defined(XSUM_WITH_BOTAN_SHA3) || defined(XSUM_WITH_OPENSSL_SHA3) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SHA3_512
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SKEIN_256
#endif

#if defined(XSUM_WITH_BOTAN_SKEIN) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SKEIN_512
#endif

#if defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SKEIN_1024
#endif

#if defined(XSUM_WITH_BOTAN_SM3) || defined(XSUM_WITH_OPENSSL_SM3) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_SM3
#endif

#if defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_MHASH_SNEFRU)
	#define XSUM_HAS_SNEFRU_128
#endif

#if defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_MHASH_SNEFRU)
	#define XSUM_HAS_SNEFRU_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT_STREEBOG) || defined(XSUM_WITH_GNUTLS_STREEBOG) || defined(XSUM_WITH_BOTAN_STREEBOG) || defined(XSUM_WITH_OPENSSL_STREEBOG) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_STREEBOG_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT_STREEBOG) || defined(XSUM_WITH_GNUTLS_STREEBOG) || defined(XSUM_WITH_BOTAN_STREEBOG) || defined(XSUM_WITH_OPENSSL_STREEBOG) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_STREEBOG_512
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_RHASH) || defined(XSUM_WITH_BOTAN_TIGER) || defined(XSUM_WITH_MHASH_TIGER) || defined(XSUM_WITH_CRYPTOPP)
	#define XSUM_HAS_TIGER
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
	#define XSUM_HAS_TIGER2
#endif

#if defined(XSUM_WITH_LIBGCRYPT) || defined(XSUM_WITH_WHIRLPOOL) || defined(XSUM_WITH_BOTAN_WHIRLPOOL) || defined(XSUM_WITH_OPENSSL_WHIRLPOOL) || defined(XSUM_WITH_MHASH_WHIRLPOOL) || defined(XSUM_WITH_CRYPTOPP) || defined(XSUM_WITH_CPPCRYPTO)
	#define XSUM_HAS_WHIRLPOOL
#endif

#if defined(XSUM_WITH_XXHASH)
	#define XSUM_HAS_XXHASH32
#endif

#if defined(XSUM_WITH_XXHASH)
	#define XSUM_HAS_XXHASH64
#endif

#endif
