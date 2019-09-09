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
#ifdef XSUM_HAS_BLAKE2SP_FULL

#include "algo_template.h"

#if defined(XSUM_WITH_LIBB2)

#include <blake2.h>
XSUM_TEMPLATE_LIBB2(blake2sp_8, blake2sp, 1)
XSUM_TEMPLATE_LIBB2(blake2sp_16, blake2sp, 2)
XSUM_TEMPLATE_LIBB2(blake2sp_24, blake2sp, 3)
XSUM_TEMPLATE_LIBB2(blake2sp_32, blake2sp, 4)
XSUM_TEMPLATE_LIBB2(blake2sp_40, blake2sp, 5)
XSUM_TEMPLATE_LIBB2(blake2sp_48, blake2sp, 6)
XSUM_TEMPLATE_LIBB2(blake2sp_56, blake2sp, 7)
XSUM_TEMPLATE_LIBB2(blake2sp_64, blake2sp, 8)
XSUM_TEMPLATE_LIBB2(blake2sp_72, blake2sp, 9)
XSUM_TEMPLATE_LIBB2(blake2sp_80, blake2sp, 10)
XSUM_TEMPLATE_LIBB2(blake2sp_88, blake2sp, 11)
XSUM_TEMPLATE_LIBB2(blake2sp_96, blake2sp, 12)
XSUM_TEMPLATE_LIBB2(blake2sp_104, blake2sp, 13)
XSUM_TEMPLATE_LIBB2(blake2sp_112, blake2sp, 14)
XSUM_TEMPLATE_LIBB2(blake2sp_120, blake2sp, 15)
XSUM_TEMPLATE_LIBB2(blake2sp_128, blake2sp, 16)
XSUM_TEMPLATE_LIBB2(blake2sp_136, blake2sp, 17)
XSUM_TEMPLATE_LIBB2(blake2sp_144, blake2sp, 18)
XSUM_TEMPLATE_LIBB2(blake2sp_152, blake2sp, 19)
XSUM_TEMPLATE_LIBB2(blake2sp_160, blake2sp, 20)
XSUM_TEMPLATE_LIBB2(blake2sp_168, blake2sp, 21)
XSUM_TEMPLATE_LIBB2(blake2sp_176, blake2sp, 22)
XSUM_TEMPLATE_LIBB2(blake2sp_184, blake2sp, 23)
XSUM_TEMPLATE_LIBB2(blake2sp_192, blake2sp, 24)
XSUM_TEMPLATE_LIBB2(blake2sp_200, blake2sp, 25)
XSUM_TEMPLATE_LIBB2(blake2sp_208, blake2sp, 26)
XSUM_TEMPLATE_LIBB2(blake2sp_216, blake2sp, 27)
XSUM_TEMPLATE_LIBB2(blake2sp_224, blake2sp, 28)
XSUM_TEMPLATE_LIBB2(blake2sp_232, blake2sp, 29)
XSUM_TEMPLATE_LIBB2(blake2sp_240, blake2sp, 30)
XSUM_TEMPLATE_LIBB2(blake2sp_248, blake2sp, 31)
XSUM_TEMPLATE_LIBB2(blake2sp_256, blake2sp, 32)

#endif

XSUM_TEMPLATE_ALGO(blake2sp_8, "BLAKE2sp-8", 1)
XSUM_TEMPLATE_ALGO(blake2sp_16, "BLAKE2sp-16", 2)
XSUM_TEMPLATE_ALGO(blake2sp_24, "BLAKE2sp-24", 3)
XSUM_TEMPLATE_ALGO(blake2sp_32, "BLAKE2sp-32", 4)
XSUM_TEMPLATE_ALGO(blake2sp_40, "BLAKE2sp-40", 5)
XSUM_TEMPLATE_ALGO(blake2sp_48, "BLAKE2sp-48", 6)
XSUM_TEMPLATE_ALGO(blake2sp_56, "BLAKE2sp-56", 7)
XSUM_TEMPLATE_ALGO(blake2sp_64, "BLAKE2sp-64", 8)
XSUM_TEMPLATE_ALGO(blake2sp_72, "BLAKE2sp-72", 9)
XSUM_TEMPLATE_ALGO(blake2sp_80, "BLAKE2sp-80", 10)
XSUM_TEMPLATE_ALGO(blake2sp_88, "BLAKE2sp-88", 11)
XSUM_TEMPLATE_ALGO(blake2sp_96, "BLAKE2sp-96", 12)
XSUM_TEMPLATE_ALGO(blake2sp_104, "BLAKE2sp-104", 13)
XSUM_TEMPLATE_ALGO(blake2sp_112, "BLAKE2sp-112", 14)
XSUM_TEMPLATE_ALGO(blake2sp_120, "BLAKE2sp-120", 15)
XSUM_TEMPLATE_ALGO(blake2sp_128, "BLAKE2sp-128", 16)
XSUM_TEMPLATE_ALGO(blake2sp_136, "BLAKE2sp-136", 17)
XSUM_TEMPLATE_ALGO(blake2sp_144, "BLAKE2sp-144", 18)
XSUM_TEMPLATE_ALGO(blake2sp_152, "BLAKE2sp-152", 19)
XSUM_TEMPLATE_ALGO(blake2sp_160, "BLAKE2sp-160", 20)
XSUM_TEMPLATE_ALGO(blake2sp_168, "BLAKE2sp-168", 21)
XSUM_TEMPLATE_ALGO(blake2sp_176, "BLAKE2sp-176", 22)
XSUM_TEMPLATE_ALGO(blake2sp_184, "BLAKE2sp-184", 23)
XSUM_TEMPLATE_ALGO(blake2sp_192, "BLAKE2sp-192", 24)
XSUM_TEMPLATE_ALGO(blake2sp_200, "BLAKE2sp-200", 25)
XSUM_TEMPLATE_ALGO(blake2sp_208, "BLAKE2sp-208", 26)
XSUM_TEMPLATE_ALGO(blake2sp_216, "BLAKE2sp-216", 27)
XSUM_TEMPLATE_ALGO(blake2sp_224, "BLAKE2sp-224", 28)
XSUM_TEMPLATE_ALGO(blake2sp_232, "BLAKE2sp-232", 29)
XSUM_TEMPLATE_ALGO(blake2sp_240, "BLAKE2sp-240", 30)
XSUM_TEMPLATE_ALGO(blake2sp_248, "BLAKE2sp-248", 31)
XSUM_TEMPLATE_ALGO(blake2sp_256, "BLAKE2sp-256", 32)

#endif
