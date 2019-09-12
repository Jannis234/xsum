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
#ifdef XSUM_HAS_MDC2

#include "algo_template.h"

#if defined(XSUM_WITH_OPENSSL_MDC2)

#include <openssl/evp.h>
XSUM_TEMPLATE_OPENSSL(mdc2, mdc2, 16)

#endif

XSUM_TEMPLATE_ALGO(mdc2, "MDC2", 16)

#endif