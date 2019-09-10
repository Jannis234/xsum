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

#include "cli.h"
#include "config.h"
#include <stddef.h>
#ifdef XSUM_WITH_NSS
#include <nss.h>
#endif
#ifdef XSUM_WITH_LIBGCRYPT
#include <gcrypt.h>
#endif
#ifdef XSUM_WITH_RHASH
#include <rhash.h>
#endif

#ifdef XSUM_WITH_NSS
void xsum_exit_nss() {
	
	NSS_Shutdown();
	
}
#endif

int xsum_lib_init() {
	
#ifdef XSUM_WITH_NSS
	NSS_NoDB_Init(NULL);
	atexit(&xsum_exit_nss);
#endif
#ifdef XSUM_WITH_LIBGCRYPT
	if (!gcry_check_version(XSUM_LIBGCRYPT_MIN_VERSION)) {
		fprintf(stderr, "The loaded version of libgcrypt is too old!\nPlease install at least version %s or re-compile xsum without libgcrypt support.\n", XSUM_LIBGCRYPT_MIN_VERSION);
		return RETURN_ERROR;
	}
#endif
#ifdef XSUM_WITH_RHASH
	rhash_library_init();
#endif
	return RETURN_OK;
	
}
