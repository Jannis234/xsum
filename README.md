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
BLAKE2b-160 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2b-256 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2b-384 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2b-512 | [libsodium](https://download.libsodium.org/doc/) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2b-X | [libsodium](https://download.libsodium.org/doc/) | Supported sizes are 128, 136, 144, ..., 512. Some are also supported by libgcrypt (see above).
BLAKE2s-128 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2s-160 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2s-224 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
BLAKE2s-256 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
CRC32 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [liblzma](https://tukaani.org/xz/) [zlib](https://www.zlib.net/) | CRC32 as specified by ISO 3309
CRC64 | [liblzma](https://tukaani.org/xz/) | CRC64 as specified by ECMA-182
GOST94 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | GOST R 34.11-94
MD2 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) |
MD4 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
MD5 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
RIPEMD160 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA1 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA224 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA256 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) |
SHA384 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA512 | [mbedtls](https://tls.mbed.org/) [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) [libsodium](https://download.libsodium.org/doc/) |
SHA512-224 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) |
SHA512-256 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) |
SHA3-224 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA3-256 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA3-384 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
SHA3-512 | [nettle](https://www.lysator.liu.se/~nisse/nettle/nettle.html) [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
Streebog-256 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | GOST R 34.11-2012
Streebog-512 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) | GOST R 34.11-2012
Sum | (Built in) | 64-bit sum of all input bytes
Tiger | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
Tiger2 | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
WHIRLPOOL | [libgcrypt](https://www.gnupg.org/related_software/libgcrypt/) |
XOR | (Built in) | XOR of all input bytes

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
