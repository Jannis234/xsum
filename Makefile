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
	src/help.c \
	src/process.c \
	src/algos.c \
	src/algos/md5.c

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
	sh src/gen_config.sh $(XSUM_VERSION) $(WITH_NETTLE) > src/include/config_generated.h

%.d: %.c config_build.mak config_system.mak src/include/config_generated.h
	$(CC) $(CFLAGS) -M -MT $(<:.c=.o) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

include depend.mak
