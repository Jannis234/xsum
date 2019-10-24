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
#ifdef XSUM_HAS_MD4

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/md4.h>
XSUM_TEMPLATE_NETTLE(md4, md4, 16)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(md4, GCRY_MD_MD4, 16)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(md4, MBEDTLS_MD_MD4, 16)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(md4, RHASH_MD4, 16)

#elif defined(XSUM_WITH_BOTAN_MD4)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(md4, "MD4", 16)

#elif defined(XSUM_WITH_OPENSSL_MD4)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(md4, md4, 16)

#elif defined(XSUM_WITH_MHASH_MD4)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(md4, MHASH_MD4, 16)

#elif defined(XSUM_WITH_WIN_CNG)

#include <windows.h>
#include <bcrypt.h>
#include <ntstatus.h>
XSUM_TEMPLATE_WIN_CNG(md4, BCRYPT_MD4_ALGORITHM, 16)

#elif defined(XSUM_WITH_CRYPTOPP)

#include "cryptopp_wrapper.h"
XSUM_TEMPLATE_CRYPTOPP(md4, MD4, 16)

#endif

XSUM_TEMPLATE_ALGO(md4, "MD4", 16)

#endif
