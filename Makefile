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

include config_system.mak

CFLAGS += $(CCFLAGS) -Wall -std=c99 -Isrc/include

SRC = src/main.c \
	src/argparse.c \
	src/byteswap.c \
	src/help.c \
	src/parse.c \
	src/process.c \
	src/algos.c \
	src/algos/adler_32.c \
	src/algos/blake2s_128.c \
	src/algos/blake2s_160.c \
	src/algos/blake2s_224.c \
	src/algos/blake2s_256.c \
	src/algos/blake2b_128.c \
	src/algos/blake2b_136.c \
	src/algos/blake2b_144.c \
	src/algos/blake2b_152.c \
	src/algos/blake2b_160.c \
	src/algos/blake2b_168.c \
	src/algos/blake2b_176.c \
	src/algos/blake2b_184.c \
	src/algos/blake2b_192.c \
	src/algos/blake2b_200.c \
	src/algos/blake2b_208.c \
	src/algos/blake2b_216.c \
	src/algos/blake2b_224.c \
	src/algos/blake2b_232.c \
	src/algos/blake2b_240.c \
	src/algos/blake2b_248.c \
	src/algos/blake2b_256.c \
	src/algos/blake2b_264.c \
	src/algos/blake2b_272.c \
	src/algos/blake2b_280.c \
	src/algos/blake2b_288.c \
	src/algos/blake2b_296.c \
	src/algos/blake2b_304.c \
	src/algos/blake2b_312.c \
	src/algos/blake2b_320.c \
	src/algos/blake2b_328.c \
	src/algos/blake2b_336.c \
	src/algos/blake2b_344.c \
	src/algos/blake2b_352.c \
	src/algos/blake2b_360.c \
	src/algos/blake2b_368.c \
	src/algos/blake2b_376.c \
	src/algos/blake2b_384.c \
	src/algos/blake2b_392.c \
	src/algos/blake2b_400.c \
	src/algos/blake2b_408.c \
	src/algos/blake2b_416.c \
	src/algos/blake2b_424.c \
	src/algos/blake2b_432.c \
	src/algos/blake2b_440.c \
	src/algos/blake2b_448.c \
	src/algos/blake2b_456.c \
	src/algos/blake2b_464.c \
	src/algos/blake2b_472.c \
	src/algos/blake2b_480.c \
	src/algos/blake2b_488.c \
	src/algos/blake2b_496.c \
	src/algos/blake2b_504.c \
	src/algos/blake2b_512.c \
	src/algos/crc32.c \
	src/algos/gost94.c \
	src/algos/md2.c \
	src/algos/md4.c \
	src/algos/md5.c \
	src/algos/ripemd160.c \
	src/algos/sha1.c \
	src/algos/sha224.c \
	src/algos/sha256.c \
	src/algos/sha384.c \
	src/algos/sha512.c \
	src/algos/sha512_224.c \
	src/algos/sha512_256.c \
	src/algos/sha3_224.c \
	src/algos/sha3_256.c \
	src/algos/sha3_384.c \
	src/algos/sha3_512.c \
	src/algos/streebog_256.c \
	src/algos/streebog_512.c \
	src/algos/sum.c \
	src/algos/tiger.c \
	src/algos/tiger2.c \
	src/algos/whirlpool.c \
	src/algos/xor.c

.PHONY: all depend clean cli man install install-cli install-man uninstall

all: cli man

depend: depend.mak

cli: xsum$(EXEEXT)

man: xsum.1

install: install-cli install-man

install-cli: cli
	mkdir -p $(BINDIR)
	$(INSTALL) xsum$(EXEEXT) $(BINDIR)

install-man: man
	mkdir -p $(MANDIR)
	$(INSTALL) -m 644 xsum.1 $(MANDIR)/man1

uninstall:
	rm -f $(BINDIR)/xsum$(EXEEXT)
	rm -f $(MANDIR)/man1/xsum.1

clean:
	rm -f $(SRC:.c=.o) $(SRC:.c=.d)
	rm -f xsum$(EXEEXT)
	rm -f xsum.1
	rm -f depend.mak
	rm -f src/include/config_generated.h

xsum$(EXEEXT): $(SRC:.c=.o)
	$(CCLD) $(LDFLAGS) -o xsum$(EXEEXT) $(SRC:.c=.o) $(LIBS)

xsum.1: xsum$(EXEEXT)
	$(HELP2MAN) -N ./xsum$(EXEEXT) -o xsum.1

depend.mak: $(SRC:.c=.d)
	cat $(SRC:.c=.d) > depend.mak

src/include/config_generated.h: config_build.mak src/gen_config.sh
	sh src/gen_config.sh $(XSUM_VERSION) $(WITH_MBEDTLS) $(WITH_NETTLE) $(WITH_LIBGCRYPT) $(WITH_LIBSODIUM) $(WITH_ZLIB) > src/include/config_generated.h

%.d: %.c config_build.mak config_system.mak src/include/config_generated.h
	$(CC) $(CFLAGS) -M -MT $(<:.c=.o) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

include depend.mak
