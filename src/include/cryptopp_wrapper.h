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

XSUM_CRYPTOPP_WRAPPER_H(SHA256)

#ifdef __cplusplus
}
#endif

#endif
