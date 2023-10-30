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

#ifdef XSUM_WITH_CPPCRYPTO

#include <stddef.h>
#include <stdint.h>
#include <cppcrypto/blake.h>
#include <cppcrypto/blake2.h>
#include <cppcrypto/echo.h>
#include <cppcrypto/esch.h>
#include <cppcrypto/groestl.h>
#include <cppcrypto/jh.h>
#include <cppcrypto/kupyna.h>
#include <cppcrypto/md5.h>
#include <cppcrypto/sha1.h>
#include <cppcrypto/sha256.h>
#include <cppcrypto/sha512.h>
#include <cppcrypto/sha3.h>
#include <cppcrypto/skein256.h>
#include <cppcrypto/skein512.h>
#include <cppcrypto/skein1024.h>
#include <cppcrypto/sm3.h>
#include <cppcrypto/streebog.h>
#include <cppcrypto/whirlpool.h>
#include "cppcrypto_wrapper.h"

#define XSUM_CPPCRYPTO_WRAPPER(name) \
	void* xsum_cppcrypto_##name##_init() { \
		cppcrypto::name *s = new(std::nothrow) cppcrypto::name(); \
		if (s != NULL) { \
			s->init(); \
		} \
		return s; \
	} \
	void xsum_cppcrypto_##name##_update(void *state, uint8_t *buf, size_t len) { \
		cppcrypto::name *s = static_cast<cppcrypto::name*>(state); \
		s->update(buf, len); \
	} \
	void xsum_cppcrypto_##name##_final(void *state, uint8_t *out) { \
		cppcrypto::name *s = static_cast<cppcrypto::name*>(state); \
		s->final(out); \
	} \
	void xsum_cppcrypto_##name##_free(void *state) { \
		cppcrypto::name *s = static_cast<cppcrypto::name*>(state); \
		delete s; \
	}
#define XSUM_CPPCRYPTO_WRAPPER_SIZE(name) \
	void* xsum_cppcrypto_##name##_init(size_t size) { \
		cppcrypto::name *s = new(std::nothrow) cppcrypto::name(size); \
		if (s != NULL) { \
			s->init(); \
		} \
		return s; \
	} \
	void xsum_cppcrypto_##name##_update(void *state, uint8_t *buf, size_t len) { \
		cppcrypto::name *s = static_cast<cppcrypto::name*>(state); \
		s->update(buf, len); \
	} \
	void xsum_cppcrypto_##name##_final(void *state, uint8_t *out) { \
		cppcrypto::name *s = static_cast<cppcrypto::name*>(state); \
		s->final(out); \
	} \
	void xsum_cppcrypto_##name##_free(void *state) { \
		cppcrypto::name *s = static_cast<cppcrypto::name*>(state); \
		delete s; \
	}

XSUM_CPPCRYPTO_WRAPPER_SIZE(blake)
XSUM_CPPCRYPTO_WRAPPER_SIZE(blake2b)
XSUM_CPPCRYPTO_WRAPPER_SIZE(blake2s)
XSUM_CPPCRYPTO_WRAPPER_SIZE(echo)
XSUM_CPPCRYPTO_WRAPPER_SIZE(esch)
XSUM_CPPCRYPTO_WRAPPER_SIZE(groestl)
XSUM_CPPCRYPTO_WRAPPER_SIZE(jh)
XSUM_CPPCRYPTO_WRAPPER_SIZE(kupyna)
XSUM_CPPCRYPTO_WRAPPER(md5)
XSUM_CPPCRYPTO_WRAPPER(sha1)
XSUM_CPPCRYPTO_WRAPPER(sha224)
XSUM_CPPCRYPTO_WRAPPER(sha256)
XSUM_CPPCRYPTO_WRAPPER(sha384)
XSUM_CPPCRYPTO_WRAPPER_SIZE(sha512)
XSUM_CPPCRYPTO_WRAPPER_SIZE(sha3)
XSUM_CPPCRYPTO_WRAPPER_SIZE(skein256)
XSUM_CPPCRYPTO_WRAPPER_SIZE(skein512)
XSUM_CPPCRYPTO_WRAPPER_SIZE(skein1024)
XSUM_CPPCRYPTO_WRAPPER(sm3)
XSUM_CPPCRYPTO_WRAPPER_SIZE(streebog)
XSUM_CPPCRYPTO_WRAPPER(whirlpool)

#endif
