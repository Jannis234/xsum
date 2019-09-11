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
Adler-32 | [botan](https://botan.randombit.net/) [zlib](https://www.zlib.net/) |
BLAKE2b-160 | [botan](https://botan.randombit.net/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-256 | [botan](https://botan.randombit.net/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-384 | [botan](https://botan.randombit.net/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-512 | [botan](https://botan.randombit.net/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ [openssl](https://www.openssl.org/)⁵⁶⁷ |
BLAKE2b-X | [botan](https://botan.randombit.net/) [libb2](https://github.com/BLAKE2/libb2) [libsodium](https://download.libsodium.org/doc/) | Supported sizes are 8, 16, 24, ..., 512. Some are also supported by libgcrypt or openssl (see above).
BLAKE2bp-X | [libb2](https://github.com/BLAKE2/libb2) | Supported sizes are 8, 16, 24, ..., 512
BLAKE2s-128 | [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-160 | [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-224 | [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-256 | [libb2](https://github.com/BLAKE2/libb2) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ [openssl](https://www.openssl.org/)⁵⁶⁷ |
BLAKE2s-X | [libb2](https://github.com/BLAKE2/libb2) | Supported sizes are 8, 16, 24, ..., 256. Some are also supported by libgcrypt or openssl (see above).
BLAKE2sp-X | [libb2](https://github.com/BLAKE2/libb2) | Supported sizes are 8, 16, 24, ..., 256
CRC24 | [botan](https://botan.randombit.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | CRC24 as used in OpenPGP
CRC32 | [botan](https://botan.randombit.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [liblzma](https://tukaani.org/xz/) [rhash](http://rhash.sourceforge.net/) [zlib](https://www.zlib.net/) | CRC32 as specified by ISO 3309
CRC64 | [liblzma](https://tukaani.org/xz/) | CRC64 as specified by ECMA-182
EDON-R-256 | [rhash](http://rhash.sourceforge.net/) |
EDON-R-512 | [rhash](http://rhash.sourceforge.net/) |
GOST94 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) | GOST R 34.11-94
GOST94-CryptoPro | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶⁷ | GOST94 with CryptoPro S-box
HAS160 | [rhash](http://rhash.sourceforge.net/) |
Keccak-224 | [botan](https://botan.randombit.net/) | Keccak-f[1600] \(older variant of SHA-3\)
Keccak-256 | [botan](https://botan.randombit.net/) | Keccak-f[1600] \(older variant of SHA-3\)
Keccak-384 | [botan](https://botan.randombit.net/) | Keccak-f[1600] \(older variant of SHA-3\)
Keccak-512 | [botan](https://botan.randombit.net/) | Keccak-f[1600] \(older variant of SHA-3\)
MD2 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [openssl](https://www.openssl.org/)⁵⁶ |
MD4 | [botan](https://botan.randombit.net/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
MD5 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
MDC2 | [openssl](https://www.openssl.org/)⁵⁶⁷ |
RIPEMD160 | [botan](https://botan.randombit.net/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [openssl](https://www.openssl.org/)⁵⁶ |
SHA1 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
SHA224 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
SHA256 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
SHA384 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
SHA512 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [nss](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
SHA512-224 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [openssl](https://www.openssl.org/)⁵⁶⁷ |
SHA512-256 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [openssl](https://www.openssl.org/)⁵⁶⁷ |
SHA3-224 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶⁷ |
SHA3-256 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶⁷ |
SHA3-384 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶⁷ |
SHA3-512 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶⁷ |
Skein-512-X | [botan](https://botan.randombit.net/) | Supported sizes are 8, 16, 24, ..., 512
SM3 | [botan](https://botan.randombit.net/) [openssl](https://www.openssl.org/)⁵⁶⁷ |
Snefru-128 | [rhash](http://rhash.sourceforge.net/) |
Snefru-256 | [rhash](http://rhash.sourceforge.net/) |
Streebog-256 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/)⁴ [openssl](https://www.openssl.org/)⁵⁶ | GOST R 34.11-2012
Streebog-512 | [botan](https://botan.randombit.net/) [gnutls](https://www.gnutls.org/)⁴ [openssl](https://www.openssl.org/)⁵⁶ | GOST R 34.11-2012
Sum | (Built in) | 64-bit sum of all input bytes
Tiger | [botan](https://botan.randombit.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
Tiger2 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
WHIRLPOOL | [botan](https://botan.randombit.net/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) [openssl](https://www.openssl.org/)⁵⁶ |
XOR | (Built in) | XOR of all input bytes

¹) libgcrypt 1.8.0 or higher required for BLAKE2

²) Nettle 3.2 or higher required for SHA-3

³) mbedtls might not have all possible algorithms compiled in, this is auto-detected at build time

⁴) Streebog is supported with gnutls 3.6.8 or higher as previous versions produce incorrect hashes

⁵) [libressl](https://www.libressl.org/) is also supported

⁶) Note that the OpenSSL license is incompatible with xsum's GPLv3. Because of this, it might not be legal to distribute the xsum binary if OpenSSL support (off by default) is compiled in.

⁷) BLAKE2 requires OpenSSL 1.1.0 or newer; GOST94 requires OpenSSL before 1.1.0 or LibreSSL; MDC2 is not supported by LibreSSL; SHA512-224, SHA512-256 and SHA3 require OpenSSL 1.1.1 or newer; SM3 requires OpenSSL 1.1.1, LibreSSL 2.9.0 or newer

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
