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
#ifdef XSUM_HAS_SHA3_384

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE_SHA3)

#include <nettle/sha3.h>
XSUM_TEMPLATE_NETTLE(sha3_384, sha3_384, 48)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(sha3_384, GCRY_MD_SHA3_384, 48)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(sha3_384, RHASH_SHA3_384, 48)

#elif defined(XSUM_WITH_GNUTLS)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(sha3_384, GNUTLS_DIG_SHA3_384, 48)

#elif defined(XSUM_WITH_BOTAN_SHA3)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(sha3_384, "SHA-3(384)", 48)

#elif defined(XSUM_WITH_OPENSSL_SHA3)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(sha3_384, sha3_384, 48)

#elif defined(XSUM_WITH_CRYPTOPP)

#include "cryptopp_wrapper.h"
XSUM_TEMPLATE_CRYPTOPP(sha3_384, SHA3_384, 48)

#elif defined(XSUM_WITH_CPPCRYPTO)

#include "cppcrypto_wrapper.h"
XSUM_TEMPLATE_CPPCRYPTO_SIZE(sha3_384, sha3, 48)

#endif

XSUM_TEMPLATE_ALGO(sha3_384, "SHA3-384", 48)

#endif
