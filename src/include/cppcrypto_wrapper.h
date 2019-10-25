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

#ifndef __CPPCRYPTO_WRAPPER_H__
#define __CPPCRYPTO_WRAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define XSUM_CPPCRYPTO_WRAPPER_H(name) \
	void* xsum_cppcrypto_##name##_init(); \
	void xsum_cppcrypto_##name##_update(void* state, uint8_t *buf, size_t len); \
	void xsum_cppcrypto_##name##_final(void* state, uint8_t *out); \
	void xsum_cppcrypto_##name##_free(void* state);
#define XSUM_CPPCRYPTO_WRAPPER_SIZE_H(name) \
	void* xsum_cppcrypto_##name##_init(size_t size); \
	void xsum_cppcrypto_##name##_update(void* state, uint8_t *buf, size_t len); \
	void xsum_cppcrypto_##name##_final(void* state, uint8_t *out); \
	void xsum_cppcrypto_##name##_free(void* state);

XSUM_CPPCRYPTO_WRAPPER_SIZE_H(blake)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(blake2b)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(blake2s)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(groestl)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(jh)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(kupyna)
XSUM_CPPCRYPTO_WRAPPER_H(md5)
XSUM_CPPCRYPTO_WRAPPER_H(sha1)
XSUM_CPPCRYPTO_WRAPPER_H(sha224)
XSUM_CPPCRYPTO_WRAPPER_H(sha256)
XSUM_CPPCRYPTO_WRAPPER_H(sha384)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(sha512)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(sha3)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(skein256)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(skein512)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(skein1024)
XSUM_CPPCRYPTO_WRAPPER_H(sm3)
XSUM_CPPCRYPTO_WRAPPER_SIZE_H(streebog)
XSUM_CPPCRYPTO_WRAPPER_H(whirlpool)

#ifdef __cplusplus
}
#endif

#endif
