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
#ifdef XSUM_HAS_SHA256

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/sha2.h>
XSUM_TEMPLATE_NETTLE(sha256, sha256, 32)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(sha256, GCRY_MD_SHA256, 32)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(sha256, MBEDTLS_MD_SHA256, 32)

#elif defined(XSUM_WITH_LIBSODIUM)

#include <sodium.h>
XSUM_TEMPLATE_LIBSODIUM_SHA(sha256, 32)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(sha256, RHASH_SHA256, 32)

#elif defined(XSUM_WITH_GNUTLS)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(sha256, GNUTLS_DIG_SHA256, 32)

#elif defined(XSUM_WITH_NSS)

#include <sechash.h>
#include <secoidt.h>
XSUM_TEMPLATE_NSS(sha256, SEC_OID_SHA256, 32);

#elif defined(XSUM_WITH_BOTAN_SHA2_256)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(sha256, "SHA-256", 32)

#elif defined(XSUM_WITH_OPENSSL_SHA256)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(sha256, sha256, 32)

#elif defined(XSUM_WITH_MHASH_SHA256)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(sha256, MHASH_SHA256, 32)

#elif defined(XSUM_WITH_WIN_CNG)

#include <windows.h>
#include <bcrypt.h>
#include <ntstatus.h>
XSUM_TEMPLATE_WIN_CNG(sha256, BCRYPT_SHA256_ALGORITHM, 32)

#elif defined(XSUM_WITH_GLIB)

#include <glib.h>
XSUM_TEMPLATE_GLIB(sha256, G_CHECKSUM_SHA256, 32)

#elif defined(XSUM_WITH_CRYPTOPP)

#include "cryptopp_wrapper.h"
XSUM_TEMPLATE_CRYPTOPP(sha256, SHA256, 32)

#elif defined(XSUM_WITH_CPPCRYPTO)

#include "cppcrypto_wrapper.h"
XSUM_TEMPLATE_CPPCRYPTO(sha256, sha256, 32)

#endif

XSUM_TEMPLATE_ALGO(sha256, "SHA256", 32)

#endif
