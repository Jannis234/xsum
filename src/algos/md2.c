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
#ifdef XSUM_HAS_MD2

#include "algo_template.h"

#if defined(XSUM_WITH_NETTLE)

#include <nettle/md2.h>
XSUM_TEMPLATE_NETTLE(md2, md2, 16)

#elif defined(XSUM_WITH_MBEDTLS)

#include <mbedtls/md.h>
XSUM_TEMPLATE_MBEDTLS(md2, MBEDTLS_MD_MD2, 16)

#elif defined(XSUM_WITH_NSS)

#include <sechash.h>
#include <secoidt.h>
XSUM_TEMPLATE_NSS(md2, SEC_OID_MD2, 16);

#elif defined(XSUM_WITH_OPENSSL_MD2)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(md2, md2, 16)

#elif defined(XSUM_WITH_MHASH_MD2)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(md2, MHASH_MD2, 16)

#elif defined(XSUM_WITH_WIN_CNG)

#include <windows.h>
#include <bcrypt.h>
#include <ntstatus.h>
XSUM_TEMPLATE_WIN_CNG(md2, BCRYPT_MD2_ALGORITHM, 16)

#endif

XSUM_TEMPLATE_ALGO(md2, "MD2", 16)

#endif
