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
#ifdef XSUM_HAS_BLAKE2B_408

#include "algo_template.h"

#if defined(XSUM_WITH_LIBSODIUM)

#include <sodium.h>
XSUM_TEMPLATE_LIBSODIUM_BLAKE2B(blake2b_408, 51)

#endif

XSUM_TEMPLATE_ALGO(blake2b_408, "BLAKE2b-408", 51)

#endif
