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
#ifdef XSUM_HAS_STREEBOG_512

#include "algo_template.h"

#if defined(XSUM_WITH_LIBGCRYPT_STREEBOG)

#include <gcrypt.h>
XSUM_TEMPLATE_LIBGCRYPT(streebog_512, GCRY_MD_STRIBOG512, 64)

#elif defined(XSUM_WITH_GNUTLS_STREEBOG)

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
XSUM_TEMPLATE_GNUTLS(streebog_512, GNUTLS_DIG_STREEBOG_512, 64)

#elif defined(XSUM_WITH_BOTAN_STREEBOG)

#include <botan/ffi.h>
XSUM_TEMPLATE_BOTAN(streebog_512, "Streebog-512", 64)

#elif defined(XSUM_WITH_OPENSSL_SHA1)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(streebog_512, streebog512, 64)

#endif

XSUM_TEMPLATE_ALGO(streebog_512, "Streebog-512", 64)

#endif
