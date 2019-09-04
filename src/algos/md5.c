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
#ifdef XSUM_HAS_MD5

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/md5.h>
XSUM_TEMPLATE_NETTLE(md5, md5, 16)

#elif defined(XSUM_WITH_LIBGCRYPT)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(md5, GCRY_MD_MD5, 16)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(md5, MBEDTLS_MD_MD5, 16)

#elif defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(md5, RHASH_MD5, 16)

#endif

XSUM_TEMPLATE_ALGO(md5, "MD5", 16)

#endif
