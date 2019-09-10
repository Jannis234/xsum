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

# ===================================================================================================
# Run tests for all possible build configurations/all supported external libraries
# This will run "make clean" and "make" multiple times
# Requires all supported libraries to be installed
# You likely won't need to run this, "make check" is enough to test your current build configuration
# ===================================================================================================

if [ ! -e src/include/xsum.h ]; then
	echo "This script needs to run from the top level directory"
	exit 1
fi

WITH_BOTAN=0
WITH_GNUTLS=0
WITH_MBEDTLS=0
WITH_NETTLE=0
WITH_NSS=0
WITH_LIBB2=0
WITH_LIBGCRYPT=0
WITH_LIBLZMA=0
WITH_LIBSODIUM=0
WITH_RHASH=0
WITH_ZLIB=0

run_test() {
	make clean
	make -j check \
		WITH_BOTAN=$WITH_BOTAN \
		WITH_GNUTLS=$WITH_GNUTLS \
		WITH_MBEDTLS=$WITH_MBEDTLS \
		WITH_NETTLE=$WITH_NETTLE \
		WITH_NSS=$WITH_NSS \
		WITH_LIBB2=$WITH_LIBB2 \
		WITH_LIBGCRYPT=$WITH_LIBGCRYPT \
		WITH_LIBLZMA=$WITH_LIBLZMA \
		WITH_LIBSODIUM=$WITH_LIBSODIUM \
		WITH_RHASH=$WITH_RHASH \
		WITH_ZLIB=$WITH_ZLIB \
		|| exit 1
}

WITH_BOTAN=1
run_test
WITH_BOTAN=0

WITH_GNUTLS=1
run_test
WITH_GNUTLS=0

WITH_MBEDTLS=1
run_test
WITH_MBEDTLS=0

WITH_NETTLE=1
run_test
WITH_NETTLE=0

WITH_NSS=1
run_test
WITH_NSS=0

WITH_LIBB2=1
run_test
WITH_LIBB2=0

WITH_LIBGCRYPT=1
run_test
WITH_LIBGCRYPT=0

WITH_LIBLZMA=1
run_test
WITH_LIBLZMA=0

WITH_LIBSODIUM=1
run_test
WITH_LIBSODIUM=0

WITH_ZLIB=1
run_test
WITH_ZLIB=0

make clean
