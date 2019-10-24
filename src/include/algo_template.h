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

// Common template for botan hashes
// Parameters: xsum-internal name; botan hash name string; hash size
#define XSUM_TEMPLATE_BOTAN(p_name_xsum, p_name_botan, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		botan_hash_t h; \
		if (botan_hash_init(&h, p_name_botan, 0) != BOTAN_FFI_SUCCESS) { \
			return NULL; \
		} \
		return h; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		botan_hash_t h = (botan_hash_t) state; \
		botan_hash_update(h, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		botan_hash_t h = (botan_hash_t) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			botan_hash_destroy(h); \
			return NULL; \
		} \
		botan_hash_final(h, out); \
		botan_hash_destroy(h); \
		return out; \
	}

// Common template for crypto++ hashes using the C wrapper
// Parameters: xsum-internal name, crypto++ class name, hash size
#define XSUM_TEMPLATE_CRYPTOPP(p_name_xsum, p_name_cryptopp, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		return xsum_cryptopp_##p_name_cryptopp##_new(); \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		xsum_cryptopp_##p_name_cryptopp##_update(state, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			xsum_cryptopp_##p_name_cryptopp##_free(state); \
			return NULL; \
		} \
		xsum_cryptopp_##p_name_cryptopp##_final(state, out); \
		xsum_cryptopp_##p_name_cryptopp##_free(state); \
		return out; \
	}

// Common template for glib hashes
// Parameters: xsum-internal name; glib constant; hash size
#define XSUM_TEMPLATE_GLIB(p_name_xsum, p_name_glib, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		GChecksum *gc = g_checksum_new(p_name_glib); \
		if (gc == NULL) { \
			return NULL; \
		} \
		return gc; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		GChecksum *gc = (GChecksum*) state; \
		g_checksum_update(gc, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		GChecksum *gc = (GChecksum*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			g_checksum_free(gc); \
			return NULL; \
		} \
		gsize len = p_size; \
		g_checksum_get_digest(gc, out, &len); \
		g_checksum_free(gc); \
		return out; \
	}

// Common template for gnutls hashes
// Parameters: xsum-internal name; gnutls constant; hash size
#define XSUM_TEMPLATE_GNUTLS(p_name_xsum, p_name_gnutls, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		gnutls_hash_hd_t hd; \
		if (gnutls_hash_init(&hd, p_name_gnutls) != 0) { \
			return NULL; \
		} \
		return hd; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		gnutls_hash_hd_t hd = (gnutls_hash_hd_t) state; \
		gnutls_hash(hd, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		gnutls_hash_hd_t hd = (gnutls_hash_hd_t) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			gnutls_hash_deinit(hd, NULL); \
			return NULL; \
		} \
		gnutls_hash_deinit(hd, out); \
		return out; \
	}

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

// Common template for mhash hashes
// Parameters: xsum-internal name; mhash constant; hash size
#define XSUM_TEMPLATE_MHASH(p_name_xsum, p_name_mhash, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		MHASH ctx = mhash_init(p_name_mhash); \
		if (ctx == MHASH_FAILED) { \
			return NULL; \
		} \
		return ctx; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		MHASH ctx = (MHASH) state; \
		mhash(ctx, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		MHASH ctx = (MHASH) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			mhash_deinit(ctx, NULL); \
			return NULL; \
		} \
		mhash_deinit(ctx, out); \
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

// Common template for NSS hashes
// Parameters: xsum-internal name; NSS OID tag; hash size
#define XSUM_TEMPLATE_NSS(p_name_xsum, p_name_nss, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		HASHContext *ctx = HASH_Create(HASH_GetHashTypeByOidTag(p_name_nss)); \
		if (ctx == NULL) { \
			return NULL; \
		} \
		HASH_Begin(ctx); \
		return ctx; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		HASHContext *ctx = (HASHContext*) state; \
		HASH_Update(ctx, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		HASHContext *ctx = (HASHContext*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			HASH_Destroy(ctx); \
			return NULL; \
		} \
		unsigned int len_out; /* Dummy */ \
		HASH_End(ctx, out, &len_out, p_size); \
		HASH_Destroy(ctx); \
		return out; \
	}

// Common template for BLAKE2 using libb2
// Parameters: xsum-internal name; BLAKE2 algorithm; hash size
#define XSUM_TEMPLATE_LIBB2(p_name_xsum, p_name_b2, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		p_name_b2##_state *s = malloc(sizeof(p_name_b2##_state)); \
		if (s == NULL) { \
			return NULL; \
		} \
		p_name_b2##_init(s, p_size); \
		return s; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		p_name_b2##_state *s = (p_name_b2##_state*) state; \
		p_name_b2##_update(s, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		p_name_b2##_state *s = (p_name_b2##_state*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			free(s); \
			return NULL; \
		} \
		p_name_b2##_final(s, out, p_size); \
		free(s); \
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

// Common template for openssl hashes
// Parameters: xsum-internal name; openssl EVP name; hash size
#define XSUM_TEMPLATE_OPENSSL(p_name_xsum, p_name_openssl, p_size) \
	void* xsum_##p_name_xsum##_init() { \
		EVP_MD_CTX *ctx = EVP_MD_CTX_create(); \
		if (ctx == NULL) { \
			return NULL; \
		} \
		if (EVP_DigestInit_ex(ctx, EVP_##p_name_openssl(), NULL) != 1) { \
			EVP_MD_CTX_destroy(ctx); \
			return NULL; \
		} \
		return ctx; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		EVP_MD_CTX *ctx = (EVP_MD_CTX*) state; \
		EVP_DigestUpdate(ctx, buf, len); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		EVP_MD_CTX *ctx = (EVP_MD_CTX*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			EVP_MD_CTX_destroy(ctx); \
			return NULL; \
		} \
		EVP_DigestFinal_ex(ctx, out, NULL); \
		EVP_MD_CTX_destroy(ctx); \
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

// Template for xxhash
// Parameters: hash size in bits
#define XSUM_TEMPLATE_XXHASH(p_size) \
	void* xsum_xxhash##p_size##_init() { \
		XXH##p_size##_state_t *s = XXH##p_size##_createState(); \
		if (s == NULL) { \
			return NULL; \
		} \
		XXH##p_size##_reset(s, 0); \
		return s; \
	} \
	void xsum_xxhash##p_size##_update(void *state, uint8_t *buf, size_t len) { \
		XXH##p_size##_state_t *s = (XXH##p_size##_state_t*) state; \
		XXH##p_size##_update(s, buf, len); \
	} \
	uint8_t* xsum_xxhash##p_size##_final(void *state) { \
		XXH##p_size##_state_t *s = (XXH##p_size##_state_t*) state; \
		uint8_t *out = malloc(p_size / 8); \
		if (out == NULL) { \
			XXH##p_size##_freeState(s); \
			return NULL; \
		} \
		XXH##p_size##_hash_t hash = XXH##p_size##_digest(s); \
		XXH##p_size##_canonical_t hash_canonical; \
		XXH##p_size##_canonicalFromHash(&hash_canonical, hash); \
		memcpy(out, hash_canonical.digest, p_size / 8); \
		XXH##p_size##_freeState(s); \
		return out; \
	}

// Template for windows CNG hashes
// Parameters: xsum-internal name; CNG constant; hash size
#define XSUM_TEMPLATE_WIN_CNG(p_name_xsum, p_name_bcrypt, p_size) \
	typedef struct { \
		BCRYPT_ALG_HANDLE algo; \
		BCRYPT_HASH_HANDLE hash; \
		void *object; \
	} xsum_win_cng_state_t; \
	void* xsum_##p_name_xsum##_init() { \
		xsum_win_cng_state_t *state = malloc(sizeof(xsum_win_cng_state_t)); \
		if (state == NULL) { \
			return NULL; \
		} \
		if (BCryptOpenAlgorithmProvider(&state->algo, p_name_bcrypt, NULL, 0) != STATUS_SUCCESS) { \
			free(state); \
			return NULL; \
		} \
		size_t object_size = 0; \
		unsigned long dummy; \
		if (BCryptGetProperty(state->algo, BCRYPT_OBJECT_LENGTH, (uint8_t*) object_size, sizeof(size_t), &dummy, 0) != STATUS_SUCCESS) { \
			BCryptCloseAlgorithmProvider(state->algo, 0); \
			free(state); \
			return NULL; \
		} \
		state->object = malloc(object_size); \
		if (state->object == NULL) { \
			BCryptCloseAlgorithmProvider(state->algo, 0); \
			free(state); \
			return NULL; \
		} \
		if (BCryptCreateHash(state->algo, &state->hash, state->object, object_size, NULL, 0, 0) != STATUS_SUCCESS) { \
			BCryptCloseAlgorithmProvider(state->algo, 0); \
			free(state->object); \
			free(state); \
			return NULL; \
		} \
		return state; \
	} \
	void xsum_##p_name_xsum##_update(void *state, uint8_t *buf, size_t len) { \
		xsum_win_cng_state_t *s = (xsum_win_cng_state_t*) state; \
		BCryptHashData(s->hash, buf, len, 0); \
	} \
	uint8_t* xsum_##p_name_xsum##_final(void *state) { \
		xsum_win_cng_state_t *s = (xsum_win_cng_state_t*) state; \
		uint8_t *out = malloc(p_size); \
		if (out == NULL) { \
			BCryptDestroyHash(s->hash); \
			BCryptCloseAlgorithmProvider(s->algo, 0); \
			free(s->object); \
			free(s); \
			return NULL; \
		} \
		BCryptFinishHash(s->hash, out, p_size, 0); \
		BCryptDestroyHash(s->hash); \
		BCryptCloseAlgorithmProvider(s->algo, 0); \
		free(s->object); \
		free(s); \
		return out; \
	}

#endif
