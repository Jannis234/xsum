# xsum

All-in-one utility to calculate and verify checksums

## About

xsum can calculate and verify a variety of different checksums/hashes and use these checksums to verify the integrity of one or multiple file(s), similar to UNIX utilities like md5sum or sha1sum. xsum combines support for multiple external libraries to calculate and compare different checksums at the same time.

## Building

Compiling xsum should be as simple as running `make` and `sudo make install` to install the result.

Check the files `config_build.mak` and `config_system.mak` for any customizable settings.

## Supported checksums

This is a list of all currently supported checksums and the libraries that are required to use them. If one checksum is supported by multiple libraries, only one of them is needed.

Name | Libraries | Comment
--- | --- | ---
Adler-32 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) [zlib](https://www.zlib.net/) |
BLAKE-224 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
BLAKE-256 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
BLAKE-384 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
BLAKE-512 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
BLAKE2b-160 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-256 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-384 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-512 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ [rhash](http://rhash.sourceforge.net/) |
BLAKE2b-X | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) | Supported sizes are 8, 16, 24, ..., 512. Some are also supported by libgcrypt or openssl (see above).
BLAKE2bp-X | [libb2](https://github.com/BLAKE2/libb2) | Supported sizes are 8, 16, 24, ..., 512
BLAKE2s-128 | [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-160 | [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-224 | [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-256 | [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ [rhash](http://rhash.sourceforge.net/) |
BLAKE2s-X | [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [libb2](https://github.com/BLAKE2/libb2) | Supported sizes are 8, 16, 24, ..., 256. Some are also supported by libgcrypt or openssl (see above).
BLAKE2sp-X | [libb2](https://github.com/BLAKE2/libb2) | Supported sizes are 8, 16, 24, ..., 256
CRC24 | [botan2](https://botan.randombit.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | CRC24 as used in OpenPGP
CRC32 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [liblzma](https://tukaani.org/xz/) [rhash](http://rhash.sourceforge.net/) [zlib](https://www.zlib.net/) | CRC32 as specified by ISO 3309
CRC64 | [liblzma](https://tukaani.org/xz/) | CRC64 as specified by ECMA-182
ECHO-X | [cppcrypto](http://cppcrypto.sourceforge.net/) | Supported sizes are 8, 16, 24, ..., 512
EDON-R-256 | [rhash](http://rhash.sourceforge.net/) |
EDON-R-512 | [rhash](http://rhash.sourceforge.net/)¹¹ |
Esch-256 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
Esch-384 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
GOST94 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) | GOST R 34.11-94
GOST94-CryptoPro | [botan2](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ | GOST94 with CryptoPro S-box
Groestl-X | [cppcrypto](http://cppcrypto.sourceforge.net/) | Supported sizes are 8, 16, 24, ..., 512
HAS160 | [rhash](http://rhash.sourceforge.net/) |
HAVAL-128 | [mhash](http://mhash.sourceforge.net/) |
HAVAL-160 | [mhash](http://mhash.sourceforge.net/) |
HAVAL-192 | [mhash](http://mhash.sourceforge.net/) |
HAVAL-224 | [mhash](http://mhash.sourceforge.net/) |
HAVAL-256 | [mhash](http://mhash.sourceforge.net/) |
JH-224 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
JH-256 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
JH-384 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
JH-512 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
Keccak-224 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) | Keccak-f[1600] \(older variant of SHA-3\)
Keccak-256 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) | Keccak-f[1600] \(older variant of SHA-3\)
Keccak-384 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) | Keccak-f[1600] \(older variant of SHA-3\)
Keccak-512 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) | Keccak-f[1600] \(older variant of SHA-3\)
Kupyna-256 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
Kupyna-512 | [cppcrypto](http://cppcrypto.sourceforge.net/) |
LSH-256 | [crypto++](https://www.cryptopp.com/) |
LSH-256-224 | [crypto++](https://www.cryptopp.com/) |
LSH-512 | [crypto++](https://www.cryptopp.com/) |
LSH-512-256 | [crypto++](https://www.cryptopp.com/) |
LSH-512-384 | [crypto++](https://www.cryptopp.com/) |
MD2 | [crypto++](https://www.cryptopp.com/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
MD4 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
MD5 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [glib](https://www.gtk.org/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
MDC2 | [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
RIPEMD128 | [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) |
RIPEMD160 | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [openssl](https://www.openssl.org/)⁵⁶ |
RIPEMD256 | [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) |
RIPEMD320 | [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) |
SHA1 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [glib](https://www.gtk.org/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
SHA224 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ |
SHA256 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [glib](https://www.gtk.org/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
SHA384 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [glib](https://www.gtk.org/)⁹ [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
SHA512 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [glib](https://www.gtk.org/)⁹ [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [mhash](http://mhash.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ Windows⁸ |
SHA512-224 | [cppcrypto](http://cppcrypto.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
SHA512-256 | [cppcrypto](http://cppcrypto.sourceforge.net/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
SHA3-224 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
SHA3-256 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
SHA3-384 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
SHA3-512 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
Skein-256-X | [cppcrypto](http://cppcrypto.sourceforge.net/) | Supported sizes are 8, 16, 24, ..., 256
Skein-512-X | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) | Supported sizes are 8, 16, 24, ..., 512
Skein-1024-X | [cppcrypto](http://cppcrypto.sourceforge.net/) | Supported sizes are 8, 16, 24, ..., 1024
SM3 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [openssl](https://www.openssl.org/)⁵ ⁶ ⁷ |
Snefru-128 | [mhash](http://mhash.sourceforge.net/) [rhash](http://rhash.sourceforge.net/) |
Snefru-256 | [mhash](http://mhash.sourceforge.net/) [rhash](http://rhash.sourceforge.net/) |
Streebog-256 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [gnutls](https://www.gnutls.org/)⁴ [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹² [openssl](https://www.openssl.org/)⁵ ⁶ [rhash](http://rhash.sourceforge.net/) | GOST R 34.11-2012
Streebog-512 | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [gnutls](https://www.gnutls.org/)⁴ [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹² [openssl](https://www.openssl.org/)⁵ ⁶ [rhash](http://rhash.sourceforge.net/) | GOST R 34.11-2012
Sum | (Built in) | 64-bit sum of all input bytes
Tiger | [botan2](https://botan.randombit.net/) [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
Tiger2 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
WHIRLPOOL | [botan2](https://botan.randombit.net/) [cppcrypto](http://cppcrypto.sourceforge.net/) [crypto++](https://www.cryptopp.com/) [mhash](http://mhash.sourceforge.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵ ⁶ |
XOR | (Built in) | XOR of all input bytes
xxHash32 | [xxhash](http://www.xxhash.com/) |
xxHash64 | [xxhash](http://www.xxhash.com/) |
xxHash3-64 | [xxhash](http://www.xxhash.com/)¹⁰ |
xxHash3-128 | [xxhash](http://www.xxhash.com/) ¹⁰ |

¹) libgcrypt 1.8.0 or higher required for BLAKE2

²) Nettle 3.2 or higher required for SHA-3

³) mbedtls might not have all possible algorithms compiled in, this is auto-detected at build time

⁴) Streebog is supported with gnutls 3.6.8 or higher as previous versions produce incorrect hashes

⁵) [libressl](https://www.libressl.org/) is also supported

⁶) Note that before version 3.0, the OpenSSL license was incompatible with xsum's GPLv3.

⁷) BLAKE2 requires OpenSSL 1.1.0 or newer; GOST94 requires OpenSSL before 1.1.0 or LibreSSL; MDC2 is not supported by LibreSSL; SHA512-224, SHA512-256 and SHA3 require OpenSSL 1.1.1 or newer; SM3 requires OpenSSL 1.1.1, LibreSSL 2.9.0 or newer

⁸) xsum supports the Windows CNG API on Windows Vista/Server 2008 or later (build xsum using [MinGW](http://mingw.org/))

⁹) SHA512 required glib 2.36 or newer, SHA384 requires glib 2.51 or newer

¹⁰) xxHash 0.8.0 or higher required for xxHash3

¹¹) rhash version 1.4.0 sometimes produced incorrect EDON-R-512 hashes. xsum 1.3 and higher use a different name (EDON-R-512_) internally, causing hashes produced by older versions to be ignored.

¹²) Streebog is supported with libgcrypt 1.9.0 or higher as previous versions produce incorrect hashes

## Usage examples

Calculate checksums:
```
xsum myfile1.txt myfile2.txt > checksums
```
Verify checksums:
```
xsum -c checksums
```
Select a list of checksums to calculate:
```
xsum -a blake2b-512,md5,sha256,whirlpool myfile.txt
```
For all available options, see:
```
xsum --help
```
