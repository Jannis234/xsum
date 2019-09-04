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
Adler-32 | [zlib](https://www.zlib.net/) |
BLAKE2b-160 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-256 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-384 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-512 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2b-X | [libsodium](https://download.libsodium.org/doc/) | Supported sizes are 128, 136, 144, ..., 512. Some are also supported by libgcrypt (see above).
BLAKE2s-128 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-160 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-224 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
BLAKE2s-256 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/)¹ |
CRC32 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [liblzma](https://tukaani.org/xz/) [rhash](http://rhash.sourceforge.net/) [zlib](https://www.zlib.net/) | CRC32 as specified by ISO 3309
CRC64 | [liblzma](https://tukaani.org/xz/) | CRC64 as specified by ECMA-182
EDON-R-256 | [rhash](http://rhash.sourceforge.net/) |
EDON-R-512 | [rhash](http://rhash.sourceforge.net/) |
GOST94 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) | GOST R 34.11-94
GOST94-CryptoPro | [rhash](http://rhash.sourceforge.net/) | GOST94 with CryptoPro S-box
HAS160 | [rhash](http://rhash.sourceforge.net/) |
MD2 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) |
MD4 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
MD5 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
RIPEMD160 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA1 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
SHA224 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
SHA256 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) [rhash](http://rhash.sourceforge.net/) |
SHA384 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
SHA512 | [mbedtls](https://tls.mbed.org/)³ [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) [rhash](http://rhash.sourceforge.net/) |
SHA512-224 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) |
SHA512-256 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) |
SHA3-224 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
SHA3-256 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
SHA3-384 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
SHA3-512 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html)² [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
Snefru-128 | [rhash](http://rhash.sourceforge.net/) |
Snefru-256 | [rhash](http://rhash.sourceforge.net/) |
Streebog-256 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | GOST R 34.11-2012
Streebog-512 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | GOST R 34.11-2012
Sum | (Built in) | 64-bit sum of all input bytes
Tiger | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
Tiger2 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
WHIRLPOOL | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [rhash](http://rhash.sourceforge.net/) |
XOR | (Built in) | XOR of all input bytes

¹) libgcrypt 1.8.0 or higher required for BLAKE2

²) Nettle 3.2 or higher required for SHA-3

³) mbedtls might not have all possible algorithms compiled in, this is auto-detected at build time

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
