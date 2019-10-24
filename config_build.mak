# This file is part of xsum
#
# xsum is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# xsum is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with xsum. If not, see <http://www.gnu.org/licenses/>.

XSUM_VERSION = git-$(shell git rev-parse --short HEAD)

# Enable multithreading on a compiler that supports OpenMP
WITH_OPENMP = 1

# External libraries containing that actual hashes
WITH_BOTAN = 1
WITH_CRYPTOPP = 1
WITH_GLIB = 1
WITH_GNUTLS = 1
WITH_MBEDTLS = 1
WITH_MHASH = 1
WITH_NETTLE = 1
WITH_NSS = 1
WITH_LIBB2 = 1
WITH_LIBGCRYPT = 1
WITH_LIBLZMA = 1
WITH_LIBSODIUM = 1
# Potential license conflict, see README.md
WITH_OPENSSL = 0
WITH_RHASH = 1
WITH_XXHASH = 1
WITH_ZLIB = 1

# Enable on windows to use the windows API for hashing
WITH_WINDOWS_CNG = 0
