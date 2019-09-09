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
#ifdef XSUM_HAS_BLAKE2S_FULL

#include "algo_template.h"

#if defined(XSUM_WITH_LIBB2)

#include <blake2.h>
XSUM_TEMPLATE_LIBB2(blake2s_8, blake2s, 1)
XSUM_TEMPLATE_LIBB2(blake2s_16, blake2s, 2)
XSUM_TEMPLATE_LIBB2(blake2s_24, blake2s, 3)
XSUM_TEMPLATE_LIBB2(blake2s_32, blake2s, 4)
XSUM_TEMPLATE_LIBB2(blake2s_40, blake2s, 5)
XSUM_TEMPLATE_LIBB2(blake2s_48, blake2s, 6)
XSUM_TEMPLATE_LIBB2(blake2s_56, blake2s, 7)
XSUM_TEMPLATE_LIBB2(blake2s_64, blake2s, 8)
XSUM_TEMPLATE_LIBB2(blake2s_72, blake2s, 9)
XSUM_TEMPLATE_LIBB2(blake2s_80, blake2s, 10)
XSUM_TEMPLATE_LIBB2(blake2s_88, blake2s, 11)
XSUM_TEMPLATE_LIBB2(blake2s_96, blake2s, 12)
XSUM_TEMPLATE_LIBB2(blake2s_104, blake2s, 13)
XSUM_TEMPLATE_LIBB2(blake2s_112, blake2s, 14)
XSUM_TEMPLATE_LIBB2(blake2s_120, blake2s, 15)
// blake2s_128.c
XSUM_TEMPLATE_LIBB2(blake2s_136, blake2s, 17)
XSUM_TEMPLATE_LIBB2(blake2s_144, blake2s, 18)
XSUM_TEMPLATE_LIBB2(blake2s_152, blake2s, 19)
// blake2s_160.c
XSUM_TEMPLATE_LIBB2(blake2s_168, blake2s, 21)
XSUM_TEMPLATE_LIBB2(blake2s_176, blake2s, 22)
XSUM_TEMPLATE_LIBB2(blake2s_184, blake2s, 23)
XSUM_TEMPLATE_LIBB2(blake2s_192, blake2s, 24)
XSUM_TEMPLATE_LIBB2(blake2s_200, blake2s, 25)
XSUM_TEMPLATE_LIBB2(blake2s_208, blake2s, 26)
XSUM_TEMPLATE_LIBB2(blake2s_216, blake2s, 27)
// blake2s_224.c
XSUM_TEMPLATE_LIBB2(blake2s_232, blake2s, 29)
XSUM_TEMPLATE_LIBB2(blake2s_240, blake2s, 30)
XSUM_TEMPLATE_LIBB2(blake2s_248, blake2s, 31)
// blake2s_256.c

#endif

XSUM_TEMPLATE_ALGO(blake2s_8, "BLAKE2s-8", 1)
XSUM_TEMPLATE_ALGO(blake2s_16, "BLAKE2s-16", 2)
XSUM_TEMPLATE_ALGO(blake2s_24, "BLAKE2s-24", 3)
XSUM_TEMPLATE_ALGO(blake2s_32, "BLAKE2s-32", 4)
XSUM_TEMPLATE_ALGO(blake2s_40, "BLAKE2s-40", 5)
XSUM_TEMPLATE_ALGO(blake2s_48, "BLAKE2s-48", 6)
XSUM_TEMPLATE_ALGO(blake2s_56, "BLAKE2s-56", 7)
XSUM_TEMPLATE_ALGO(blake2s_64, "BLAKE2s-64", 8)
XSUM_TEMPLATE_ALGO(blake2s_72, "BLAKE2s-72", 9)
XSUM_TEMPLATE_ALGO(blake2s_80, "BLAKE2s-80", 10)
XSUM_TEMPLATE_ALGO(blake2s_88, "BLAKE2s-88", 11)
XSUM_TEMPLATE_ALGO(blake2s_96, "BLAKE2s-96", 12)
XSUM_TEMPLATE_ALGO(blake2s_104, "BLAKE2s-104", 13)
XSUM_TEMPLATE_ALGO(blake2s_112, "BLAKE2s-112", 14)
XSUM_TEMPLATE_ALGO(blake2s_120, "BLAKE2s-120", 15)
// blake2s_128.c
XSUM_TEMPLATE_ALGO(blake2s_136, "BLAKE2s-136", 17)
XSUM_TEMPLATE_ALGO(blake2s_144, "BLAKE2s-144", 18)
XSUM_TEMPLATE_ALGO(blake2s_152, "BLAKE2s-152", 19)
// blake2s_160.c
XSUM_TEMPLATE_ALGO(blake2s_168, "BLAKE2s-168", 21)
XSUM_TEMPLATE_ALGO(blake2s_176, "BLAKE2s-176", 22)
XSUM_TEMPLATE_ALGO(blake2s_184, "BLAKE2s-184", 23)
XSUM_TEMPLATE_ALGO(blake2s_192, "BLAKE2s-192", 24)
XSUM_TEMPLATE_ALGO(blake2s_200, "BLAKE2s-200", 25)
XSUM_TEMPLATE_ALGO(blake2s_208, "BLAKE2s-208", 26)
XSUM_TEMPLATE_ALGO(blake2s_216, "BLAKE2s-216", 27)
// blake2s_224.c
XSUM_TEMPLATE_ALGO(blake2s_232, "BLAKE2s-232", 29)
XSUM_TEMPLATE_ALGO(blake2s_240, "BLAKE2s-240", 30)
XSUM_TEMPLATE_ALGO(blake2s_248, "BLAKE2s-248", 31)
// blake2s_256.c

#endif
