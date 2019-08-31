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

#include <stddef.h>
#include "algos.h"
#include "config.h"

xsum_algo_t *xsum_algos[] = {
#ifdef XSUM_HAS_GOST94
	&xsum_algo_gost94,
#endif
#ifdef XSUM_HAS_MD2
	&xsum_algo_md2,
#endif
#ifdef XSUM_HAS_MD4
	&xsum_algo_md4,
#endif
#ifdef XSUM_HAS_MD5
	&xsum_algo_md5,
#endif
#ifdef XSUM_HAS_RIPEMD160
	&xsum_algo_ripemd160,
#endif
#ifdef XSUM_HAS_SHA1
	&xsum_algo_sha1,
#endif
#ifdef XSUM_HAS_SHA224
	&xsum_algo_sha224,
#endif
#ifdef XSUM_HAS_SHA256
	&xsum_algo_sha256,
#endif
#ifdef XSUM_HAS_SHA384
	&xsum_algo_sha384,
#endif
#ifdef XSUM_HAS_SHA512
	&xsum_algo_sha512,
#endif
#ifdef XSUM_HAS_SHA512_224
	&xsum_algo_sha512_224,
#endif
#ifdef XSUM_HAS_SHA512_256
	&xsum_algo_sha512_256,
#endif
#ifdef XSUM_HAS_SHA3_224
	&xsum_algo_sha3_224,
#endif
#ifdef XSUM_HAS_SHA3_256
	&xsum_algo_sha3_256,
#endif
#ifdef XSUM_HAS_SHA3_384
	&xsum_algo_sha3_384,
#endif
#ifdef XSUM_HAS_SHA3_512
	&xsum_algo_sha3_512,
#endif
	NULL // End of array indicator
};
