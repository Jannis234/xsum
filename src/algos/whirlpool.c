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
#ifdef XSUM_HAS_WHIRLPOOL

#include "algo_template.h"

#if defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(whirlpool, GCRY_MD_WHIRLPOOL, 64)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(whirlpool, RHASH_WHIRLPOOL, 64)

#elif defined(XSUM_WITH_BOTAN_WHIRLPOOL)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(whirlpool, "Whirlpool", 64)

#elif defined(XSUM_WITH_OPENSSL_WHIRLPOOL)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(whirlpool, whirlpool, 64)

#elif defined(XSUM_WITH_MHASH_WHIRLPOOL)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(whirlpool, MHASH_WHIRLPOOL, 64)

#elif defined(XSUM_WITH_CRYPTOPP)

#include "cryptopp_wrapper.h"
XSUM_TEMPLATE_CRYPTOPP(whirlpool, Whirlpool, 64)

#elif defined(XSUM_WITH_CPPCRYPTO)

#include "cppcrypto_wrapper.h"
XSUM_TEMPLATE_CPPCRYPTO(whirlpool, whirlpool, 64)

#endif

XSUM_TEMPLATE_ALGO(whirlpool, "WHIRLPOOL", 64)

#endif
