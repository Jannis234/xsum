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
XSUM = ../xsum$(EXEEXT) --ignore-unknown

# Depend on the last file that make_input creates (in case it aborts early)
INPUT_DEPEND = input/empty

CHECKS = check_adler_32 \
	check_blake_224 check_blake_256 check_blake_384 check_blake_512 \
	check_blake2s_8 check_blake2s_16 check_blake2s_24 check_blake2s_32 check_blake2s_40 check_blake2s_48 check_blake2s_56 check_blake2s_64 check_blake2s_72 check_blake2s_80 check_blake2s_88 check_blake2s_96 check_blake2s_104 check_blake2s_112 check_blake2s_120 check_blake2s_128 check_blake2s_136 check_blake2s_144 check_blake2s_152 check_blake2s_160 check_blake2s_168 check_blake2s_176 check_blake2s_184 check_blake2s_192 check_blake2s_200 check_blake2s_208 check_blake2s_216 check_blake2s_224 check_blake2s_232 check_blake2s_240 check_blake2s_248 check_blake2s_256 \
	check_blake2sp_8 check_blake2sp_16 check_blake2sp_24 check_blake2sp_32 check_blake2sp_40 check_blake2sp_48 check_blake2sp_56 check_blake2sp_64 check_blake2sp_72 check_blake2sp_80 check_blake2sp_88 check_blake2sp_96 check_blake2sp_104 check_blake2sp_112 check_blake2sp_120 check_blake2sp_128 check_blake2sp_136 check_blake2sp_144 check_blake2sp_152 check_blake2sp_160 check_blake2sp_168 check_blake2sp_176 check_blake2sp_184 check_blake2sp_192 check_blake2sp_200 check_blake2sp_208 check_blake2sp_216 check_blake2sp_224 check_blake2sp_232 check_blake2sp_240 check_blake2sp_248 check_blake2sp_256 \
	check_blake2b_8 check_blake2b_16 check_blake2b_24 check_blake2b_32 check_blake2b_40 check_blake2b_48 check_blake2b_56 check_blake2b_64 check_blake2b_72 check_blake2b_80 check_blake2b_88 check_blake2b_96 check_blake2b_104 check_blake2b_112 check_blake2b_120 check_blake2b_128 check_blake2b_136 check_blake2b_144 check_blake2b_152 check_blake2b_160 check_blake2b_168 check_blake2b_176 check_blake2b_184 check_blake2b_192 check_blake2b_200 check_blake2b_208 check_blake2b_216 check_blake2b_224 check_blake2b_232 check_blake2b_240 check_blake2b_248 check_blake2b_256 check_blake2b_264 check_blake2b_272 check_blake2b_280 check_blake2b_288 check_blake2b_296 check_blake2b_304 check_blake2b_312 check_blake2b_320 check_blake2b_328 check_blake2b_336 check_blake2b_344 check_blake2b_352 check_blake2b_360 check_blake2b_368 check_blake2b_376 check_blake2b_384 check_blake2b_392 check_blake2b_400 check_blake2b_408 check_blake2b_416 check_blake2b_424 check_blake2b_432 check_blake2b_440 check_blake2b_448 check_blake2b_456 check_blake2b_464 check_blake2b_472 check_blake2b_480 check_blake2b_488 check_blake2b_496 check_blake2b_504 check_blake2b_512 \
	check_blake2bp_8 check_blake2bp_16 check_blake2bp_24 check_blake2bp_32 check_blake2bp_40 check_blake2bp_48 check_blake2bp_56 check_blake2bp_64 check_blake2bp_72 check_blake2bp_80 check_blake2bp_88 check_blake2bp_96 check_blake2bp_104 check_blake2bp_112 check_blake2bp_120 check_blake2bp_128 check_blake2bp_136 check_blake2bp_144 check_blake2bp_152 check_blake2bp_160 check_blake2bp_168 check_blake2bp_176 check_blake2bp_184 check_blake2bp_192 check_blake2bp_200 check_blake2bp_208 check_blake2bp_216 check_blake2bp_224 check_blake2bp_232 check_blake2bp_240 check_blake2bp_248 check_blake2bp_256 check_blake2bp_264 check_blake2bp_272 check_blake2bp_280 check_blake2bp_288 check_blake2bp_296 check_blake2bp_304 check_blake2bp_312 check_blake2bp_320 check_blake2bp_328 check_blake2bp_336 check_blake2bp_344 check_blake2bp_352 check_blake2bp_360 check_blake2bp_368 check_blake2bp_376 check_blake2bp_384 check_blake2bp_392 check_blake2bp_400 check_blake2bp_408 check_blake2bp_416 check_blake2bp_424 check_blake2bp_432 check_blake2bp_440 check_blake2bp_448 check_blake2bp_456 check_blake2bp_464 check_blake2bp_472 check_blake2bp_480 check_blake2bp_488 check_blake2bp_496 check_blake2bp_504 check_blake2bp_512 \
	check_crc24 check_crc32 check_crc64 \
	check_echo_8 check_echo_16 check_echo_24 check_echo_32 check_echo_40 check_echo_48 check_echo_56 check_echo_64 check_echo_72 check_echo_80 check_echo_88 check_echo_96 check_echo_104 check_echo_112 check_echo_120 check_echo_128 check_echo_136 check_echo_144 check_echo_152 check_echo_160 check_echo_168 check_echo_176 check_echo_184 check_echo_192 check_echo_200 check_echo_208 check_echo_216 check_echo_224 check_echo_232 check_echo_240 check_echo_248 check_echo_256 check_echo_264 check_echo_272 check_echo_280 check_echo_288 check_echo_296 check_echo_304 check_echo_312 check_echo_320 check_echo_328 check_echo_336 check_echo_344 check_echo_352 check_echo_360 check_echo_368 check_echo_376 check_echo_384 check_echo_392 check_echo_400 check_echo_408 check_echo_416 check_echo_424 check_echo_432 check_echo_440 check_echo_448 check_echo_456 check_echo_464 check_echo_472 check_echo_480 check_echo_488 check_echo_496 check_echo_504 check_echo_512 \
	check_edon_r_256 check_edon_r_512 \
	check_esch_256 check_esch_384 \
	check_gost12_256 check_gost12_512 \
	check_gost94 check_gost94_cryptopro \
	check_groestl_8 check_groestl_16 check_groestl_24 check_groestl_32 check_groestl_40 check_groestl_48 check_groestl_56 check_groestl_64 check_groestl_72 check_groestl_80 check_groestl_88 check_groestl_96 check_groestl_104 check_groestl_112 check_groestl_120 check_groestl_128 check_groestl_136 check_groestl_144 check_groestl_152 check_groestl_160 check_groestl_168 check_groestl_176 check_groestl_184 check_groestl_192 check_groestl_200 check_groestl_208 check_groestl_216 check_groestl_224 check_groestl_232 check_groestl_240 check_groestl_248 check_groestl_256 check_groestl_264 check_groestl_272 check_groestl_280 check_groestl_288 check_groestl_296 check_groestl_304 check_groestl_312 check_groestl_320 check_groestl_328 check_groestl_336 check_groestl_344 check_groestl_352 check_groestl_360 check_groestl_368 check_groestl_376 check_groestl_384 check_groestl_392 check_groestl_400 check_groestl_408 check_groestl_416 check_groestl_424 check_groestl_432 check_groestl_440 check_groestl_448 check_groestl_456 check_groestl_464 check_groestl_472 check_groestl_480 check_groestl_488 check_groestl_496 check_groestl_504 check_groestl_512 \
	check_has160 \
	check_haval_128 check_haval_160 check_haval_192 check_haval_224 check_haval_256 \
	check_jh_224 check_jh_256 check_jh_384 check_jh_512 \
	check_md2 \
	check_md4 \
	check_md5 \
	check_mdc2 \
	check_keccak_224 check_keccak_256 check_keccak_384 check_keccak_512 \
	check_kupyna_256 check_kupyna_512 \
	check_ripemd128 check_ripemd160 check_ripemd256 check_ripemd320 \
	check_sha1 \
	check_sha224 check_sha256 check_sha384 check_sha512 check_sha512_224 check_sha512_256 \
	check_sha3_224 check_sha3_256 check_sha3_384 check_sha3_512 \
	check_skein256_8 check_skein256_16 check_skein256_24 check_skein256_32 check_skein256_40 check_skein256_48 check_skein256_56 check_skein256_64 check_skein256_72 check_skein256_80 check_skein256_88 check_skein256_96 check_skein256_104 check_skein256_112 check_skein256_120 check_skein256_128 check_skein256_136 check_skein256_144 check_skein256_152 check_skein256_160 check_skein256_168 check_skein256_176 check_skein256_184 check_skein256_192 check_skein256_200 check_skein256_208 check_skein256_216 check_skein256_224 check_skein256_232 check_skein256_240 check_skein256_248 check_skein256_256 \
	check_skein_512_8 check_skein_512_16 check_skein_512_24 check_skein_512_32 check_skein_512_40 check_skein_512_48 check_skein_512_56 check_skein_512_64 check_skein_512_72 check_skein_512_80 check_skein_512_88 check_skein_512_96 check_skein_512_104 check_skein_512_112 check_skein_512_120 check_skein_512_128 check_skein_512_136 check_skein_512_144 check_skein_512_152 check_skein_512_160 check_skein_512_168 check_skein_512_176 check_skein_512_184 check_skein_512_192 check_skein_512_200 check_skein_512_208 check_skein_512_216 check_skein_512_224 check_skein_512_232 check_skein_512_240 check_skein_512_248 check_skein_512_256 check_skein_512_264 check_skein_512_272 check_skein_512_280 check_skein_512_288 check_skein_512_296 check_skein_512_304 check_skein_512_312 check_skein_512_320 check_skein_512_328 check_skein_512_336 check_skein_512_344 check_skein_512_352 check_skein_512_360 check_skein_512_368 check_skein_512_376 check_skein_512_384 check_skein_512_392 check_skein_512_400 check_skein_512_408 check_skein_512_416 check_skein_512_424 check_skein_512_432 check_skein_512_440 check_skein_512_448 check_skein_512_456 check_skein_512_464 check_skein_512_472 check_skein_512_480 check_skein_512_488 check_skein_512_496 check_skein_512_504 check_skein_512_512 \
	check_skein1024_8 check_skein1024_16 check_skein1024_24 check_skein1024_32 check_skein1024_40 check_skein1024_48 check_skein1024_56 check_skein1024_64 check_skein1024_72 check_skein1024_80 check_skein1024_88 check_skein1024_96 check_skein1024_104 check_skein1024_112 check_skein1024_120 check_skein1024_128 check_skein1024_136 check_skein1024_144 check_skein1024_152 check_skein1024_160 check_skein1024_168 check_skein1024_176 check_skein1024_184 check_skein1024_192 check_skein1024_200 check_skein1024_208 check_skein1024_216 check_skein1024_224 check_skein1024_232 check_skein1024_240 check_skein1024_248 check_skein1024_256 check_skein1024_264 check_skein1024_272 check_skein1024_280 check_skein1024_288 check_skein1024_296 check_skein1024_304 check_skein1024_312 check_skein1024_320 check_skein1024_328 check_skein1024_336 check_skein1024_344 check_skein1024_352 check_skein1024_360 check_skein1024_368 check_skein1024_376 check_skein1024_384 check_skein1024_392 check_skein1024_400 check_skein1024_408 check_skein1024_416 check_skein1024_424 check_skein1024_432 check_skein1024_440 check_skein1024_448 check_skein1024_456 check_skein1024_464 check_skein1024_472 check_skein1024_480 check_skein1024_488 check_skein1024_496 check_skein1024_504 check_skein1024_512 check_skein1024_520 check_skein1024_528 check_skein1024_536 check_skein1024_544 check_skein1024_552 check_skein1024_560 check_skein1024_568 check_skein1024_576 check_skein1024_584 check_skein1024_592 check_skein1024_600 check_skein1024_608 check_skein1024_616 check_skein1024_624 check_skein1024_632 check_skein1024_640 check_skein1024_648 check_skein1024_656 check_skein1024_664 check_skein1024_672 check_skein1024_680 check_skein1024_688 check_skein1024_696 check_skein1024_704 check_skein1024_712 check_skein1024_720 check_skein1024_728 check_skein1024_736 check_skein1024_744 check_skein1024_752 check_skein1024_760 check_skein1024_768 check_skein1024_776 check_skein1024_784 check_skein1024_792 check_skein1024_800 check_skein1024_808 check_skein1024_816 check_skein1024_824 check_skein1024_832 check_skein1024_840 check_skein1024_848 check_skein1024_856 check_skein1024_864 check_skein1024_872 check_skein1024_880 check_skein1024_888 check_skein1024_896 check_skein1024_904 check_skein1024_912 check_skein1024_920 check_skein1024_928 check_skein1024_936 check_skein1024_944 check_skein1024_952 check_skein1024_960 check_skein1024_968 check_skein1024_976 check_skein1024_984 check_skein1024_992 check_skein1024_1000 check_skein1024_1008 check_skein1024_1016 check_skein1024_1024 \
	check_sm3 \
	check_snefru_128 check_snefru_256 \
	check_streebog_256 check_streebog_512 \
	check_sum \
	check_xor \
	check_xxhash32 check_xxhash64 check_xxhash3_64 check_xxhash3_128

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

check_blake_224: $(INPUT_DEPEND) data/blake_224.txt
	$(XSUM) -c data/blake_224.txt

check_blake_256: $(INPUT_DEPEND) data/blake_256.txt
	$(XSUM) -c data/blake_256.txt

check_blake_384: $(INPUT_DEPEND) data/blake_384.txt
	$(XSUM) -c data/blake_384.txt

check_blake_512: $(INPUT_DEPEND) data/blake_512.txt
	$(XSUM) -c data/blake_512.txt

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

check_echo_8: $(INPUT_DEPEND) data/echo_8.txt
	$(XSUM) -c data/echo_8.txt

check_echo_16: $(INPUT_DEPEND) data/echo_16.txt
	$(XSUM) -c data/echo_16.txt

check_echo_24: $(INPUT_DEPEND) data/echo_24.txt
	$(XSUM) -c data/echo_24.txt

check_echo_32: $(INPUT_DEPEND) data/echo_32.txt
	$(XSUM) -c data/echo_32.txt

check_echo_40: $(INPUT_DEPEND) data/echo_40.txt
	$(XSUM) -c data/echo_40.txt

check_echo_48: $(INPUT_DEPEND) data/echo_48.txt
	$(XSUM) -c data/echo_48.txt

check_echo_56: $(INPUT_DEPEND) data/echo_56.txt
	$(XSUM) -c data/echo_56.txt

check_echo_64: $(INPUT_DEPEND) data/echo_64.txt
	$(XSUM) -c data/echo_64.txt

check_echo_72: $(INPUT_DEPEND) data/echo_72.txt
	$(XSUM) -c data/echo_72.txt

check_echo_80: $(INPUT_DEPEND) data/echo_80.txt
	$(XSUM) -c data/echo_80.txt

check_echo_88: $(INPUT_DEPEND) data/echo_88.txt
	$(XSUM) -c data/echo_88.txt

check_echo_96: $(INPUT_DEPEND) data/echo_96.txt
	$(XSUM) -c data/echo_96.txt

check_echo_104: $(INPUT_DEPEND) data/echo_104.txt
	$(XSUM) -c data/echo_104.txt

check_echo_112: $(INPUT_DEPEND) data/echo_112.txt
	$(XSUM) -c data/echo_112.txt

check_echo_120: $(INPUT_DEPEND) data/echo_120.txt
	$(XSUM) -c data/echo_120.txt

check_echo_128: $(INPUT_DEPEND) data/echo_128.txt
	$(XSUM) -c data/echo_128.txt

check_echo_136: $(INPUT_DEPEND) data/echo_136.txt
	$(XSUM) -c data/echo_136.txt

check_echo_144: $(INPUT_DEPEND) data/echo_144.txt
	$(XSUM) -c data/echo_144.txt

check_echo_152: $(INPUT_DEPEND) data/echo_152.txt
	$(XSUM) -c data/echo_152.txt

check_echo_160: $(INPUT_DEPEND) data/echo_160.txt
	$(XSUM) -c data/echo_160.txt

check_echo_168: $(INPUT_DEPEND) data/echo_168.txt
	$(XSUM) -c data/echo_168.txt

check_echo_176: $(INPUT_DEPEND) data/echo_176.txt
	$(XSUM) -c data/echo_176.txt

check_echo_184: $(INPUT_DEPEND) data/echo_184.txt
	$(XSUM) -c data/echo_184.txt

check_echo_192: $(INPUT_DEPEND) data/echo_192.txt
	$(XSUM) -c data/echo_192.txt

check_echo_200: $(INPUT_DEPEND) data/echo_200.txt
	$(XSUM) -c data/echo_200.txt

check_echo_208: $(INPUT_DEPEND) data/echo_208.txt
	$(XSUM) -c data/echo_208.txt

check_echo_216: $(INPUT_DEPEND) data/echo_216.txt
	$(XSUM) -c data/echo_216.txt

check_echo_224: $(INPUT_DEPEND) data/echo_224.txt
	$(XSUM) -c data/echo_224.txt

check_echo_232: $(INPUT_DEPEND) data/echo_232.txt
	$(XSUM) -c data/echo_232.txt

check_echo_240: $(INPUT_DEPEND) data/echo_240.txt
	$(XSUM) -c data/echo_240.txt

check_echo_248: $(INPUT_DEPEND) data/echo_248.txt
	$(XSUM) -c data/echo_248.txt

check_echo_256: $(INPUT_DEPEND) data/echo_256.txt
	$(XSUM) -c data/echo_256.txt

check_echo_264: $(INPUT_DEPEND) data/echo_264.txt
	$(XSUM) -c data/echo_264.txt

check_echo_272: $(INPUT_DEPEND) data/echo_272.txt
	$(XSUM) -c data/echo_272.txt

check_echo_280: $(INPUT_DEPEND) data/echo_280.txt
	$(XSUM) -c data/echo_280.txt

check_echo_288: $(INPUT_DEPEND) data/echo_288.txt
	$(XSUM) -c data/echo_288.txt

check_echo_296: $(INPUT_DEPEND) data/echo_296.txt
	$(XSUM) -c data/echo_296.txt

check_echo_304: $(INPUT_DEPEND) data/echo_304.txt
	$(XSUM) -c data/echo_304.txt

check_echo_312: $(INPUT_DEPEND) data/echo_312.txt
	$(XSUM) -c data/echo_312.txt

check_echo_320: $(INPUT_DEPEND) data/echo_320.txt
	$(XSUM) -c data/echo_320.txt

check_echo_328: $(INPUT_DEPEND) data/echo_328.txt
	$(XSUM) -c data/echo_328.txt

check_echo_336: $(INPUT_DEPEND) data/echo_336.txt
	$(XSUM) -c data/echo_336.txt

check_echo_344: $(INPUT_DEPEND) data/echo_344.txt
	$(XSUM) -c data/echo_344.txt

check_echo_352: $(INPUT_DEPEND) data/echo_352.txt
	$(XSUM) -c data/echo_352.txt

check_echo_360: $(INPUT_DEPEND) data/echo_360.txt
	$(XSUM) -c data/echo_360.txt

check_echo_368: $(INPUT_DEPEND) data/echo_368.txt
	$(XSUM) -c data/echo_368.txt

check_echo_376: $(INPUT_DEPEND) data/echo_376.txt
	$(XSUM) -c data/echo_376.txt

check_echo_384: $(INPUT_DEPEND) data/echo_384.txt
	$(XSUM) -c data/echo_384.txt

check_echo_392: $(INPUT_DEPEND) data/echo_392.txt
	$(XSUM) -c data/echo_392.txt

check_echo_400: $(INPUT_DEPEND) data/echo_400.txt
	$(XSUM) -c data/echo_400.txt

check_echo_408: $(INPUT_DEPEND) data/echo_408.txt
	$(XSUM) -c data/echo_408.txt

check_echo_416: $(INPUT_DEPEND) data/echo_416.txt
	$(XSUM) -c data/echo_416.txt

check_echo_424: $(INPUT_DEPEND) data/echo_424.txt
	$(XSUM) -c data/echo_424.txt

check_echo_432: $(INPUT_DEPEND) data/echo_432.txt
	$(XSUM) -c data/echo_432.txt

check_echo_440: $(INPUT_DEPEND) data/echo_440.txt
	$(XSUM) -c data/echo_440.txt

check_echo_448: $(INPUT_DEPEND) data/echo_448.txt
	$(XSUM) -c data/echo_448.txt

check_echo_456: $(INPUT_DEPEND) data/echo_456.txt
	$(XSUM) -c data/echo_456.txt

check_echo_464: $(INPUT_DEPEND) data/echo_464.txt
	$(XSUM) -c data/echo_464.txt

check_echo_472: $(INPUT_DEPEND) data/echo_472.txt
	$(XSUM) -c data/echo_472.txt

check_echo_480: $(INPUT_DEPEND) data/echo_480.txt
	$(XSUM) -c data/echo_480.txt

check_echo_488: $(INPUT_DEPEND) data/echo_488.txt
	$(XSUM) -c data/echo_488.txt

check_echo_496: $(INPUT_DEPEND) data/echo_496.txt
	$(XSUM) -c data/echo_496.txt

check_echo_504: $(INPUT_DEPEND) data/echo_504.txt
	$(XSUM) -c data/echo_504.txt

check_echo_512: $(INPUT_DEPEND) data/echo_512.txt
	$(XSUM) -c data/echo_512.txt

check_edon_r_256: $(INPUT_DEPEND) data/edon_r_256.txt
	$(XSUM) -c data/edon_r_256.txt

check_edon_r_512: $(INPUT_DEPEND) data/edon_r_512.txt
	$(XSUM) -c data/edon_r_512.txt

check_esch_256: $(INPUT_DEPEND) data/esch_256.txt
	$(XSUM) -c data/esch_256.txt

check_esch_384: $(INPUT_DEPEND) data/esch_384.txt
	$(XSUM) -c data/esch_384.txt

check_gost12_256: $(INPUT_DEPEND) data/gost12_256.txt
	$(XSUM) -c data/gost12_256.txt

check_gost12_512: $(INPUT_DEPEND) data/gost12_512.txt
	$(XSUM) -c data/gost12_512.txt

check_gost94: $(INPUT_DEPEND) data/gost94.txt
	$(XSUM) -c data/gost94.txt

check_gost94_cryptopro: $(INPUT_DEPEND) data/gost94_cryptopro.txt
	$(XSUM) -c data/gost94_cryptopro.txt

check_groestl_8: $(INPUT_DEPEND) data/groestl_8.txt
	$(XSUM) -c data/groestl_8.txt

check_groestl_16: $(INPUT_DEPEND) data/groestl_16.txt
	$(XSUM) -c data/groestl_16.txt

check_groestl_24: $(INPUT_DEPEND) data/groestl_24.txt
	$(XSUM) -c data/groestl_24.txt

check_groestl_32: $(INPUT_DEPEND) data/groestl_32.txt
	$(XSUM) -c data/groestl_32.txt

check_groestl_40: $(INPUT_DEPEND) data/groestl_40.txt
	$(XSUM) -c data/groestl_40.txt

check_groestl_48: $(INPUT_DEPEND) data/groestl_48.txt
	$(XSUM) -c data/groestl_48.txt

check_groestl_56: $(INPUT_DEPEND) data/groestl_56.txt
	$(XSUM) -c data/groestl_56.txt

check_groestl_64: $(INPUT_DEPEND) data/groestl_64.txt
	$(XSUM) -c data/groestl_64.txt

check_groestl_72: $(INPUT_DEPEND) data/groestl_72.txt
	$(XSUM) -c data/groestl_72.txt

check_groestl_80: $(INPUT_DEPEND) data/groestl_80.txt
	$(XSUM) -c data/groestl_80.txt

check_groestl_88: $(INPUT_DEPEND) data/groestl_88.txt
	$(XSUM) -c data/groestl_88.txt

check_groestl_96: $(INPUT_DEPEND) data/groestl_96.txt
	$(XSUM) -c data/groestl_96.txt

check_groestl_104: $(INPUT_DEPEND) data/groestl_104.txt
	$(XSUM) -c data/groestl_104.txt

check_groestl_112: $(INPUT_DEPEND) data/groestl_112.txt
	$(XSUM) -c data/groestl_112.txt

check_groestl_120: $(INPUT_DEPEND) data/groestl_120.txt
	$(XSUM) -c data/groestl_120.txt

check_groestl_128: $(INPUT_DEPEND) data/groestl_128.txt
	$(XSUM) -c data/groestl_128.txt

check_groestl_136: $(INPUT_DEPEND) data/groestl_136.txt
	$(XSUM) -c data/groestl_136.txt

check_groestl_144: $(INPUT_DEPEND) data/groestl_144.txt
	$(XSUM) -c data/groestl_144.txt

check_groestl_152: $(INPUT_DEPEND) data/groestl_152.txt
	$(XSUM) -c data/groestl_152.txt

check_groestl_160: $(INPUT_DEPEND) data/groestl_160.txt
	$(XSUM) -c data/groestl_160.txt

check_groestl_168: $(INPUT_DEPEND) data/groestl_168.txt
	$(XSUM) -c data/groestl_168.txt

check_groestl_176: $(INPUT_DEPEND) data/groestl_176.txt
	$(XSUM) -c data/groestl_176.txt

check_groestl_184: $(INPUT_DEPEND) data/groestl_184.txt
	$(XSUM) -c data/groestl_184.txt

check_groestl_192: $(INPUT_DEPEND) data/groestl_192.txt
	$(XSUM) -c data/groestl_192.txt

check_groestl_200: $(INPUT_DEPEND) data/groestl_200.txt
	$(XSUM) -c data/groestl_200.txt

check_groestl_208: $(INPUT_DEPEND) data/groestl_208.txt
	$(XSUM) -c data/groestl_208.txt

check_groestl_216: $(INPUT_DEPEND) data/groestl_216.txt
	$(XSUM) -c data/groestl_216.txt

check_groestl_224: $(INPUT_DEPEND) data/groestl_224.txt
	$(XSUM) -c data/groestl_224.txt

check_groestl_232: $(INPUT_DEPEND) data/groestl_232.txt
	$(XSUM) -c data/groestl_232.txt

check_groestl_240: $(INPUT_DEPEND) data/groestl_240.txt
	$(XSUM) -c data/groestl_240.txt

check_groestl_248: $(INPUT_DEPEND) data/groestl_248.txt
	$(XSUM) -c data/groestl_248.txt

check_groestl_256: $(INPUT_DEPEND) data/groestl_256.txt
	$(XSUM) -c data/groestl_256.txt

check_groestl_264: $(INPUT_DEPEND) data/groestl_264.txt
	$(XSUM) -c data/groestl_264.txt

check_groestl_272: $(INPUT_DEPEND) data/groestl_272.txt
	$(XSUM) -c data/groestl_272.txt

check_groestl_280: $(INPUT_DEPEND) data/groestl_280.txt
	$(XSUM) -c data/groestl_280.txt

check_groestl_288: $(INPUT_DEPEND) data/groestl_288.txt
	$(XSUM) -c data/groestl_288.txt

check_groestl_296: $(INPUT_DEPEND) data/groestl_296.txt
	$(XSUM) -c data/groestl_296.txt

check_groestl_304: $(INPUT_DEPEND) data/groestl_304.txt
	$(XSUM) -c data/groestl_304.txt

check_groestl_312: $(INPUT_DEPEND) data/groestl_312.txt
	$(XSUM) -c data/groestl_312.txt

check_groestl_320: $(INPUT_DEPEND) data/groestl_320.txt
	$(XSUM) -c data/groestl_320.txt

check_groestl_328: $(INPUT_DEPEND) data/groestl_328.txt
	$(XSUM) -c data/groestl_328.txt

check_groestl_336: $(INPUT_DEPEND) data/groestl_336.txt
	$(XSUM) -c data/groestl_336.txt

check_groestl_344: $(INPUT_DEPEND) data/groestl_344.txt
	$(XSUM) -c data/groestl_344.txt

check_groestl_352: $(INPUT_DEPEND) data/groestl_352.txt
	$(XSUM) -c data/groestl_352.txt

check_groestl_360: $(INPUT_DEPEND) data/groestl_360.txt
	$(XSUM) -c data/groestl_360.txt

check_groestl_368: $(INPUT_DEPEND) data/groestl_368.txt
	$(XSUM) -c data/groestl_368.txt

check_groestl_376: $(INPUT_DEPEND) data/groestl_376.txt
	$(XSUM) -c data/groestl_376.txt

check_groestl_384: $(INPUT_DEPEND) data/groestl_384.txt
	$(XSUM) -c data/groestl_384.txt

check_groestl_392: $(INPUT_DEPEND) data/groestl_392.txt
	$(XSUM) -c data/groestl_392.txt

check_groestl_400: $(INPUT_DEPEND) data/groestl_400.txt
	$(XSUM) -c data/groestl_400.txt

check_groestl_408: $(INPUT_DEPEND) data/groestl_408.txt
	$(XSUM) -c data/groestl_408.txt

check_groestl_416: $(INPUT_DEPEND) data/groestl_416.txt
	$(XSUM) -c data/groestl_416.txt

check_groestl_424: $(INPUT_DEPEND) data/groestl_424.txt
	$(XSUM) -c data/groestl_424.txt

check_groestl_432: $(INPUT_DEPEND) data/groestl_432.txt
	$(XSUM) -c data/groestl_432.txt

check_groestl_440: $(INPUT_DEPEND) data/groestl_440.txt
	$(XSUM) -c data/groestl_440.txt

check_groestl_448: $(INPUT_DEPEND) data/groestl_448.txt
	$(XSUM) -c data/groestl_448.txt

check_groestl_456: $(INPUT_DEPEND) data/groestl_456.txt
	$(XSUM) -c data/groestl_456.txt

check_groestl_464: $(INPUT_DEPEND) data/groestl_464.txt
	$(XSUM) -c data/groestl_464.txt

check_groestl_472: $(INPUT_DEPEND) data/groestl_472.txt
	$(XSUM) -c data/groestl_472.txt

check_groestl_480: $(INPUT_DEPEND) data/groestl_480.txt
	$(XSUM) -c data/groestl_480.txt

check_groestl_488: $(INPUT_DEPEND) data/groestl_488.txt
	$(XSUM) -c data/groestl_488.txt

check_groestl_496: $(INPUT_DEPEND) data/groestl_496.txt
	$(XSUM) -c data/groestl_496.txt

check_groestl_504: $(INPUT_DEPEND) data/groestl_504.txt
	$(XSUM) -c data/groestl_504.txt

check_groestl_512: $(INPUT_DEPEND) data/groestl_512.txt
	$(XSUM) -c data/groestl_512.txt

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

check_jh_224: $(INPUT_DEPEND) data/jh_224.txt
	$(XSUM) -c data/jh_224.txt

check_jh_256: $(INPUT_DEPEND) data/jh_256.txt
	$(XSUM) -c data/jh_256.txt

check_jh_384: $(INPUT_DEPEND) data/jh_384.txt
	$(XSUM) -c data/jh_384.txt

check_jh_512: $(INPUT_DEPEND) data/jh_512.txt
	$(XSUM) -c data/jh_512.txt

check_keccak_224: $(INPUT_DEPEND) data/keccak_224.txt
	$(XSUM) -c data/keccak_224.txt

check_keccak_256: $(INPUT_DEPEND) data/keccak_256.txt
	$(XSUM) -c data/keccak_256.txt

check_keccak_384: $(INPUT_DEPEND) data/keccak_384.txt
	$(XSUM) -c data/keccak_384.txt

check_keccak_512: $(INPUT_DEPEND) data/keccak_512.txt
	$(XSUM) -c data/keccak_512.txt

check_kupyna_256: $(INPUT_DEPEND) data/kupyna_256.txt
	$(XSUM) -c data/kupyna_256.txt

check_kupyna_512: $(INPUT_DEPEND) data/kupyna_512.txt
	$(XSUM) -c data/kupyna_512.txt

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

check_skein_256_8: $(INPUT_DEPEND) data/skein_256_8.txt
	$(XSUM) -c data/skein_256_8.txt

check_skein_256_16: $(INPUT_DEPEND) data/skein_256_16.txt
	$(XSUM) -c data/skein_256_16.txt

check_skein_256_24: $(INPUT_DEPEND) data/skein_256_24.txt
	$(XSUM) -c data/skein_256_24.txt

check_skein_256_32: $(INPUT_DEPEND) data/skein_256_32.txt
	$(XSUM) -c data/skein_256_32.txt

check_skein_256_40: $(INPUT_DEPEND) data/skein_256_40.txt
	$(XSUM) -c data/skein_256_40.txt

check_skein_256_48: $(INPUT_DEPEND) data/skein_256_48.txt
	$(XSUM) -c data/skein_256_48.txt

check_skein_256_56: $(INPUT_DEPEND) data/skein_256_56.txt
	$(XSUM) -c data/skein_256_56.txt

check_skein_256_64: $(INPUT_DEPEND) data/skein_256_64.txt
	$(XSUM) -c data/skein_256_64.txt

check_skein_256_72: $(INPUT_DEPEND) data/skein_256_72.txt
	$(XSUM) -c data/skein_256_72.txt

check_skein_256_80: $(INPUT_DEPEND) data/skein_256_80.txt
	$(XSUM) -c data/skein_256_80.txt

check_skein_256_88: $(INPUT_DEPEND) data/skein_256_88.txt
	$(XSUM) -c data/skein_256_88.txt

check_skein_256_96: $(INPUT_DEPEND) data/skein_256_96.txt
	$(XSUM) -c data/skein_256_96.txt

check_skein_256_104: $(INPUT_DEPEND) data/skein_256_104.txt
	$(XSUM) -c data/skein_256_104.txt

check_skein_256_112: $(INPUT_DEPEND) data/skein_256_112.txt
	$(XSUM) -c data/skein_256_112.txt

check_skein_256_120: $(INPUT_DEPEND) data/skein_256_120.txt
	$(XSUM) -c data/skein_256_120.txt

check_skein_256_128: $(INPUT_DEPEND) data/skein_256_128.txt
	$(XSUM) -c data/skein_256_128.txt

check_skein_256_136: $(INPUT_DEPEND) data/skein_256_136.txt
	$(XSUM) -c data/skein_256_136.txt

check_skein_256_144: $(INPUT_DEPEND) data/skein_256_144.txt
	$(XSUM) -c data/skein_256_144.txt

check_skein_256_152: $(INPUT_DEPEND) data/skein_256_152.txt
	$(XSUM) -c data/skein_256_152.txt

check_skein_256_160: $(INPUT_DEPEND) data/skein_256_160.txt
	$(XSUM) -c data/skein_256_160.txt

check_skein_256_168: $(INPUT_DEPEND) data/skein_256_168.txt
	$(XSUM) -c data/skein_256_168.txt

check_skein_256_176: $(INPUT_DEPEND) data/skein_256_176.txt
	$(XSUM) -c data/skein_256_176.txt

check_skein_256_184: $(INPUT_DEPEND) data/skein_256_184.txt
	$(XSUM) -c data/skein_256_184.txt

check_skein_256_192: $(INPUT_DEPEND) data/skein_256_192.txt
	$(XSUM) -c data/skein_256_192.txt

check_skein_256_200: $(INPUT_DEPEND) data/skein_256_200.txt
	$(XSUM) -c data/skein_256_200.txt

check_skein_256_208: $(INPUT_DEPEND) data/skein_256_208.txt
	$(XSUM) -c data/skein_256_208.txt

check_skein_256_216: $(INPUT_DEPEND) data/skein_256_216.txt
	$(XSUM) -c data/skein_256_216.txt

check_skein_256_224: $(INPUT_DEPEND) data/skein_256_224.txt
	$(XSUM) -c data/skein_256_224.txt

check_skein_256_232: $(INPUT_DEPEND) data/skein_256_232.txt
	$(XSUM) -c data/skein_256_232.txt

check_skein_256_240: $(INPUT_DEPEND) data/skein_256_240.txt
	$(XSUM) -c data/skein_256_240.txt

check_skein_256_248: $(INPUT_DEPEND) data/skein_256_248.txt
	$(XSUM) -c data/skein_256_248.txt

check_skein_256_256: $(INPUT_DEPEND) data/skein_256_256.txt
	$(XSUM) -c data/skein_256_256.txt

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

check_skein_1024_8: $(INPUT_DEPEND) data/skein_1024_8.txt
	$(XSUM) -c data/skein_1024_8.txt

check_skein_1024_16: $(INPUT_DEPEND) data/skein_1024_16.txt
	$(XSUM) -c data/skein_1024_16.txt

check_skein_1024_24: $(INPUT_DEPEND) data/skein_1024_24.txt
	$(XSUM) -c data/skein_1024_24.txt

check_skein_1024_32: $(INPUT_DEPEND) data/skein_1024_32.txt
	$(XSUM) -c data/skein_1024_32.txt

check_skein_1024_40: $(INPUT_DEPEND) data/skein_1024_40.txt
	$(XSUM) -c data/skein_1024_40.txt

check_skein_1024_48: $(INPUT_DEPEND) data/skein_1024_48.txt
	$(XSUM) -c data/skein_1024_48.txt

check_skein_1024_56: $(INPUT_DEPEND) data/skein_1024_56.txt
	$(XSUM) -c data/skein_1024_56.txt

check_skein_1024_64: $(INPUT_DEPEND) data/skein_1024_64.txt
	$(XSUM) -c data/skein_1024_64.txt

check_skein_1024_72: $(INPUT_DEPEND) data/skein_1024_72.txt
	$(XSUM) -c data/skein_1024_72.txt

check_skein_1024_80: $(INPUT_DEPEND) data/skein_1024_80.txt
	$(XSUM) -c data/skein_1024_80.txt

check_skein_1024_88: $(INPUT_DEPEND) data/skein_1024_88.txt
	$(XSUM) -c data/skein_1024_88.txt

check_skein_1024_96: $(INPUT_DEPEND) data/skein_1024_96.txt
	$(XSUM) -c data/skein_1024_96.txt

check_skein_1024_104: $(INPUT_DEPEND) data/skein_1024_104.txt
	$(XSUM) -c data/skein_1024_104.txt

check_skein_1024_112: $(INPUT_DEPEND) data/skein_1024_112.txt
	$(XSUM) -c data/skein_1024_112.txt

check_skein_1024_120: $(INPUT_DEPEND) data/skein_1024_120.txt
	$(XSUM) -c data/skein_1024_120.txt

check_skein_1024_128: $(INPUT_DEPEND) data/skein_1024_128.txt
	$(XSUM) -c data/skein_1024_128.txt

check_skein_1024_136: $(INPUT_DEPEND) data/skein_1024_136.txt
	$(XSUM) -c data/skein_1024_136.txt

check_skein_1024_144: $(INPUT_DEPEND) data/skein_1024_144.txt
	$(XSUM) -c data/skein_1024_144.txt

check_skein_1024_152: $(INPUT_DEPEND) data/skein_1024_152.txt
	$(XSUM) -c data/skein_1024_152.txt

check_skein_1024_160: $(INPUT_DEPEND) data/skein_1024_160.txt
	$(XSUM) -c data/skein_1024_160.txt

check_skein_1024_168: $(INPUT_DEPEND) data/skein_1024_168.txt
	$(XSUM) -c data/skein_1024_168.txt

check_skein_1024_176: $(INPUT_DEPEND) data/skein_1024_176.txt
	$(XSUM) -c data/skein_1024_176.txt

check_skein_1024_184: $(INPUT_DEPEND) data/skein_1024_184.txt
	$(XSUM) -c data/skein_1024_184.txt

check_skein_1024_192: $(INPUT_DEPEND) data/skein_1024_192.txt
	$(XSUM) -c data/skein_1024_192.txt

check_skein_1024_200: $(INPUT_DEPEND) data/skein_1024_200.txt
	$(XSUM) -c data/skein_1024_200.txt

check_skein_1024_208: $(INPUT_DEPEND) data/skein_1024_208.txt
	$(XSUM) -c data/skein_1024_208.txt

check_skein_1024_216: $(INPUT_DEPEND) data/skein_1024_216.txt
	$(XSUM) -c data/skein_1024_216.txt

check_skein_1024_224: $(INPUT_DEPEND) data/skein_1024_224.txt
	$(XSUM) -c data/skein_1024_224.txt

check_skein_1024_232: $(INPUT_DEPEND) data/skein_1024_232.txt
	$(XSUM) -c data/skein_1024_232.txt

check_skein_1024_240: $(INPUT_DEPEND) data/skein_1024_240.txt
	$(XSUM) -c data/skein_1024_240.txt

check_skein_1024_248: $(INPUT_DEPEND) data/skein_1024_248.txt
	$(XSUM) -c data/skein_1024_248.txt

check_skein_1024_256: $(INPUT_DEPEND) data/skein_1024_256.txt
	$(XSUM) -c data/skein_1024_256.txt

check_skein_1024_264: $(INPUT_DEPEND) data/skein_1024_264.txt
	$(XSUM) -c data/skein_1024_264.txt

check_skein_1024_272: $(INPUT_DEPEND) data/skein_1024_272.txt
	$(XSUM) -c data/skein_1024_272.txt

check_skein_1024_280: $(INPUT_DEPEND) data/skein_1024_280.txt
	$(XSUM) -c data/skein_1024_280.txt

check_skein_1024_288: $(INPUT_DEPEND) data/skein_1024_288.txt
	$(XSUM) -c data/skein_1024_288.txt

check_skein_1024_296: $(INPUT_DEPEND) data/skein_1024_296.txt
	$(XSUM) -c data/skein_1024_296.txt

check_skein_1024_304: $(INPUT_DEPEND) data/skein_1024_304.txt
	$(XSUM) -c data/skein_1024_304.txt

check_skein_1024_312: $(INPUT_DEPEND) data/skein_1024_312.txt
	$(XSUM) -c data/skein_1024_312.txt

check_skein_1024_320: $(INPUT_DEPEND) data/skein_1024_320.txt
	$(XSUM) -c data/skein_1024_320.txt

check_skein_1024_328: $(INPUT_DEPEND) data/skein_1024_328.txt
	$(XSUM) -c data/skein_1024_328.txt

check_skein_1024_336: $(INPUT_DEPEND) data/skein_1024_336.txt
	$(XSUM) -c data/skein_1024_336.txt

check_skein_1024_344: $(INPUT_DEPEND) data/skein_1024_344.txt
	$(XSUM) -c data/skein_1024_344.txt

check_skein_1024_352: $(INPUT_DEPEND) data/skein_1024_352.txt
	$(XSUM) -c data/skein_1024_352.txt

check_skein_1024_360: $(INPUT_DEPEND) data/skein_1024_360.txt
	$(XSUM) -c data/skein_1024_360.txt

check_skein_1024_368: $(INPUT_DEPEND) data/skein_1024_368.txt
	$(XSUM) -c data/skein_1024_368.txt

check_skein_1024_376: $(INPUT_DEPEND) data/skein_1024_376.txt
	$(XSUM) -c data/skein_1024_376.txt

check_skein_1024_384: $(INPUT_DEPEND) data/skein_1024_384.txt
	$(XSUM) -c data/skein_1024_384.txt

check_skein_1024_392: $(INPUT_DEPEND) data/skein_1024_392.txt
	$(XSUM) -c data/skein_1024_392.txt

check_skein_1024_400: $(INPUT_DEPEND) data/skein_1024_400.txt
	$(XSUM) -c data/skein_1024_400.txt

check_skein_1024_408: $(INPUT_DEPEND) data/skein_1024_408.txt
	$(XSUM) -c data/skein_1024_408.txt

check_skein_1024_416: $(INPUT_DEPEND) data/skein_1024_416.txt
	$(XSUM) -c data/skein_1024_416.txt

check_skein_1024_424: $(INPUT_DEPEND) data/skein_1024_424.txt
	$(XSUM) -c data/skein_1024_424.txt

check_skein_1024_432: $(INPUT_DEPEND) data/skein_1024_432.txt
	$(XSUM) -c data/skein_1024_432.txt

check_skein_1024_440: $(INPUT_DEPEND) data/skein_1024_440.txt
	$(XSUM) -c data/skein_1024_440.txt

check_skein_1024_448: $(INPUT_DEPEND) data/skein_1024_448.txt
	$(XSUM) -c data/skein_1024_448.txt

check_skein_1024_456: $(INPUT_DEPEND) data/skein_1024_456.txt
	$(XSUM) -c data/skein_1024_456.txt

check_skein_1024_464: $(INPUT_DEPEND) data/skein_1024_464.txt
	$(XSUM) -c data/skein_1024_464.txt

check_skein_1024_472: $(INPUT_DEPEND) data/skein_1024_472.txt
	$(XSUM) -c data/skein_1024_472.txt

check_skein_1024_480: $(INPUT_DEPEND) data/skein_1024_480.txt
	$(XSUM) -c data/skein_1024_480.txt

check_skein_1024_488: $(INPUT_DEPEND) data/skein_1024_488.txt
	$(XSUM) -c data/skein_1024_488.txt

check_skein_1024_496: $(INPUT_DEPEND) data/skein_1024_496.txt
	$(XSUM) -c data/skein_1024_496.txt

check_skein_1024_504: $(INPUT_DEPEND) data/skein_1024_504.txt
	$(XSUM) -c data/skein_1024_504.txt

check_skein_1024_512: $(INPUT_DEPEND) data/skein_1024_512.txt
	$(XSUM) -c data/skein_1024_512.txt

check_skein_1024_520: $(INPUT_DEPEND) data/skein_1024_520.txt
	$(XSUM) -c data/skein_1024_520.txt

check_skein_1024_528: $(INPUT_DEPEND) data/skein_1024_528.txt
	$(XSUM) -c data/skein_1024_528.txt

check_skein_1024_536: $(INPUT_DEPEND) data/skein_1024_536.txt
	$(XSUM) -c data/skein_1024_536.txt

check_skein_1024_544: $(INPUT_DEPEND) data/skein_1024_544.txt
	$(XSUM) -c data/skein_1024_544.txt

check_skein_1024_552: $(INPUT_DEPEND) data/skein_1024_552.txt
	$(XSUM) -c data/skein_1024_552.txt

check_skein_1024_560: $(INPUT_DEPEND) data/skein_1024_560.txt
	$(XSUM) -c data/skein_1024_560.txt

check_skein_1024_568: $(INPUT_DEPEND) data/skein_1024_568.txt
	$(XSUM) -c data/skein_1024_568.txt

check_skein_1024_576: $(INPUT_DEPEND) data/skein_1024_576.txt
	$(XSUM) -c data/skein_1024_576.txt

check_skein_1024_584: $(INPUT_DEPEND) data/skein_1024_584.txt
	$(XSUM) -c data/skein_1024_584.txt

check_skein_1024_592: $(INPUT_DEPEND) data/skein_1024_592.txt
	$(XSUM) -c data/skein_1024_592.txt

check_skein_1024_600: $(INPUT_DEPEND) data/skein_1024_600.txt
	$(XSUM) -c data/skein_1024_600.txt

check_skein_1024_608: $(INPUT_DEPEND) data/skein_1024_608.txt
	$(XSUM) -c data/skein_1024_608.txt

check_skein_1024_616: $(INPUT_DEPEND) data/skein_1024_616.txt
	$(XSUM) -c data/skein_1024_616.txt

check_skein_1024_624: $(INPUT_DEPEND) data/skein_1024_624.txt
	$(XSUM) -c data/skein_1024_624.txt

check_skein_1024_632: $(INPUT_DEPEND) data/skein_1024_632.txt
	$(XSUM) -c data/skein_1024_632.txt

check_skein_1024_640: $(INPUT_DEPEND) data/skein_1024_640.txt
	$(XSUM) -c data/skein_1024_640.txt

check_skein_1024_648: $(INPUT_DEPEND) data/skein_1024_648.txt
	$(XSUM) -c data/skein_1024_648.txt

check_skein_1024_656: $(INPUT_DEPEND) data/skein_1024_656.txt
	$(XSUM) -c data/skein_1024_656.txt

check_skein_1024_664: $(INPUT_DEPEND) data/skein_1024_664.txt
	$(XSUM) -c data/skein_1024_664.txt

check_skein_1024_672: $(INPUT_DEPEND) data/skein_1024_672.txt
	$(XSUM) -c data/skein_1024_672.txt

check_skein_1024_680: $(INPUT_DEPEND) data/skein_1024_680.txt
	$(XSUM) -c data/skein_1024_680.txt

check_skein_1024_688: $(INPUT_DEPEND) data/skein_1024_688.txt
	$(XSUM) -c data/skein_1024_688.txt

check_skein_1024_696: $(INPUT_DEPEND) data/skein_1024_696.txt
	$(XSUM) -c data/skein_1024_696.txt

check_skein_1024_704: $(INPUT_DEPEND) data/skein_1024_704.txt
	$(XSUM) -c data/skein_1024_704.txt

check_skein_1024_712: $(INPUT_DEPEND) data/skein_1024_712.txt
	$(XSUM) -c data/skein_1024_712.txt

check_skein_1024_720: $(INPUT_DEPEND) data/skein_1024_720.txt
	$(XSUM) -c data/skein_1024_720.txt

check_skein_1024_728: $(INPUT_DEPEND) data/skein_1024_728.txt
	$(XSUM) -c data/skein_1024_728.txt

check_skein_1024_736: $(INPUT_DEPEND) data/skein_1024_736.txt
	$(XSUM) -c data/skein_1024_736.txt

check_skein_1024_744: $(INPUT_DEPEND) data/skein_1024_744.txt
	$(XSUM) -c data/skein_1024_744.txt

check_skein_1024_752: $(INPUT_DEPEND) data/skein_1024_752.txt
	$(XSUM) -c data/skein_1024_752.txt

check_skein_1024_760: $(INPUT_DEPEND) data/skein_1024_760.txt
	$(XSUM) -c data/skein_1024_760.txt

check_skein_1024_768: $(INPUT_DEPEND) data/skein_1024_768.txt
	$(XSUM) -c data/skein_1024_768.txt

check_skein_1024_776: $(INPUT_DEPEND) data/skein_1024_776.txt
	$(XSUM) -c data/skein_1024_776.txt

check_skein_1024_784: $(INPUT_DEPEND) data/skein_1024_784.txt
	$(XSUM) -c data/skein_1024_784.txt

check_skein_1024_792: $(INPUT_DEPEND) data/skein_1024_792.txt
	$(XSUM) -c data/skein_1024_792.txt

check_skein_1024_800: $(INPUT_DEPEND) data/skein_1024_800.txt
	$(XSUM) -c data/skein_1024_800.txt

check_skein_1024_808: $(INPUT_DEPEND) data/skein_1024_808.txt
	$(XSUM) -c data/skein_1024_808.txt

check_skein_1024_816: $(INPUT_DEPEND) data/skein_1024_816.txt
	$(XSUM) -c data/skein_1024_816.txt

check_skein_1024_824: $(INPUT_DEPEND) data/skein_1024_824.txt
	$(XSUM) -c data/skein_1024_824.txt

check_skein_1024_832: $(INPUT_DEPEND) data/skein_1024_832.txt
	$(XSUM) -c data/skein_1024_832.txt

check_skein_1024_840: $(INPUT_DEPEND) data/skein_1024_840.txt
	$(XSUM) -c data/skein_1024_840.txt

check_skein_1024_848: $(INPUT_DEPEND) data/skein_1024_848.txt
	$(XSUM) -c data/skein_1024_848.txt

check_skein_1024_856: $(INPUT_DEPEND) data/skein_1024_856.txt
	$(XSUM) -c data/skein_1024_856.txt

check_skein_1024_864: $(INPUT_DEPEND) data/skein_1024_864.txt
	$(XSUM) -c data/skein_1024_864.txt

check_skein_1024_872: $(INPUT_DEPEND) data/skein_1024_872.txt
	$(XSUM) -c data/skein_1024_872.txt

check_skein_1024_880: $(INPUT_DEPEND) data/skein_1024_880.txt
	$(XSUM) -c data/skein_1024_880.txt

check_skein_1024_888: $(INPUT_DEPEND) data/skein_1024_888.txt
	$(XSUM) -c data/skein_1024_888.txt

check_skein_1024_896: $(INPUT_DEPEND) data/skein_1024_896.txt
	$(XSUM) -c data/skein_1024_896.txt

check_skein_1024_904: $(INPUT_DEPEND) data/skein_1024_904.txt
	$(XSUM) -c data/skein_1024_904.txt

check_skein_1024_912: $(INPUT_DEPEND) data/skein_1024_912.txt
	$(XSUM) -c data/skein_1024_912.txt

check_skein_1024_920: $(INPUT_DEPEND) data/skein_1024_920.txt
	$(XSUM) -c data/skein_1024_920.txt

check_skein_1024_928: $(INPUT_DEPEND) data/skein_1024_928.txt
	$(XSUM) -c data/skein_1024_928.txt

check_skein_1024_936: $(INPUT_DEPEND) data/skein_1024_936.txt
	$(XSUM) -c data/skein_1024_936.txt

check_skein_1024_944: $(INPUT_DEPEND) data/skein_1024_944.txt
	$(XSUM) -c data/skein_1024_944.txt

check_skein_1024_952: $(INPUT_DEPEND) data/skein_1024_952.txt
	$(XSUM) -c data/skein_1024_952.txt

check_skein_1024_960: $(INPUT_DEPEND) data/skein_1024_960.txt
	$(XSUM) -c data/skein_1024_960.txt

check_skein_1024_968: $(INPUT_DEPEND) data/skein_1024_968.txt
	$(XSUM) -c data/skein_1024_968.txt

check_skein_1024_976: $(INPUT_DEPEND) data/skein_1024_976.txt
	$(XSUM) -c data/skein_1024_976.txt

check_skein_1024_984: $(INPUT_DEPEND) data/skein_1024_984.txt
	$(XSUM) -c data/skein_1024_984.txt

check_skein_1024_992: $(INPUT_DEPEND) data/skein_1024_992.txt
	$(XSUM) -c data/skein_1024_992.txt

check_skein_1024_1000: $(INPUT_DEPEND) data/skein_1024_1000.txt
	$(XSUM) -c data/skein_1024_1000.txt

check_skein_1024_1008: $(INPUT_DEPEND) data/skein_1024_1008.txt
	$(XSUM) -c data/skein_1024_1008.txt

check_skein_1024_1016: $(INPUT_DEPEND) data/skein_1024_1016.txt
	$(XSUM) -c data/skein_1024_1016.txt

check_skein_1024_1024: $(INPUT_DEPEND) data/skein_1024_1024.txt
	$(XSUM) -c data/skein_1024_1024.txt

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

check_xxhash32: $(INPUT_DEPEND) data/xxhash32.txt
	$(XSUM) -c data/xxhash32.txt

check_xxhash64: $(INPUT_DEPEND) data/xxhash64.txt
	$(XSUM) -c data/xxhash64.txt

check_xxhash3_64: $(INPUT_DEPEND) data/xxhash3_64.txt
	$(XSUM) -c data/xxhash3_64.txt

check_xxhash3_128: $(INPUT_DEPEND) data/xxhash3_128.txt
	$(XSUM) -c data/xxhash3_128.txt
