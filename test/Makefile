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
	check_blake2s_8 check_blake2s_16 check_blake2s_24 check_blake2s_32 check_blake2s_40 check_blake2s_48 check_blake2s_56 check_blake2s_64 check_blake2s_72 check_blake2s_80 check_blake2s_88 check_blake2s_96 check_blake2s_104 check_blake2s_112 check_blake2s_120 check_blake2s_128 check_blake2s_136 check_blake2s_144 check_blake2s_152 check_blake2s_160 check_blake2s_168 check_blake2s_176 check_blake2s_184 check_blake2s_192 check_blake2s_200 check_blake2s_208 check_blake2s_216 check_blake2s_224 check_blake2s_232 check_blake2s_240 check_blake2s_248 check_blake2s_256 \
	check_blake2sp_8 check_blake2sp_16 check_blake2sp_24 check_blake2sp_32 check_blake2sp_40 check_blake2sp_48 check_blake2sp_56 check_blake2sp_64 check_blake2sp_72 check_blake2sp_80 check_blake2sp_88 check_blake2sp_96 check_blake2sp_104 check_blake2sp_112 check_blake2sp_120 check_blake2sp_128 check_blake2sp_136 check_blake2sp_144 check_blake2sp_152 check_blake2sp_160 check_blake2sp_168 check_blake2sp_176 check_blake2sp_184 check_blake2sp_192 check_blake2sp_200 check_blake2sp_208 check_blake2sp_216 check_blake2sp_224 check_blake2sp_232 check_blake2sp_240 check_blake2sp_248 check_blake2sp_256 \
	check_blake2b_8 check_blake2b_16 check_blake2b_24 check_blake2b_32 check_blake2b_40 check_blake2b_48 check_blake2b_56 check_blake2b_64 check_blake2b_72 check_blake2b_80 check_blake2b_88 check_blake2b_96 check_blake2b_104 check_blake2b_112 check_blake2b_120 check_blake2b_128 check_blake2b_136 check_blake2b_144 check_blake2b_152 check_blake2b_160 check_blake2b_168 check_blake2b_176 check_blake2b_184 check_blake2b_192 check_blake2b_200 check_blake2b_208 check_blake2b_216 check_blake2b_224 check_blake2b_232 check_blake2b_240 check_blake2b_248 check_blake2b_256 check_blake2b_264 check_blake2b_272 check_blake2b_280 check_blake2b_288 check_blake2b_296 check_blake2b_304 check_blake2b_312 check_blake2b_320 check_blake2b_328 check_blake2b_336 check_blake2b_344 check_blake2b_352 check_blake2b_360 check_blake2b_368 check_blake2b_376 check_blake2b_384 check_blake2b_392 check_blake2b_400 check_blake2b_408 check_blake2b_416 check_blake2b_424 check_blake2b_432 check_blake2b_440 check_blake2b_448 check_blake2b_456 check_blake2b_464 check_blake2b_472 check_blake2b_480 check_blake2b_488 check_blake2b_496 check_blake2b_504 check_blake2b_512 \
	check_blake2bp_8 check_blake2bp_16 check_blake2bp_24 check_blake2bp_32 check_blake2bp_40 check_blake2bp_48 check_blake2bp_56 check_blake2bp_64 check_blake2bp_72 check_blake2bp_80 check_blake2bp_88 check_blake2bp_96 check_blake2bp_104 check_blake2bp_112 check_blake2bp_120 check_blake2bp_128 check_blake2bp_136 check_blake2bp_144 check_blake2bp_152 check_blake2bp_160 check_blake2bp_168 check_blake2bp_176 check_blake2bp_184 check_blake2bp_192 check_blake2bp_200 check_blake2bp_208 check_blake2bp_216 check_blake2bp_224 check_blake2bp_232 check_blake2bp_240 check_blake2bp_248 check_blake2bp_256 check_blake2bp_264 check_blake2bp_272 check_blake2bp_280 check_blake2bp_288 check_blake2bp_296 check_blake2bp_304 check_blake2bp_312 check_blake2bp_320 check_blake2bp_328 check_blake2bp_336 check_blake2bp_344 check_blake2bp_352 check_blake2bp_360 check_blake2bp_368 check_blake2bp_376 check_blake2bp_384 check_blake2bp_392 check_blake2bp_400 check_blake2bp_408 check_blake2bp_416 check_blake2bp_424 check_blake2bp_432 check_blake2bp_440 check_blake2bp_448 check_blake2bp_456 check_blake2bp_464 check_blake2bp_472 check_blake2bp_480 check_blake2bp_488 check_blake2bp_496 check_blake2bp_504 check_blake2bp_512 \
	check_crc24 check_crc32 check_crc64 \
	check_edon_r_256 check_edon_r_512 \
	check_gost94 check_gost94_cryptopro \
	check_has160 \
	check_haval_128 check_haval_160 check_haval_192 check_haval_224 check_haval_256 \
	check_md2 \
	check_md4 \
	check_md5 \
	check_mdc2 \
	check_keccak_224 check_keccak_256 check_keccak_384 check_keccak_512 \
	check_ripemd128 check_ripemd160 check_ripemd256 check_ripemd320 \
	check_sha1 \
	check_sha224 check_sha256 check_sha384 check_sha512 check_sha512_224 check_sha512_256 \
	check_sha3_224 check_sha3_256 check_sha3_384 check_sha3_512 \
	check_skein_512_8 check_skein_512_16 check_skein_512_24 check_skein_512_32 check_skein_512_40 check_skein_512_48 check_skein_512_56 check_skein_512_64 check_skein_512_72 check_skein_512_80 check_skein_512_88 check_skein_512_96 check_skein_512_104 check_skein_512_112 check_skein_512_120 check_skein_512_128 check_skein_512_136 check_skein_512_144 check_skein_512_152 check_skein_512_160 check_skein_512_168 check_skein_512_176 check_skein_512_184 check_skein_512_192 check_skein_512_200 check_skein_512_208 check_skein_512_216 check_skein_512_224 check_skein_512_232 check_skein_512_240 check_skein_512_248 check_skein_512_256 check_skein_512_264 check_skein_512_272 check_skein_512_280 check_skein_512_288 check_skein_512_296 check_skein_512_304 check_skein_512_312 check_skein_512_320 check_skein_512_328 check_skein_512_336 check_skein_512_344 check_skein_512_352 check_skein_512_360 check_skein_512_368 check_skein_512_376 check_skein_512_384 check_skein_512_392 check_skein_512_400 check_skein_512_408 check_skein_512_416 check_skein_512_424 check_skein_512_432 check_skein_512_440 check_skein_512_448 check_skein_512_456 check_skein_512_464 check_skein_512_472 check_skein_512_480 check_skein_512_488 check_skein_512_496 check_skein_512_504 check_skein_512_512 \
	check_sm3 \
	check_snefru_128 check_snefru_256 \
	check_streebog_256 check_streebog_512

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

check_blake2s_8: $(INPUT_DEPEND) data/blake2s_8.txt
	$(XSUM) -c data/blake2s_8.txt

check_blake2s_16: $(INPUT_DEPEND) data/blake2s_16.txt
	$(XSUM) -c data/blake2s_16.txt

check_blake2s_24: $(INPUT_DEPEND) data/blake2s_24.txt
	$(XSUM) -c data/blake2s_24.txt

check_blake2s_32: $(INPUT_DEPEND) data/blake2s_32.txt
	$(XSUM) -c data/blake2s_32.txt

check_blake2s_40: $(INPUT_DEPEND) data/blake2s_40.txt
	$(XSUM) -c data/blake2s_40.txt

check_blake2s_48: $(INPUT_DEPEND) data/blake2s_48.txt
	$(XSUM) -c data/blake2s_48.txt

check_blake2s_56: $(INPUT_DEPEND) data/blake2s_56.txt
	$(XSUM) -c data/blake2s_56.txt

check_blake2s_64: $(INPUT_DEPEND) data/blake2s_64.txt
	$(XSUM) -c data/blake2s_64.txt

check_blake2s_72: $(INPUT_DEPEND) data/blake2s_72.txt
	$(XSUM) -c data/blake2s_72.txt

check_blake2s_80: $(INPUT_DEPEND) data/blake2s_80.txt
	$(XSUM) -c data/blake2s_80.txt

check_blake2s_88: $(INPUT_DEPEND) data/blake2s_88.txt
	$(XSUM) -c data/blake2s_88.txt

check_blake2s_96: $(INPUT_DEPEND) data/blake2s_96.txt
	$(XSUM) -c data/blake2s_96.txt

check_blake2s_104: $(INPUT_DEPEND) data/blake2s_104.txt
	$(XSUM) -c data/blake2s_104.txt

check_blake2s_112: $(INPUT_DEPEND) data/blake2s_112.txt
	$(XSUM) -c data/blake2s_112.txt

check_blake2s_120: $(INPUT_DEPEND) data/blake2s_120.txt
	$(XSUM) -c data/blake2s_120.txt

check_blake2s_128: $(INPUT_DEPEND) data/blake2s_128.txt
	$(XSUM) -c data/blake2s_128.txt

check_blake2s_136: $(INPUT_DEPEND) data/blake2s_136.txt
	$(XSUM) -c data/blake2s_136.txt

check_blake2s_144: $(INPUT_DEPEND) data/blake2s_144.txt
	$(XSUM) -c data/blake2s_144.txt

check_blake2s_152: $(INPUT_DEPEND) data/blake2s_152.txt
	$(XSUM) -c data/blake2s_152.txt

check_blake2s_160: $(INPUT_DEPEND) data/blake2s_160.txt
	$(XSUM) -c data/blake2s_160.txt

check_blake2s_168: $(INPUT_DEPEND) data/blake2s_168.txt
	$(XSUM) -c data/blake2s_168.txt

check_blake2s_176: $(INPUT_DEPEND) data/blake2s_176.txt
	$(XSUM) -c data/blake2s_176.txt

check_blake2s_184: $(INPUT_DEPEND) data/blake2s_184.txt
	$(XSUM) -c data/blake2s_184.txt

check_blake2s_192: $(INPUT_DEPEND) data/blake2s_192.txt
	$(XSUM) -c data/blake2s_192.txt

check_blake2s_200: $(INPUT_DEPEND) data/blake2s_200.txt
	$(XSUM) -c data/blake2s_200.txt

check_blake2s_208: $(INPUT_DEPEND) data/blake2s_208.txt
	$(XSUM) -c data/blake2s_208.txt

check_blake2s_216: $(INPUT_DEPEND) data/blake2s_216.txt
	$(XSUM) -c data/blake2s_216.txt

check_blake2s_224: $(INPUT_DEPEND) data/blake2s_224.txt
	$(XSUM) -c data/blake2s_224.txt

check_blake2s_232: $(INPUT_DEPEND) data/blake2s_232.txt
	$(XSUM) -c data/blake2s_232.txt

check_blake2s_240: $(INPUT_DEPEND) data/blake2s_240.txt
	$(XSUM) -c data/blake2s_240.txt

check_blake2s_248: $(INPUT_DEPEND) data/blake2s_248.txt
	$(XSUM) -c data/blake2s_248.txt

check_blake2s_256: $(INPUT_DEPEND) data/blake2s_256.txt
	$(XSUM) -c data/blake2s_256.txt

check_blake2sp_8: $(INPUT_DEPEND) data/blake2sp_8.txt
	$(XSUM) -c data/blake2sp_8.txt

check_blake2sp_16: $(INPUT_DEPEND) data/blake2sp_16.txt
	$(XSUM) -c data/blake2sp_16.txt

check_blake2sp_24: $(INPUT_DEPEND) data/blake2sp_24.txt
	$(XSUM) -c data/blake2sp_24.txt

check_blake2sp_32: $(INPUT_DEPEND) data/blake2sp_32.txt
	$(XSUM) -c data/blake2sp_32.txt

check_blake2sp_40: $(INPUT_DEPEND) data/blake2sp_40.txt
	$(XSUM) -c data/blake2sp_40.txt

check_blake2sp_48: $(INPUT_DEPEND) data/blake2sp_48.txt
	$(XSUM) -c data/blake2sp_48.txt

check_blake2sp_56: $(INPUT_DEPEND) data/blake2sp_56.txt
	$(XSUM) -c data/blake2sp_56.txt

check_blake2sp_64: $(INPUT_DEPEND) data/blake2sp_64.txt
	$(XSUM) -c data/blake2sp_64.txt

check_blake2sp_72: $(INPUT_DEPEND) data/blake2sp_72.txt
	$(XSUM) -c data/blake2sp_72.txt

check_blake2sp_80: $(INPUT_DEPEND) data/blake2sp_80.txt
	$(XSUM) -c data/blake2sp_80.txt

check_blake2sp_88: $(INPUT_DEPEND) data/blake2sp_88.txt
	$(XSUM) -c data/blake2sp_88.txt

check_blake2sp_96: $(INPUT_DEPEND) data/blake2sp_96.txt
	$(XSUM) -c data/blake2sp_96.txt

check_blake2sp_104: $(INPUT_DEPEND) data/blake2sp_104.txt
	$(XSUM) -c data/blake2sp_104.txt

check_blake2sp_112: $(INPUT_DEPEND) data/blake2sp_112.txt
	$(XSUM) -c data/blake2sp_112.txt

check_blake2sp_120: $(INPUT_DEPEND) data/blake2sp_120.txt
	$(XSUM) -c data/blake2sp_120.txt

check_blake2sp_128: $(INPUT_DEPEND) data/blake2sp_128.txt
	$(XSUM) -c data/blake2sp_128.txt

check_blake2sp_136: $(INPUT_DEPEND) data/blake2sp_136.txt
	$(XSUM) -c data/blake2sp_136.txt

check_blake2sp_144: $(INPUT_DEPEND) data/blake2sp_144.txt
	$(XSUM) -c data/blake2sp_144.txt

check_blake2sp_152: $(INPUT_DEPEND) data/blake2sp_152.txt
	$(XSUM) -c data/blake2sp_152.txt

check_blake2sp_160: $(INPUT_DEPEND) data/blake2sp_160.txt
	$(XSUM) -c data/blake2sp_160.txt

check_blake2sp_168: $(INPUT_DEPEND) data/blake2sp_168.txt
	$(XSUM) -c data/blake2sp_168.txt

check_blake2sp_176: $(INPUT_DEPEND) data/blake2sp_176.txt
	$(XSUM) -c data/blake2sp_176.txt

check_blake2sp_184: $(INPUT_DEPEND) data/blake2sp_184.txt
	$(XSUM) -c data/blake2sp_184.txt

check_blake2sp_192: $(INPUT_DEPEND) data/blake2sp_192.txt
	$(XSUM) -c data/blake2sp_192.txt

check_blake2sp_200: $(INPUT_DEPEND) data/blake2sp_200.txt
	$(XSUM) -c data/blake2sp_200.txt

check_blake2sp_208: $(INPUT_DEPEND) data/blake2sp_208.txt
	$(XSUM) -c data/blake2sp_208.txt

check_blake2sp_216: $(INPUT_DEPEND) data/blake2sp_216.txt
	$(XSUM) -c data/blake2sp_216.txt

check_blake2sp_224: $(INPUT_DEPEND) data/blake2sp_224.txt
	$(XSUM) -c data/blake2sp_224.txt

check_blake2sp_232: $(INPUT_DEPEND) data/blake2sp_232.txt
	$(XSUM) -c data/blake2sp_232.txt

check_blake2sp_240: $(INPUT_DEPEND) data/blake2sp_240.txt
	$(XSUM) -c data/blake2sp_240.txt

check_blake2sp_248: $(INPUT_DEPEND) data/blake2sp_248.txt
	$(XSUM) -c data/blake2sp_248.txt

check_blake2sp_256: $(INPUT_DEPEND) data/blake2sp_256.txt
	$(XSUM) -c data/blake2sp_256.txt

check_blake2b_8: $(INPUT_DEPEND) data/blake2b_8.txt
	$(XSUM) -c data/blake2b_8.txt

check_blake2b_16: $(INPUT_DEPEND) data/blake2b_16.txt
	$(XSUM) -c data/blake2b_16.txt

check_blake2b_24: $(INPUT_DEPEND) data/blake2b_24.txt
	$(XSUM) -c data/blake2b_24.txt

check_blake2b_32: $(INPUT_DEPEND) data/blake2b_32.txt
	$(XSUM) -c data/blake2b_32.txt

check_blake2b_40: $(INPUT_DEPEND) data/blake2b_40.txt
	$(XSUM) -c data/blake2b_40.txt

check_blake2b_48: $(INPUT_DEPEND) data/blake2b_48.txt
	$(XSUM) -c data/blake2b_48.txt

check_blake2b_56: $(INPUT_DEPEND) data/blake2b_56.txt
	$(XSUM) -c data/blake2b_56.txt

check_blake2b_64: $(INPUT_DEPEND) data/blake2b_64.txt
	$(XSUM) -c data/blake2b_64.txt

check_blake2b_72: $(INPUT_DEPEND) data/blake2b_72.txt
	$(XSUM) -c data/blake2b_72.txt

check_blake2b_80: $(INPUT_DEPEND) data/blake2b_80.txt
	$(XSUM) -c data/blake2b_80.txt

check_blake2b_88: $(INPUT_DEPEND) data/blake2b_88.txt
	$(XSUM) -c data/blake2b_88.txt

check_blake2b_96: $(INPUT_DEPEND) data/blake2b_96.txt
	$(XSUM) -c data/blake2b_96.txt

check_blake2b_104: $(INPUT_DEPEND) data/blake2b_104.txt
	$(XSUM) -c data/blake2b_104.txt

check_blake2b_112: $(INPUT_DEPEND) data/blake2b_112.txt
	$(XSUM) -c data/blake2b_112.txt

check_blake2b_120: $(INPUT_DEPEND) data/blake2b_120.txt
	$(XSUM) -c data/blake2b_120.txt

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

check_blake2bp_8: $(INPUT_DEPEND) data/blake2bp_8.txt
	$(XSUM) -c data/blake2bp_8.txt

check_blake2bp_16: $(INPUT_DEPEND) data/blake2bp_16.txt
	$(XSUM) -c data/blake2bp_16.txt

check_blake2bp_24: $(INPUT_DEPEND) data/blake2bp_24.txt
	$(XSUM) -c data/blake2bp_24.txt

check_blake2bp_32: $(INPUT_DEPEND) data/blake2bp_32.txt
	$(XSUM) -c data/blake2bp_32.txt

check_blake2bp_40: $(INPUT_DEPEND) data/blake2bp_40.txt
	$(XSUM) -c data/blake2bp_40.txt

check_blake2bp_48: $(INPUT_DEPEND) data/blake2bp_48.txt
	$(XSUM) -c data/blake2bp_48.txt

check_blake2bp_56: $(INPUT_DEPEND) data/blake2bp_56.txt
	$(XSUM) -c data/blake2bp_56.txt

check_blake2bp_64: $(INPUT_DEPEND) data/blake2bp_64.txt
	$(XSUM) -c data/blake2bp_64.txt

check_blake2bp_72: $(INPUT_DEPEND) data/blake2bp_72.txt
	$(XSUM) -c data/blake2bp_72.txt

check_blake2bp_80: $(INPUT_DEPEND) data/blake2bp_80.txt
	$(XSUM) -c data/blake2bp_80.txt

check_blake2bp_88: $(INPUT_DEPEND) data/blake2bp_88.txt
	$(XSUM) -c data/blake2bp_88.txt

check_blake2bp_96: $(INPUT_DEPEND) data/blake2bp_96.txt
	$(XSUM) -c data/blake2bp_96.txt

check_blake2bp_104: $(INPUT_DEPEND) data/blake2bp_104.txt
	$(XSUM) -c data/blake2bp_104.txt

check_blake2bp_112: $(INPUT_DEPEND) data/blake2bp_112.txt
	$(XSUM) -c data/blake2bp_112.txt

check_blake2bp_120: $(INPUT_DEPEND) data/blake2bp_120.txt
	$(XSUM) -c data/blake2bp_120.txt

check_blake2bp_128: $(INPUT_DEPEND) data/blake2bp_128.txt
	$(XSUM) -c data/blake2bp_128.txt

check_blake2bp_136: $(INPUT_DEPEND) data/blake2bp_136.txt
	$(XSUM) -c data/blake2bp_136.txt

check_blake2bp_144: $(INPUT_DEPEND) data/blake2bp_144.txt
	$(XSUM) -c data/blake2bp_144.txt

check_blake2bp_152: $(INPUT_DEPEND) data/blake2bp_152.txt
	$(XSUM) -c data/blake2bp_152.txt

check_blake2bp_160: $(INPUT_DEPEND) data/blake2bp_160.txt
	$(XSUM) -c data/blake2bp_160.txt

check_blake2bp_168: $(INPUT_DEPEND) data/blake2bp_168.txt
	$(XSUM) -c data/blake2bp_168.txt

check_blake2bp_176: $(INPUT_DEPEND) data/blake2bp_176.txt
	$(XSUM) -c data/blake2bp_176.txt

check_blake2bp_184: $(INPUT_DEPEND) data/blake2bp_184.txt
	$(XSUM) -c data/blake2bp_184.txt

check_blake2bp_192: $(INPUT_DEPEND) data/blake2bp_192.txt
	$(XSUM) -c data/blake2bp_192.txt

check_blake2bp_200: $(INPUT_DEPEND) data/blake2bp_200.txt
	$(XSUM) -c data/blake2bp_200.txt

check_blake2bp_208: $(INPUT_DEPEND) data/blake2bp_208.txt
	$(XSUM) -c data/blake2bp_208.txt

check_blake2bp_216: $(INPUT_DEPEND) data/blake2bp_216.txt
	$(XSUM) -c data/blake2bp_216.txt

check_blake2bp_224: $(INPUT_DEPEND) data/blake2bp_224.txt
	$(XSUM) -c data/blake2bp_224.txt

check_blake2bp_232: $(INPUT_DEPEND) data/blake2bp_232.txt
	$(XSUM) -c data/blake2bp_232.txt

check_blake2bp_240: $(INPUT_DEPEND) data/blake2bp_240.txt
	$(XSUM) -c data/blake2bp_240.txt

check_blake2bp_248: $(INPUT_DEPEND) data/blake2bp_248.txt
	$(XSUM) -c data/blake2bp_248.txt

check_blake2bp_256: $(INPUT_DEPEND) data/blake2bp_256.txt
	$(XSUM) -c data/blake2bp_256.txt

check_blake2bp_264: $(INPUT_DEPEND) data/blake2bp_264.txt
	$(XSUM) -c data/blake2bp_264.txt

check_blake2bp_272: $(INPUT_DEPEND) data/blake2bp_272.txt
	$(XSUM) -c data/blake2bp_272.txt

check_blake2bp_280: $(INPUT_DEPEND) data/blake2bp_280.txt
	$(XSUM) -c data/blake2bp_280.txt

check_blake2bp_288: $(INPUT_DEPEND) data/blake2bp_288.txt
	$(XSUM) -c data/blake2bp_288.txt

check_blake2bp_296: $(INPUT_DEPEND) data/blake2bp_296.txt
	$(XSUM) -c data/blake2bp_296.txt

check_blake2bp_304: $(INPUT_DEPEND) data/blake2bp_304.txt
	$(XSUM) -c data/blake2bp_304.txt

check_blake2bp_312: $(INPUT_DEPEND) data/blake2bp_312.txt
	$(XSUM) -c data/blake2bp_312.txt

check_blake2bp_320: $(INPUT_DEPEND) data/blake2bp_320.txt
	$(XSUM) -c data/blake2bp_320.txt

check_blake2bp_328: $(INPUT_DEPEND) data/blake2bp_328.txt
	$(XSUM) -c data/blake2bp_328.txt

check_blake2bp_336: $(INPUT_DEPEND) data/blake2bp_336.txt
	$(XSUM) -c data/blake2bp_336.txt

check_blake2bp_344: $(INPUT_DEPEND) data/blake2bp_344.txt
	$(XSUM) -c data/blake2bp_344.txt

check_blake2bp_352: $(INPUT_DEPEND) data/blake2bp_352.txt
	$(XSUM) -c data/blake2bp_352.txt

check_blake2bp_360: $(INPUT_DEPEND) data/blake2bp_360.txt
	$(XSUM) -c data/blake2bp_360.txt

check_blake2bp_368: $(INPUT_DEPEND) data/blake2bp_368.txt
	$(XSUM) -c data/blake2bp_368.txt

check_blake2bp_376: $(INPUT_DEPEND) data/blake2bp_376.txt
	$(XSUM) -c data/blake2bp_376.txt

check_blake2bp_384: $(INPUT_DEPEND) data/blake2bp_384.txt
	$(XSUM) -c data/blake2bp_384.txt

check_blake2bp_392: $(INPUT_DEPEND) data/blake2bp_392.txt
	$(XSUM) -c data/blake2bp_392.txt

check_blake2bp_400: $(INPUT_DEPEND) data/blake2bp_400.txt
	$(XSUM) -c data/blake2bp_400.txt

check_blake2bp_408: $(INPUT_DEPEND) data/blake2bp_408.txt
	$(XSUM) -c data/blake2bp_408.txt

check_blake2bp_416: $(INPUT_DEPEND) data/blake2bp_416.txt
	$(XSUM) -c data/blake2bp_416.txt

check_blake2bp_424: $(INPUT_DEPEND) data/blake2bp_424.txt
	$(XSUM) -c data/blake2bp_424.txt

check_blake2bp_432: $(INPUT_DEPEND) data/blake2bp_432.txt
	$(XSUM) -c data/blake2bp_432.txt

check_blake2bp_440: $(INPUT_DEPEND) data/blake2bp_440.txt
	$(XSUM) -c data/blake2bp_440.txt

check_blake2bp_448: $(INPUT_DEPEND) data/blake2bp_448.txt
	$(XSUM) -c data/blake2bp_448.txt

check_blake2bp_456: $(INPUT_DEPEND) data/blake2bp_456.txt
	$(XSUM) -c data/blake2bp_456.txt

check_blake2bp_464: $(INPUT_DEPEND) data/blake2bp_464.txt
	$(XSUM) -c data/blake2bp_464.txt

check_blake2bp_472: $(INPUT_DEPEND) data/blake2bp_472.txt
	$(XSUM) -c data/blake2bp_472.txt

check_blake2bp_480: $(INPUT_DEPEND) data/blake2bp_480.txt
	$(XSUM) -c data/blake2bp_480.txt

check_blake2bp_488: $(INPUT_DEPEND) data/blake2bp_488.txt
	$(XSUM) -c data/blake2bp_488.txt

check_blake2bp_496: $(INPUT_DEPEND) data/blake2bp_496.txt
	$(XSUM) -c data/blake2bp_496.txt

check_blake2bp_504: $(INPUT_DEPEND) data/blake2bp_504.txt
	$(XSUM) -c data/blake2bp_504.txt

check_blake2bp_512: $(INPUT_DEPEND) data/blake2bp_512.txt
	$(XSUM) -c data/blake2bp_512.txt

check_crc24: $(INPUT_DEPEND) data/crc24.txt
	$(XSUM) -c data/crc24.txt

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

check_haval_128: $(INPUT_DEPEND) data/haval_128.txt
	$(XSUM) -c data/haval_128.txt

check_haval_160: $(INPUT_DEPEND) data/haval_160.txt
	$(XSUM) -c data/haval_160.txt

check_haval_192: $(INPUT_DEPEND) data/haval_192.txt
	$(XSUM) -c data/haval_192.txt

check_haval_224: $(INPUT_DEPEND) data/haval_224.txt
	$(XSUM) -c data/haval_224.txt

check_haval_256: $(INPUT_DEPEND) data/haval_256.txt
	$(XSUM) -c data/haval_256.txt

check_keccak_224: $(INPUT_DEPEND) data/keccak_224.txt
	$(XSUM) -c data/keccak_224.txt

check_keccak_256: $(INPUT_DEPEND) data/keccak_256.txt
	$(XSUM) -c data/keccak_256.txt

check_keccak_384: $(INPUT_DEPEND) data/keccak_384.txt
	$(XSUM) -c data/keccak_384.txt

check_keccak_512: $(INPUT_DEPEND) data/keccak_512.txt
	$(XSUM) -c data/keccak_512.txt

check_md2: $(INPUT_DEPEND) data/md2.txt
	$(XSUM) -c data/md2.txt

check_md4: $(INPUT_DEPEND) data/md4.txt
	$(XSUM) -c data/md4.txt

check_md5: $(INPUT_DEPEND) data/md5.txt
	$(XSUM) -c data/md5.txt

check_mdc2: $(INPUT_DEPEND) data/mdc2.txt
	$(XSUM) -c data/mdc2.txt

check_ripemd128: $(INPUT_DEPEND) data/ripemd128.txt
	$(XSUM) -c data/ripemd128.txt

check_ripemd160: $(INPUT_DEPEND) data/ripemd160.txt
	$(XSUM) -c data/ripemd160.txt

check_ripemd256: $(INPUT_DEPEND) data/ripemd256.txt
	$(XSUM) -c data/ripemd256.txt

check_ripemd320: $(INPUT_DEPEND) data/ripemd320.txt
	$(XSUM) -c data/ripemd320.txt

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

check_sm3: $(INPUT_DEPEND) data/sm3.txt
	$(XSUM) -c data/sm3.txt

check_skein_512_8: $(INPUT_DEPEND) data/skein_512_8.txt
	$(XSUM) -c data/skein_512_8.txt

check_skein_512_16: $(INPUT_DEPEND) data/skein_512_16.txt
	$(XSUM) -c data/skein_512_16.txt

check_skein_512_24: $(INPUT_DEPEND) data/skein_512_24.txt
	$(XSUM) -c data/skein_512_24.txt

check_skein_512_32: $(INPUT_DEPEND) data/skein_512_32.txt
	$(XSUM) -c data/skein_512_32.txt

check_skein_512_40: $(INPUT_DEPEND) data/skein_512_40.txt
	$(XSUM) -c data/skein_512_40.txt

check_skein_512_48: $(INPUT_DEPEND) data/skein_512_48.txt
	$(XSUM) -c data/skein_512_48.txt

check_skein_512_56: $(INPUT_DEPEND) data/skein_512_56.txt
	$(XSUM) -c data/skein_512_56.txt

check_skein_512_64: $(INPUT_DEPEND) data/skein_512_64.txt
	$(XSUM) -c data/skein_512_64.txt

check_skein_512_72: $(INPUT_DEPEND) data/skein_512_72.txt
	$(XSUM) -c data/skein_512_72.txt

check_skein_512_80: $(INPUT_DEPEND) data/skein_512_80.txt
	$(XSUM) -c data/skein_512_80.txt

check_skein_512_88: $(INPUT_DEPEND) data/skein_512_88.txt
	$(XSUM) -c data/skein_512_88.txt

check_skein_512_96: $(INPUT_DEPEND) data/skein_512_96.txt
	$(XSUM) -c data/skein_512_96.txt

check_skein_512_104: $(INPUT_DEPEND) data/skein_512_104.txt
	$(XSUM) -c data/skein_512_104.txt

check_skein_512_112: $(INPUT_DEPEND) data/skein_512_112.txt
	$(XSUM) -c data/skein_512_112.txt

check_skein_512_120: $(INPUT_DEPEND) data/skein_512_120.txt
	$(XSUM) -c data/skein_512_120.txt

check_skein_512_128: $(INPUT_DEPEND) data/skein_512_128.txt
	$(XSUM) -c data/skein_512_128.txt

check_skein_512_136: $(INPUT_DEPEND) data/skein_512_136.txt
	$(XSUM) -c data/skein_512_136.txt

check_skein_512_144: $(INPUT_DEPEND) data/skein_512_144.txt
	$(XSUM) -c data/skein_512_144.txt

check_skein_512_152: $(INPUT_DEPEND) data/skein_512_152.txt
	$(XSUM) -c data/skein_512_152.txt

check_skein_512_160: $(INPUT_DEPEND) data/skein_512_160.txt
	$(XSUM) -c data/skein_512_160.txt

check_skein_512_168: $(INPUT_DEPEND) data/skein_512_168.txt
	$(XSUM) -c data/skein_512_168.txt

check_skein_512_176: $(INPUT_DEPEND) data/skein_512_176.txt
	$(XSUM) -c data/skein_512_176.txt

check_skein_512_184: $(INPUT_DEPEND) data/skein_512_184.txt
	$(XSUM) -c data/skein_512_184.txt

check_skein_512_192: $(INPUT_DEPEND) data/skein_512_192.txt
	$(XSUM) -c data/skein_512_192.txt

check_skein_512_200: $(INPUT_DEPEND) data/skein_512_200.txt
	$(XSUM) -c data/skein_512_200.txt

check_skein_512_208: $(INPUT_DEPEND) data/skein_512_208.txt
	$(XSUM) -c data/skein_512_208.txt

check_skein_512_216: $(INPUT_DEPEND) data/skein_512_216.txt
	$(XSUM) -c data/skein_512_216.txt

check_skein_512_224: $(INPUT_DEPEND) data/skein_512_224.txt
	$(XSUM) -c data/skein_512_224.txt

check_skein_512_232: $(INPUT_DEPEND) data/skein_512_232.txt
	$(XSUM) -c data/skein_512_232.txt

check_skein_512_240: $(INPUT_DEPEND) data/skein_512_240.txt
	$(XSUM) -c data/skein_512_240.txt

check_skein_512_248: $(INPUT_DEPEND) data/skein_512_248.txt
	$(XSUM) -c data/skein_512_248.txt

check_skein_512_256: $(INPUT_DEPEND) data/skein_512_256.txt
	$(XSUM) -c data/skein_512_256.txt

check_skein_512_264: $(INPUT_DEPEND) data/skein_512_264.txt
	$(XSUM) -c data/skein_512_264.txt

check_skein_512_272: $(INPUT_DEPEND) data/skein_512_272.txt
	$(XSUM) -c data/skein_512_272.txt

check_skein_512_280: $(INPUT_DEPEND) data/skein_512_280.txt
	$(XSUM) -c data/skein_512_280.txt

check_skein_512_288: $(INPUT_DEPEND) data/skein_512_288.txt
	$(XSUM) -c data/skein_512_288.txt

check_skein_512_296: $(INPUT_DEPEND) data/skein_512_296.txt
	$(XSUM) -c data/skein_512_296.txt

check_skein_512_304: $(INPUT_DEPEND) data/skein_512_304.txt
	$(XSUM) -c data/skein_512_304.txt

check_skein_512_312: $(INPUT_DEPEND) data/skein_512_312.txt
	$(XSUM) -c data/skein_512_312.txt

check_skein_512_320: $(INPUT_DEPEND) data/skein_512_320.txt
	$(XSUM) -c data/skein_512_320.txt

check_skein_512_328: $(INPUT_DEPEND) data/skein_512_328.txt
	$(XSUM) -c data/skein_512_328.txt

check_skein_512_336: $(INPUT_DEPEND) data/skein_512_336.txt
	$(XSUM) -c data/skein_512_336.txt

check_skein_512_344: $(INPUT_DEPEND) data/skein_512_344.txt
	$(XSUM) -c data/skein_512_344.txt

check_skein_512_352: $(INPUT_DEPEND) data/skein_512_352.txt
	$(XSUM) -c data/skein_512_352.txt

check_skein_512_360: $(INPUT_DEPEND) data/skein_512_360.txt
	$(XSUM) -c data/skein_512_360.txt

check_skein_512_368: $(INPUT_DEPEND) data/skein_512_368.txt
	$(XSUM) -c data/skein_512_368.txt

check_skein_512_376: $(INPUT_DEPEND) data/skein_512_376.txt
	$(XSUM) -c data/skein_512_376.txt

check_skein_512_384: $(INPUT_DEPEND) data/skein_512_384.txt
	$(XSUM) -c data/skein_512_384.txt

check_skein_512_392: $(INPUT_DEPEND) data/skein_512_392.txt
	$(XSUM) -c data/skein_512_392.txt

check_skein_512_400: $(INPUT_DEPEND) data/skein_512_400.txt
	$(XSUM) -c data/skein_512_400.txt

check_skein_512_408: $(INPUT_DEPEND) data/skein_512_408.txt
	$(XSUM) -c data/skein_512_408.txt

check_skein_512_416: $(INPUT_DEPEND) data/skein_512_416.txt
	$(XSUM) -c data/skein_512_416.txt

check_skein_512_424: $(INPUT_DEPEND) data/skein_512_424.txt
	$(XSUM) -c data/skein_512_424.txt

check_skein_512_432: $(INPUT_DEPEND) data/skein_512_432.txt
	$(XSUM) -c data/skein_512_432.txt

check_skein_512_440: $(INPUT_DEPEND) data/skein_512_440.txt
	$(XSUM) -c data/skein_512_440.txt

check_skein_512_448: $(INPUT_DEPEND) data/skein_512_448.txt
	$(XSUM) -c data/skein_512_448.txt

check_skein_512_456: $(INPUT_DEPEND) data/skein_512_456.txt
	$(XSUM) -c data/skein_512_456.txt

check_skein_512_464: $(INPUT_DEPEND) data/skein_512_464.txt
	$(XSUM) -c data/skein_512_464.txt

check_skein_512_472: $(INPUT_DEPEND) data/skein_512_472.txt
	$(XSUM) -c data/skein_512_472.txt

check_skein_512_480: $(INPUT_DEPEND) data/skein_512_480.txt
	$(XSUM) -c data/skein_512_480.txt

check_skein_512_488: $(INPUT_DEPEND) data/skein_512_488.txt
	$(XSUM) -c data/skein_512_488.txt

check_skein_512_496: $(INPUT_DEPEND) data/skein_512_496.txt
	$(XSUM) -c data/skein_512_496.txt

check_skein_512_504: $(INPUT_DEPEND) data/skein_512_504.txt
	$(XSUM) -c data/skein_512_504.txt

check_skein_512_512: $(INPUT_DEPEND) data/skein_512_512.txt
	$(XSUM) -c data/skein_512_512.txt

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
