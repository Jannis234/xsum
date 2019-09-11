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
#ifdef XSUM_HAS_RIPEMD160

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/ripemd160.h>
XSUM_TEMPLATE_NETTLE(ripemd160, ripemd160, 20)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(ripemd160, GCRY_MD_RMD160, 20)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(ripemd160, MBEDTLS_MD_RIPEMD160, 20)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(ripemd160, RHASH_RIPEMD160, 20)

#elif defined(XSUM_WITH_BOTAN_RIPEMD160)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(ripemd160, "RIPEMD160", 20)

#elif defined(XSUM_WITH_OPENSSL_RIPEMD160)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(ripemd160, ripemd160, 20)

#endif

XSUM_TEMPLATE_ALGO(ripemd160, "RIPEMD160", 20)

#endif
