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
#ifdef XSUM_HAS_SHA512

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/sha2.h>
XSUM_TEMPLATE_NETTLE(sha512, sha512, 64)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(sha512, GCRY_MD_SHA512, 64)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(sha512, MBEDTLS_MD_SHA512, 64)

#elif defined(XSUM_WITH_LIBSODIUM)

#include <sodium.h>
XSUM_TEMPLATE_LIBSODIUM_SHA(sha512, 64)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(sha512, RHASH_SHA512, 64)

#elif defined(XSUM_WITH_GNUTLS)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(sha512, GNUTLS_DIG_SHA512, 64)

#elif defined(XSUM_WITH_NSS)

#include <sechash.h>
#include <secoidt.h>
XSUM_TEMPLATE_NSS(sha512, SEC_OID_SHA512, 64);

#elif defined(XSUM_WITH_BOTAN_SHA2_512)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(sha512, "SHA-512", 64)

#elif defined(XSUM_WITH_OPENSSL_SHA512)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(sha512, sha512, 64)

#elif defined(XSUM_WITH_MHASH_SHA512)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(sha512, MHASH_SHA512, 64)

#endif

XSUM_TEMPLATE_ALGO(sha512, "SHA512", 64)

#endif
