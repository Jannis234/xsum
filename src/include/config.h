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

#ifndef __XSUM_CONFIG_H__
#define __XSUM_CONFIG_H__

#include "config_generated.h"

#if (XSUM_CONFIG_NETTLE == 1)
#define XSUM_WITH_NETTLE
#include <nettle/sha3.h>
#ifdef NETTLE_SHA3_FIPS202
#define XSUM_WITH_NETTLE_SHA3
#endif
#endif

#if (XSUM_CONFIG_LIBGCRYPT == 1)
#define XSUM_WITH_LIBGCRYPT
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2S_128
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2S_160
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2S_224
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2S_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2B_160
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2B_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2B_384
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_BLAKE2B_512
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_GOST94
#endif

#if defined(XSUM_WITH_NETTLE)
#define XSUM_HAS_MD2
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_MD4
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_MD5
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_RIPEMD160
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA1
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA224
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA256
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA384
#endif

#if defined(XSUM_WITH_NETTLE) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA512
#endif

#if defined(XSUM_WITH_NETTLE)
#define XSUM_HAS_SHA512_224
#endif

#if defined(XSUM_WITH_NETTLE)
#define XSUM_HAS_SHA512_256
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA3_224
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA3_256
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA3_384
#endif

#if defined(XSUM_WITH_NETTLE_SHA3) || defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_SHA3_512
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_STREEBOG_256
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_STREEBOG_512
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_TIGER
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_TIGER2
#endif

#if defined(XSUM_WITH_LIBGCRYPT)
#define XSUM_HAS_WHIRLPOOL
#endif

#endif
