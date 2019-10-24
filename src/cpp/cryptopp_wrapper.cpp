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
#include <cryptopp/sha.h>
#include "cryptopp_wrapper.h"

#define XSUM_CRYPTOPP_WRAPPER(name) \
	void* xsum_cryptopp_##name##_new() { \
		return new(std::nothrow) CryptoPP::name(); \
	} \
	void xsum_cryptopp_##name##_update(void* state, uint8_t *data, size_t len) { \
		CryptoPP::name* s = static_cast<CryptoPP::name*>(state); \
		s->Update(data, len); \
	} \
	void xsum_cryptopp_##name##_final(void* state, uint8_t *out) { \
		CryptoPP::name* s = static_cast<CryptoPP::name*>(state); \
		s->Final(out); \
	} \
	void xsum_cryptopp_##name##_free(void *state) { \
		CryptoPP::name* s = static_cast<CryptoPP::name*>(state); \
		delete s; \
	}

XSUM_CRYPTOPP_WRAPPER(SHA256)

#endif
