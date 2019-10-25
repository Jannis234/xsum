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
#ifdef XSUM_HAS_SHA1

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/sha1.h>
XSUM_TEMPLATE_NETTLE(sha1, sha1, 20)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(sha1, GCRY_MD_SHA1, 20)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(sha1, MBEDTLS_MD_SHA1, 20)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(sha1, RHASH_SHA1, 20)

#elif defined(XSUM_WITH_GNUTLS)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(sha1, GNUTLS_DIG_SHA1, 20)

#elif defined(XSUM_WITH_NSS)

#include <sechash.h>
#include <secoidt.h>
XSUM_TEMPLATE_NSS(sha1, SEC_OID_SHA1, 20);

#elif defined(XSUM_WITH_BOTAN_SHA1)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(sha1, "SHA1", 20)

#elif defined(XSUM_WITH_OPENSSL_SHA1)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(sha1, sha1, 20)

#elif defined(XSUM_WITH_MHASH_SHA1)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(sha1, MHASH_SHA1, 20)

#elif defined(XSUM_WITH_WIN_CNG)

#include <windows.h>
#include <bcrypt.h>
#include <ntstatus.h>
XSUM_TEMPLATE_WIN_CNG(sha1, BCRYPT_SHA1_ALGORITHM, 20)

#elif defined(XSUM_WITH_GLIB)

#include <glib.h>
XSUM_TEMPLATE_GLIB(sha1, G_CHECKSUM_SHA1, 20)

#elif defined(XSUM_WITH_CRYPTOPP)

#include "cryptopp_wrapper.h"
XSUM_TEMPLATE_CRYPTOPP(sha1, SHA1, 20)

#elif defined(XSUM_WITH_CPPCRYPTO)

#include "cppcrypto_wrapper.h"
XSUM_TEMPLATE_CPPCRYPTO(sha1, sha1, 20)

#endif

XSUM_TEMPLATE_ALGO(sha1, "SHA1", 20)

#endif
