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
#ifdef XSUM_HAS_GOST94_CRYPTOPRO

#include "algo_template.h"

#if defined(XSUM_WITH_RHASH)

#include <rhash.h>
XSUM_TEMPLATE_RHASH(gost94_cryptopro, RHASH_GOST_CRYPTOPRO, 32)

#elif defined(XSUM_WITH_GNUTLS)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(gost94_cryptopro, GNUTLS_DIG_GOSTR_94, 32)

#elif defined(XSUM_WITH_BOTAN_GOST94)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(gost94_cryptopro, "GOST-34.11", 32)

#elif defined(XSUM_WITH_OPENSSL_GOST94)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(gost94_cryptopro, gostr341194, 32)

#endif

XSUM_TEMPLATE_ALGO(gost94_cryptopro, "GOST94-CryptoPro", 32)

#endif
