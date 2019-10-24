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

#ifndef __CRYPTOPP_WRAPPER_H__
#define __CRYPTOPP_WRAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define XSUM_CRYPTOPP_WRAPPER_H(name) \
	void* xsum_cryptopp_##name##_new(); \
	void xsum_cryptopp_##name##_update(void* state, uint8_t *data, size_t len); \
	void xsum_cryptopp_##name##_final(void* state, uint8_t *out); \
	void xsum_cryptopp_##name##_free(void* state);
#define XSUM_CRYPTOPP_WRAPPER_SIZE_H(name) \
	void* xsum_cryptopp_##name##_new(unsigned int size); \
	void xsum_cryptopp_##name##_update(void* state, uint8_t *data, size_t len); \
	void xsum_cryptopp_##name##_final(void* state, uint8_t *out); \
	void xsum_cryptopp_##name##_free(void* state);

XSUM_CRYPTOPP_WRAPPER_H(Adler32)
XSUM_CRYPTOPP_WRAPPER_SIZE_H(BLAKE2s)
XSUM_CRYPTOPP_WRAPPER_SIZE_H(BLAKE2b)
XSUM_CRYPTOPP_WRAPPER_H(CRC32)
XSUM_CRYPTOPP_WRAPPER_H(Keccak_224)
XSUM_CRYPTOPP_WRAPPER_H(Keccak_256)
XSUM_CRYPTOPP_WRAPPER_H(Keccak_384)
XSUM_CRYPTOPP_WRAPPER_H(Keccak_512)
XSUM_CRYPTOPP_WRAPPER_H(MD2)
XSUM_CRYPTOPP_WRAPPER_H(MD4)
XSUM_CRYPTOPP_WRAPPER_H(MD5)
XSUM_CRYPTOPP_WRAPPER_H(RIPEMD128)
XSUM_CRYPTOPP_WRAPPER_H(RIPEMD160)
XSUM_CRYPTOPP_WRAPPER_H(RIPEMD256)
XSUM_CRYPTOPP_WRAPPER_H(RIPEMD320)
XSUM_CRYPTOPP_WRAPPER_H(SHA1)
XSUM_CRYPTOPP_WRAPPER_H(SHA224)
XSUM_CRYPTOPP_WRAPPER_H(SHA256)
XSUM_CRYPTOPP_WRAPPER_H(SHA384)
XSUM_CRYPTOPP_WRAPPER_H(SHA512)
XSUM_CRYPTOPP_WRAPPER_H(SHA3_224)
XSUM_CRYPTOPP_WRAPPER_H(SHA3_256)
XSUM_CRYPTOPP_WRAPPER_H(SHA3_384)
XSUM_CRYPTOPP_WRAPPER_H(SHA3_512)
XSUM_CRYPTOPP_WRAPPER_H(SM3)
XSUM_CRYPTOPP_WRAPPER_H(Tiger)
XSUM_CRYPTOPP_WRAPPER_H(Whirlpool)

int xsum_cryptopp_version_build();
int xsum_cryptopp_version_runtime();

#ifdef __cplusplus
}
#endif

#endif
