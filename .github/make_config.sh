#!/bin/bash
# Generate config_build.mak for use with github actions

if [ ! "$1" ]; then
	echo "Missing argument: library"
	exit 1
fi

echo "XSUM_VERSION = git-\$(shell git rev-parse --short HEAD)"
echo "WITH_OPENMP = 1"
echo "WITH_WINDOWS_CNG = 0"

for i in botan2:WITH_BOTAN \
	cppcrypto:WITH_CPPCRYPTO \
	cryptopp:WITH_CRYPTOPP \
	glib:WITH_GLIB \
	gnutls:WITH_GNUTLS \
	mbedtls:WITH_MBEDTLS \
	mhash:WITH_MHASH \
	nettle:WITH_NETTLE \
	nss:WITH_NSS \
	libb2:WITH_LIBB2 \
	libgcrypt:WITH_LIBGCRYPT \
	liblzma:WITH_LIBLZMA \
	libsodium:WITH_LIBSODIUM \
	openssl:WITH_OPENSSL \
	rhash:WITH_RHASH \
	xxhash:WITH_XXHASH \
	zlib:WITH_ZLIB; do
	if [ "$1" == "${i%:*}" ]; then
		echo "${i#*:} = 1"
	else
		echo "${i#*:} = 0"
	fi
done
