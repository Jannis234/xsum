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
#ifdef XSUM_HAS_HAVAL_160

#include "algo_template.h"

#if defined(XSUM_WITH_MHASH_HAVAL)

#include <mhash.h>
XSUM_TEMPLATE_MHASH(haval_160, MHASH_HAVAL160, 20)

#endif

XSUM_TEMPLATE_ALGO(haval_160, "HAVAL-160", 20)

#endif
