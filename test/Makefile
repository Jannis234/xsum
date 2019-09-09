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

CFLAGS = $(CCFLAGS) -std=c99 -Wall
# --ignore-unknown to skip algorithms that are not compiled in
XSUM = ../xsum --ignore-unknown

# Depend on the last file that make_input creates (in case it aborts early)
INPUT_DEPEND = input/empty

CHECKS = check_adler_32 \
	check_blake2s_128 \
	check_blake2s_160 \
	check_blake2s_224 \
	check_blake2s_256 \
	check_blake2b_128 \
	check_blake2b_136 \
	check_blake2b_144 \
	check_blake2b_152 \
	check_blake2b_160 \
	check_blake2b_168 \
	check_blake2b_176 \
	check_blake2b_184 \
	check_blake2b_192 \
	check_blake2b_200 \
	check_blake2b_208 \
	check_blake2b_216 \
	check_blake2b_224 \
	check_blake2b_232 \
	check_blake2b_240 \
	check_blake2b_248 \
	check_blake2b_256 \
	check_blake2b_264 \
	check_blake2b_272 \
	check_blake2b_280 \
	check_blake2b_288 \
	check_blake2b_296 \
	check_blake2b_304 \
	check_blake2b_312 \
	check_blake2b_320 \
	check_blake2b_328 \
	check_blake2b_336 \
	check_blake2b_344 \
	check_blake2b_352 \
	check_blake2b_360 \
	check_blake2b_368 \
	check_blake2b_376 \
	check_blake2b_384 \
	check_blake2b_392 \
	check_blake2b_400 \
	check_blake2b_408 \
	check_blake2b_416 \
	check_blake2b_424 \
	check_blake2b_432 \
	check_blake2b_440 \
	check_blake2b_448 \
	check_blake2b_456 \
	check_blake2b_464 \
	check_blake2b_472 \
	check_blake2b_480 \
	check_blake2b_488 \
	check_blake2b_496 \
	check_blake2b_504 \
	check_blake2b_512 \
	check_crc32 \
	check_crc64 \
	check_edon_r_256 \
	check_edon_r_512 \
	check_gost94 \
	check_gost94_cryptopro \
	check_has160 \
	check_md2 \
	check_md4 \
	check_md5 \
	check_ripemd160 \
	check_sha1 \
	check_sha224 \
	check_sha256 \
	check_sha384 \
	check_sha512 \
	check_sha512_224 \
	check_sha512_256 \
	check_sha3_224 \
	check_sha3_256 \
	check_sha3_384 \
	check_sha3_512 \
	check_snefru_128 \
	check_snefru_256 \
	check_streebog_256 \
	check_streebog_512

.PHONY: check clean $(CHECKS)

check: $(CHECKS)

$(INPUT_DEPEND): make_input$(EXEEXT)
	mkdir -p input
	./make_input$(EXEEXT)

make_input$(EXEEXT): make_input.c
	$(CC) $(CFLAGS) make_input.c -o make_input$(EXEEXT)

clean:
	rm -rf input
	rm -f make_input$(EXEEXT)

check_adler_32: $(INPUT_DEPEND) data/adler_32.txt
	$(XSUM) -c data/adler_32.txt

check_blake2s_128: $(INPUT_DEPEND) data/blake2s_128.txt
	$(XSUM) -c data/blake2s_128.txt

check_blake2s_160: $(INPUT_DEPEND) data/blake2s_160.txt
	$(XSUM) -c data/blake2s_160.txt

check_blake2s_224: $(INPUT_DEPEND) data/blake2s_224.txt
	$(XSUM) -c data/blake2s_224.txt

check_blake2s_256: $(INPUT_DEPEND) data/blake2s_256.txt
	$(XSUM) -c data/blake2s_256.txt

check_blake2b_128: $(INPUT_DEPEND) data/blake2b_128.txt
	$(XSUM) -c data/blake2b_128.txt

check_blake2b_136: $(INPUT_DEPEND) data/blake2b_136.txt
	$(XSUM) -c data/blake2b_136.txt

check_blake2b_144: $(INPUT_DEPEND) data/blake2b_144.txt
	$(XSUM) -c data/blake2b_144.txt

check_blake2b_152: $(INPUT_DEPEND) data/blake2b_152.txt
	$(XSUM) -c data/blake2b_152.txt

check_blake2b_160: $(INPUT_DEPEND) data/blake2b_160.txt
	$(XSUM) -c data/blake2b_160.txt

check_blake2b_168: $(INPUT_DEPEND) data/blake2b_168.txt
	$(XSUM) -c data/blake2b_168.txt

check_blake2b_176: $(INPUT_DEPEND) data/blake2b_176.txt
	$(XSUM) -c data/blake2b_176.txt

check_blake2b_184: $(INPUT_DEPEND) data/blake2b_184.txt
	$(XSUM) -c data/blake2b_184.txt

check_blake2b_192: $(INPUT_DEPEND) data/blake2b_192.txt
	$(XSUM) -c data/blake2b_192.txt

check_blake2b_200: $(INPUT_DEPEND) data/blake2b_200.txt
	$(XSUM) -c data/blake2b_200.txt

check_blake2b_208: $(INPUT_DEPEND) data/blake2b_208.txt
	$(XSUM) -c data/blake2b_208.txt

check_blake2b_216: $(INPUT_DEPEND) data/blake2b_216.txt
	$(XSUM) -c data/blake2b_216.txt

check_blake2b_224: $(INPUT_DEPEND) data/blake2b_224.txt
	$(XSUM) -c data/blake2b_224.txt

check_blake2b_232: $(INPUT_DEPEND) data/blake2b_232.txt
	$(XSUM) -c data/blake2b_232.txt

check_blake2b_240: $(INPUT_DEPEND) data/blake2b_240.txt
	$(XSUM) -c data/blake2b_240.txt

check_blake2b_248: $(INPUT_DEPEND) data/blake2b_248.txt
	$(XSUM) -c data/blake2b_248.txt

check_blake2b_256: $(INPUT_DEPEND) data/blake2b_256.txt
	$(XSUM) -c data/blake2b_256.txt

check_blake2b_264: $(INPUT_DEPEND) data/blake2b_264.txt
	$(XSUM) -c data/blake2b_264.txt

check_blake2b_272: $(INPUT_DEPEND) data/blake2b_272.txt
	$(XSUM) -c data/blake2b_272.txt

check_blake2b_280: $(INPUT_DEPEND) data/blake2b_280.txt
	$(XSUM) -c data/blake2b_280.txt

check_blake2b_288: $(INPUT_DEPEND) data/blake2b_288.txt
	$(XSUM) -c data/blake2b_288.txt

check_blake2b_296: $(INPUT_DEPEND) data/blake2b_296.txt
	$(XSUM) -c data/blake2b_296.txt

check_blake2b_304: $(INPUT_DEPEND) data/blake2b_304.txt
	$(XSUM) -c data/blake2b_304.txt

check_blake2b_312: $(INPUT_DEPEND) data/blake2b_312.txt
	$(XSUM) -c data/blake2b_312.txt

check_blake2b_320: $(INPUT_DEPEND) data/blake2b_320.txt
	$(XSUM) -c data/blake2b_320.txt

check_blake2b_328: $(INPUT_DEPEND) data/blake2b_328.txt
	$(XSUM) -c data/blake2b_328.txt

check_blake2b_336: $(INPUT_DEPEND) data/blake2b_336.txt
	$(XSUM) -c data/blake2b_336.txt

check_blake2b_344: $(INPUT_DEPEND) data/blake2b_344.txt
	$(XSUM) -c data/blake2b_344.txt

check_blake2b_352: $(INPUT_DEPEND) data/blake2b_352.txt
	$(XSUM) -c data/blake2b_352.txt

check_blake2b_360: $(INPUT_DEPEND) data/blake2b_360.txt
	$(XSUM) -c data/blake2b_360.txt

check_blake2b_368: $(INPUT_DEPEND) data/blake2b_368.txt
	$(XSUM) -c data/blake2b_368.txt

check_blake2b_376: $(INPUT_DEPEND) data/blake2b_376.txt
	$(XSUM) -c data/blake2b_376.txt

check_blake2b_384: $(INPUT_DEPEND) data/blake2b_384.txt
	$(XSUM) -c data/blake2b_384.txt

check_blake2b_392: $(INPUT_DEPEND) data/blake2b_392.txt
	$(XSUM) -c data/blake2b_392.txt

check_blake2b_400: $(INPUT_DEPEND) data/blake2b_400.txt
	$(XSUM) -c data/blake2b_400.txt

check_blake2b_408: $(INPUT_DEPEND) data/blake2b_408.txt
	$(XSUM) -c data/blake2b_408.txt

check_blake2b_416: $(INPUT_DEPEND) data/blake2b_416.txt
	$(XSUM) -c data/blake2b_416.txt

check_blake2b_424: $(INPUT_DEPEND) data/blake2b_424.txt
	$(XSUM) -c data/blake2b_424.txt

check_blake2b_432: $(INPUT_DEPEND) data/blake2b_432.txt
	$(XSUM) -c data/blake2b_432.txt

check_blake2b_440: $(INPUT_DEPEND) data/blake2b_440.txt
	$(XSUM) -c data/blake2b_440.txt

check_blake2b_448: $(INPUT_DEPEND) data/blake2b_448.txt
	$(XSUM) -c data/blake2b_448.txt

check_blake2b_456: $(INPUT_DEPEND) data/blake2b_456.txt
	$(XSUM) -c data/blake2b_456.txt

check_blake2b_464: $(INPUT_DEPEND) data/blake2b_464.txt
	$(XSUM) -c data/blake2b_464.txt

check_blake2b_472: $(INPUT_DEPEND) data/blake2b_472.txt
	$(XSUM) -c data/blake2b_472.txt

check_blake2b_480: $(INPUT_DEPEND) data/blake2b_480.txt
	$(XSUM) -c data/blake2b_480.txt

check_blake2b_488: $(INPUT_DEPEND) data/blake2b_488.txt
	$(XSUM) -c data/blake2b_488.txt

check_blake2b_496: $(INPUT_DEPEND) data/blake2b_496.txt
	$(XSUM) -c data/blake2b_496.txt

check_blake2b_504: $(INPUT_DEPEND) data/blake2b_504.txt
	$(XSUM) -c data/blake2b_504.txt

check_blake2b_512: $(INPUT_DEPEND) data/blake2b_512.txt
	$(XSUM) -c data/blake2b_512.txt

check_crc32: $(INPUT_DEPEND) data/crc32.txt
	$(XSUM) -c data/crc32.txt

check_crc64: $(INPUT_DEPEND) data/crc64.txt
	$(XSUM) -c data/crc64.txt

check_edon_r_256: $(INPUT_DEPEND) data/edon_r_256.txt
	$(XSUM) -c data/edon_r_256.txt

check_edon_r_512: $(INPUT_DEPEND) data/edon_r_512.txt
	$(XSUM) -c data/edon_r_512.txt

check_gost94: $(INPUT_DEPEND) data/gost94.txt
	$(XSUM) -c data/gost94.txt

check_gost94_cryptopro: $(INPUT_DEPEND) data/gost94_cryptopro.txt
	$(XSUM) -c data/gost94_cryptopro.txt

check_has160: $(INPUT_DEPEND) data/has160.txt
	$(XSUM) -c data/has160.txt

check_md2: $(INPUT_DEPEND) data/md2.txt
	$(XSUM) -c data/md2.txt

check_md4: $(INPUT_DEPEND) data/md4.txt
	$(XSUM) -c data/md4.txt

check_md5: $(INPUT_DEPEND) data/md5.txt
	$(XSUM) -c data/md5.txt

check_ripemd160: $(INPUT_DEPEND) data/ripemd160.txt
	$(XSUM) -c data/ripemd160.txt

check_sha1: $(INPUT_DEPEND) data/sha1.txt
	$(XSUM) -c data/sha1.txt

check_sha224: $(INPUT_DEPEND) data/sha224.txt
	$(XSUM) -c data/sha224.txt

check_sha256: $(INPUT_DEPEND) data/sha256.txt
	$(XSUM) -c data/sha256.txt

check_sha384: $(INPUT_DEPEND) data/sha384.txt
	$(XSUM) -c data/sha384.txt

check_sha512: $(INPUT_DEPEND) data/sha512.txt
	$(XSUM) -c data/sha512.txt

check_sha512_224: $(INPUT_DEPEND) data/sha512_224.txt
	$(XSUM) -c data/sha512_224.txt

check_sha512_256: $(INPUT_DEPEND) data/sha512_256.txt
	$(XSUM) -c data/sha512_256.txt

check_sha3_224: $(INPUT_DEPEND) data/sha3_224.txt
	$(XSUM) -c data/sha3_224.txt

check_sha3_256: $(INPUT_DEPEND) data/sha3_256.txt
	$(XSUM) -c data/sha3_256.txt

check_sha3_384: $(INPUT_DEPEND) data/sha3_384.txt
	$(XSUM) -c data/sha3_384.txt

check_sha3_512: $(INPUT_DEPEND) data/sha3_512.txt
	$(XSUM) -c data/sha3_512.txt

check_snefru_128: $(INPUT_DEPEND) data/snefru_128.txt
	$(XSUM) -c data/snefru_128.txt

check_snefru_256: $(INPUT_DEPEND) data/snefru_256.txt
	$(XSUM) -c data/snefru_256.txt

check_streebog_256: $(INPUT_DEPEND) data/streebog_256.txt
	$(XSUM) -c data/streebog_256.txt

check_streebog_512: $(INPUT_DEPEND) data/streebog_512.txt
	$(XSUM) -c data/streebog_512.txt

check_sum: $(INPUT_DEPEND) data/sum.txt
	$(XSUM) -c data/sum.txt

check_tiger: $(INPUT_DEPEND) data/tiger.txt
	$(XSUM) -c data/tiger.txt

check_tiger2: $(INPUT_DEPEND) data/tiger2.txt
	$(XSUM) -c data/tiger2.txt

check_whirlpool: $(INPUT_DEPEND) data/whirlpool.txt
	$(XSUM) -c data/whirlpool.txt

check_xor: $(INPUT_DEPEND) data/xor.txt
	$(XSUM) -c data/xor.txt
