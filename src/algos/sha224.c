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
#ifdef XSUM_HAS_SHA224

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/sha2.h>
XSUM_TEMPLATE_NETTLE(sha224, sha224, 28)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(sha224, GCRY_MD_SHA224, 28)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(sha224, MBEDTLS_MD_SHA224, 28)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(sha224, RHASH_SHA224, 28)

#elif defined(XSUM_WITH_GNUTLS)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(sha224, GNUTLS_DIG_SHA224, 28)

#elif defined(XSUM_WITH_NSS)

#include <sechash.h>
#include <secoidt.h>
XSUM_TEMPLATE_NSS(sha224, SEC_OID_SHA224, 28);

#elif defined(XSUM_WITH_BOTAN_SHA2_256)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(sha224, "SHA-224", 28)

#endif

XSUM_TEMPLATE_ALGO(sha224, "SHA224", 28)

#endif
