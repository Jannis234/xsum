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
#ifdef XSUM_HAS_SHA512_256

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/sha2.h>
XSUM_TEMPLATE_NETTLE(sha512_256, sha512_256, 32)

#elif defined(XSUM_WITH_OPENSSL_SHA512_256)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(sha512_256, sha512_256, 32)

#elif defined(XSUM_WITH_CPPCRYPTO)

#include "cppcrypto_wrapper.h"
XSUM_TEMPLATE_CPPCRYPTO_SIZE(sha512_256, sha512, 32)

#endif

XSUM_TEMPLATE_ALGO(sha512_256, "SHA512-256", 32)

#endif
