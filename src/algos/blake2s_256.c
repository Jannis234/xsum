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
#ifdef XSUM_HAS_BLAKE2S_256

#include "algo_template.h"

#if defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(blake2s_256, GCRY_MD_BLAKE2S_256, 32)

#elif defined(XSUM_WITH_LIBB2)

#include <blake2.h>
XSUM_TEMPLATE_LIBB2(blake2s_256, blake2s, 32)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(blake2s_256, RHASH_BLAKE2S, 32)

#elif defined(XSUM_WITH_OPENSSL_BLAKE2)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(blake2s_256, blake2s256, 32)

#elif defined(XSUM_WITH_CRYPTOPP)

#include "cryptopp_wrapper.h"
XSUM_TEMPLATE_CRYPTOPP_SIZE(blake2s_256, BLAKE2s, 32)

#elif defined(XSUM_WITH_CPPCRYPTO)

#include "cppcrypto_wrapper.h"
XSUM_TEMPLATE_CPPCRYPTO_SIZE(blake2s_256, blake2s, 32)

#endif

XSUM_TEMPLATE_ALGO(blake2s_256, "BLAKE2s-256", 32)

#endif
