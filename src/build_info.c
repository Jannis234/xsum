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

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "config.h"

#ifdef XSUM_WITH_BOTAN
#define XSUM_HAS_EXTLIB
#include <botan/build.h>
#include <botan/ffi.h>
#endif
#ifdef XSUM_WITH_GLIB
#define XSUM_HAS_EXTLIB
#include <glib.h>
#endif
#ifdef XSUM_WITH_GNUTLS
#define XSUM_HAS_EXTLIB
#include <gnutls/gnutls.h>
#endif
#ifdef XSUM_WITH_MBEDTLS
#define XSUM_HAS_EXTLIB
#include <mbedtls/version.h>
#endif
#ifdef XSUM_WITH_MHASH
#define XSUM_HAS_EXTLIB
#include <mhash.h>
#endif
#ifdef XSUM_WITH_NETTLE
#define XSUM_HAS_EXTLIB
#include <nettle/version.h>
#endif
#ifdef XSUM_WITH_NSS
#define XSUM_HAS_EXTLIB
#include <nss/nss.h>
#endif
#ifdef XSUM_WITH_LIBB2
#define XSUM_HAS_EXTLIB
#endif
#ifdef XSUM_WITH_LIBGCRYPT
#define XSUM_HAS_EXTLIB
#include <gcrypt.h>
#endif
#ifdef XSUM_WITH_LIBLZMA
#define XSUM_HAS_EXTLIB
#include <lzma.h>
#endif
#ifdef XSUM_WITH_LIBSODIUM
#define XSUM_HAS_EXTLIB
#include <sodium.h>
#endif
#ifdef XSUM_WITH_OPENSSL
#define XSUM_HAS_EXTLIB
#include <openssl/crypto.h>
#include <openssl/opensslv.h>
#endif
#ifdef XSUM_WITH_RHASH
#define XSUM_HAS_EXTLIB
#endif
#ifdef XSUM_WITH_XXHASH
#define XSUM_HAS_EXTLIB
#include <xxhash.h>
#endif
#ifdef XSUM_WITH_ZLIB
#define XSUM_HAS_EXTLIB
#include <zlib.h>
#endif

void xsum_build_info() {
	
	printf("xsum %s\n\n", XSUM_VERSION_STRING);
	
	printf("Optional features:\n");
#ifdef XSUM_WITH_OPENMP
	char *opt_omp = "Yes";
#else
	char *opt_omp = "No";
#endif
	printf("  OpenMP: %s\n", opt_omp);
#ifdef XSUM_WITH_MMAP
	char *opt_mmap = "Yes";
#else
	char *opt_mmap = "No";
#endif
	printf("  mmap: %s\n", opt_mmap);
#ifdef XSUM_WITH_WIN_CNG
	char *opt_win = "Yes";
#else
	char *opt_win = "No";
#endif
	printf("  Windows CNG API: %s\n", opt_win);
	
	printf("\nExternal libraries (build / runtime):\n");
#ifdef XSUM_WITH_BOTAN
	printf("  Botan: %d.%d.%d / %d.%d.%d\n", BOTAN_VERSION_MAJOR, BOTAN_VERSION_MINOR, BOTAN_VERSION_PATCH, botan_version_major(), botan_version_minor(), botan_version_patch());
#endif
#ifdef XSUM_WITH_GLIB
	printf("  glib: %d.%d.%d / %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION, glib_major_version, glib_minor_version, glib_micro_version);
#endif
#ifdef XSUM_WITH_GNUTLS
	printf("  GnuTLS: %s / %s\n", GNUTLS_VERSION, gnutls_check_version(NULL));
#endif
#ifdef XSUM_WITH_MBEDTLS
	char buf[18]; // Maximum possible string length from mbedtls/version.h
	mbedtls_version_get_string(buf);
	printf("  mbedTLS: %s / %s\n", MBEDTLS_VERSION_STRING, buf);
#endif
#ifdef XSUM_WITH_MHASH
	printf("  mhash: %d /\n", MHASH_API_VERSION);
#endif
#ifdef XSUM_WITH_NETTLE
	printf("  nettle: %d.%d / %d.%d\n", NETTLE_VERSION_MAJOR, NETTLE_VERSION_MINOR, nettle_version_major(), nettle_version_minor());
#endif
#ifdef XSUM_WITH_NSS
	printf("  NSS: %s / %s\n", NSS_VERSION, NSS_GetVersion());
#endif
#ifdef XSUM_WITH_LIBB2
	printf("  libb2: /\n");
#endif
#ifdef XSUM_WITH_LIBGCRYPT
	printf("  libgcrypt: %s / %s\n", GCRYPT_VERSION, gcry_check_version(NULL));
#endif
#ifdef XSUM_WITH_LIBLZMA
	printf("  liblzma: %s / %s\n", LZMA_VERSION_STRING, lzma_version_string());
#endif
#ifdef XSUM_WITH_LIBSODIUM
	printf("  libsodium: %s / %s\n", SODIUM_VERSION_STRING, sodium_version_string());
#endif
#ifdef XSUM_WITH_OPENSSL
	printf("  OpenSSL: %s / %s\n", OPENSSL_VERSION_TEXT, OpenSSL_version(OPENSSL_VERSION));
#endif
#ifdef XSUM_WITH_RHASH
	printf("  RHash: /\n");
#endif
#ifdef XSUM_WITH_XXHASH
	printf("  xxHash: %d.%d.%d / %u\n", XXH_VERSION_MAJOR, XXH_VERSION_MINOR, XXH_VERSION_RELEASE, XXH_versionNumber());
#endif
#ifdef XSUM_WITH_ZLIB
	printf("  zlib: %s / %s\n", ZLIB_VERSION, zlibVersion());
#endif
#ifndef XSUM_HAS_EXTLIB
	printf("  None\n");
#endif
	
}
