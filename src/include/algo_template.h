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

#ifndef __XSUM_ALGO_TEMPLATE_H__
#define __XSUM_ALGO_TEMPLATE_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "algos.h"

// Common template for the global per-algo struct
// Parameters: xsum-internal name; Hash name string (for CLI); hash size
#define XSUM_TEMPLATE_ALGO(p_name, p_name_string, p_size) \
	xsum_algo_t xsum_algo_##p_name = { p_name_string, p_size, &xsum_##p_name##_init, &xsum_##p_name##_update, &xsum_##p_name##_final };

// Common template for mbedtls hashes
// Parameters: xsum-internal name; mbedtls constant; hash size
#define XSUM_TEMPLATE_MBEDTLS(p_name_xsum, p_name_mbedtls, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		mbedtls_md_context_t *ctx = malloc(sizeof(mbedtls_md_context_t)); \
		if (ctx == NULL) { \
			return NULL; \
		} \
		mbedtls_md_init(ctx); \
		const mbedtls_md_info_t *info = mbedtls_md_info_from_type(p_name_mbedtls); \
		if (info == NULL) { \
			free(ctx); \
			return NULL; \
		} \
		if (mbedtls_md_setup(ctx, info, 0) != 0) { \
			free(ctx); \
			return NULL; \
		} \
		mbedtls_md_starts(ctx); \
		return ctx; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		mbedtls_md_context_t *ctx = (mbedtls_md_context_t*) state; \
		mbedtls_md_update(ctx, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		mbedtls_md_context_t *ctx = (mbedtls_md_context_t*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			mbedtls_md_free(ctx); \
			free(ctx); \
			return NULL; \
		} \
		mbedtls_md_finish(ctx, out); \
		mbedtls_md_free(ctx); \
		free(ctx); \
		return out; \
	}

// Common template for nettle hashes
// Parameters: xsum-internal name; nettle-internal name; hash size
#define XSUM_TEMPLATE_NETTLE(p_name_xsum, p_name_nettle, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		struct p_name_nettle##_ctx *state = malloc(sizeof(struct p_name_nettle##_ctx)); \
		if (state == NULL) { \
			return NULL; \
		} \
		p_name_nettle##_init(state); \
		return state; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		struct p_name_nettle##_ctx *ctx = (struct p_name_nettle##_ctx*) state; \
		p_name_nettle##_update(ctx, len, buf); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		struct p_name_nettle##_ctx *ctx = (struct p_name_nettle##_ctx*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			free(ctx); \
			return NULL; \
		} \
		p_name_nettle##_digest(ctx, p_size, out); \
		free(ctx); \
		return out; \
	}

// Common template for libgcrypt hashes
// Parameters: xsum-internal name; libgcrypt constant; hash size
#define XSUM_TEMPLATE_LIBGCRYPT(p_name_xsum, p_name_gcrypt, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		gcry_md_hd_t *hd = malloc(sizeof(gcry_md_hd_t)); \
		if (hd == NULL) { \
			return NULL; \
		} \
		gcry_md_open(hd, p_name_gcrypt, 0); \
		if (*hd == NULL) { \
			free(hd); \
			return NULL; \
		} \
		return hd; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		gcry_md_hd_t *hd = (gcry_md_hd_t*) state; \
		gcry_md_write(*hd, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		gcry_md_hd_t *hd = (gcry_md_hd_t*) state; \
		unsigned char *out = gcry_md_read(*hd, 0); \
		uint8_t *out2 = malloc(p_size); \
		if (out2 == NULL) { \
			gcry_md_close(*hd); \
			free(hd); \
			return NULL; \
		} \
		memcpy(out2, out, p_size); \
		gcry_md_close(*hd); \
		free(hd); \
		return out2; \
	}

// Common template for CRC with liblzma
// Parameters: CRC size (bits)
#define XSUM_TEMPLATE_LIBLZMA_CRC(p_size) \
	void* xsum_crc##p_size##_init() { \
		uint##p_size##_t *crc = malloc(p_size / 8); \
		if (crc == NULL) { \
			return NULL; \
		} \
		*crc = 0; \
		return crc; \
	} \
	void xsum_crc##p_size##_update(void *state, uint8_t *buf, size_t len) { \
		uint##p_size##_t *crc = (uint##p_size##_t*) state; \
		*crc = lzma_crc##p_size(buf, len, *crc); \
	} \
	uint8_t* xsum_crc##p_size##_final(void *state) { \
		uint##p_size##_t *crc = (uint##p_size##_t*) state; \
		*crc = xsum_endian##p_size(*crc); \
		return (uint8_t*) crc; \
	}

// Common template for BLAKE2B with libsodium
// Parameters: hash name; hash size
#define XSUM_TEMPLATE_LIBSODIUM_BLAKE2B(p_name, p_size) \
	void* xsum_##p_name##_init() { \
		crypto_generichash_blake2b_state *s = malloc(sizeof(crypto_generichash_blake2b_state)); \
		if (s == NULL) { \
			return NULL; \
		} \
		crypto_generichash_blake2b_init(s, NULL, 0, p_size); \
		return s; \
	} \
	void xsum_##p_name##_update(void *state, uint8_t *buf, size_t len) { \
		crypto_generichash_blake2b_state *s = (crypto_generichash_blake2b_state*) state; \
		crypto_generichash_blake2b_update(s, buf, len); \
	} \
	uint8_t* xsum_##p_name##_final(void *state) { \
		crypto_generichash_blake2b_state *s = (crypto_generichash_blake2b_state*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			free(s); \
			return NULL; \
		} \
		crypto_generichash_blake2b_final(s, out, p_size); \
		free(s); \
		return out; \
	}

// Common template for SHA256/SHA512 with libsodium
// Parameters: hash name; hash size
#define XSUM_TEMPLATE_LIBSODIUM_SHA(p_name, p_size) \
	void* xsum_##p_name##_init() { \
		crypto_hash_##p_name##_state *s = malloc(sizeof(crypto_hash_##p_name##_state)); \
		if (s == NULL) { \
			return NULL; \
		} \
		crypto_hash_##p_name##_init(s); \
		return s; \
	} \
	void xsum_##p_name##_update(void *state, uint8_t *buf, size_t len) { \
		crypto_hash_##p_name##_state *s = (crypto_hash_##p_name##_state*) state; \
		crypto_hash_##p_name##_update(s, buf, len); \
	} \
	uint8_t* xsum_##p_name##_final(void *state) { \
		crypto_hash_##p_name##_state *s = (crypto_hash_##p_name##_state*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			free(s); \
			return NULL; \
		} \
		crypto_hash_##p_name##_final(s, out); \
		free(s); \
		return out; \
	}

// Common template for rhash hashes
// Parameters: xsum-internal name; rhash constant; hash size
#define XSUM_TEMPLATE_RHASH(p_name_xsum, p_name_rhash, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		rhash ctx = rhash_init(p_name_rhash); \
		if (ctx == NULL) { \
			return NULL; \
		} \
		return ctx; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		rhash ctx = (rhash) state; \
		rhash_update(ctx, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		rhash ctx = (rhash) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			rhash_free(ctx); \
			return NULL; \
		} \
		rhash_final(ctx, out); \
		rhash_free(ctx); \
		return out; \
	}

#endif
