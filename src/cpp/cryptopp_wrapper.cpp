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

#ifdef XSUM_WITH_CRYPTOPP

#include <stddef.h>
#include <stdint.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/cryptlib.h>
#include <cryptopp/adler32.h>
#include <cryptopp/blake2.h>
#include <cryptopp/crc.h>
#include <cryptopp/keccak.h>
#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <cryptopp/md5.h>
#include <cryptopp/ripemd.h>
#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/sm3.h>
#include <cryptopp/tiger.h>
#include <cryptopp/whrlpool.h>
#include "cryptopp_wrapper.h"

#define XSUM_CRYPTOPP_WRAPPER(ns, name) \
	void* xsum_cryptopp_##name##_new() { \
		return new(std::nothrow) ns::name(); \
	} \
	void xsum_cryptopp_##name##_update(void* state, uint8_t *data, size_t len) { \
		ns::name* s = static_cast<ns::name*>(state); \
		s->Update(data, len); \
	} \
	void xsum_cryptopp_##name##_final(void* state, uint8_t *out) { \
		ns::name* s = static_cast<ns::name*>(state); \
		s->Final(out); \
	} \
	void xsum_cryptopp_##name##_free(void *state) { \
		ns::name* s = static_cast<ns::name*>(state); \
		delete s; \
	}
#define XSUM_CRYPTOPP_WRAPPER_SIZE(ns, name) \
	void* xsum_cryptopp_##name##_new(unsigned int size) { \
		return new(std::nothrow) ns::name(size); \
	} \
	void xsum_cryptopp_##name##_update(void* state, uint8_t *data, size_t len) { \
		ns::name* s = static_cast<ns::name*>(state); \
		s->Update(data, len); \
	} \
	void xsum_cryptopp_##name##_final(void* state, uint8_t *out) { \
		ns::name* s = static_cast<ns::name*>(state); \
		s->Final(out); \
	} \
	void xsum_cryptopp_##name##_free(void *state) { \
		ns::name* s = static_cast<ns::name*>(state); \
		delete s; \
	}

XSUM_CRYPTOPP_WRAPPER(CryptoPP, Adler32)
XSUM_CRYPTOPP_WRAPPER_SIZE(CryptoPP, BLAKE2s)
XSUM_CRYPTOPP_WRAPPER_SIZE(CryptoPP, BLAKE2b)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, CRC32)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, Keccak_224)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, Keccak_256)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, Keccak_384)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, Keccak_512)
XSUM_CRYPTOPP_WRAPPER(CryptoPP::Weak, MD2)
XSUM_CRYPTOPP_WRAPPER(CryptoPP::Weak, MD4)
XSUM_CRYPTOPP_WRAPPER(CryptoPP::Weak, MD5)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, RIPEMD128)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, RIPEMD160)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, RIPEMD256)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, RIPEMD320)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA1)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA224)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA256)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA384)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA512)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA3_224)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA3_256)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA3_384)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SHA3_512)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, SM3)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, Tiger)
XSUM_CRYPTOPP_WRAPPER(CryptoPP, Whirlpool)

int xsum_cryptopp_version_build() {
	
	return CryptoPP::HeaderVersion();
	
}

int xsum_cryptopp_version_runtime() {
	
	return CryptoPP::LibraryVersion();
	
}

#endif
