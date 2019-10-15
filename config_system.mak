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

include config_build.mak

# Host-specific options (programs, paths, etc.)

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man
DESKTOPDIR = $(PREFIX)/share/applications
ICONDIR = $(PREFIX)/share/icons

BUILD = 
CC = $(BUILD)gcc
CCLD = $(CC)
AR = $(BUILD)ar
RANLIB = $(BUILD)ranlib
PKG_CONFIG = $(BUILD)pkg-config
HELP2MAN = help2man
INSTALL = install

CCFLAGS = -O2 -pipe -ggdb
LDFLAGS = 
LIBS = 
EXEEXT = 

ifeq ($(WITH_OPENMP), 1)
CFLAGS += -fopenmp
LDFLAGS += -fopenmp
endif

ifeq ($(WITH_BOTAN), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags botan-2)
LIBS += $(shell $(PKG_CONFIG) --libs botan-2)
endif

ifeq ($(WITH_GLIB), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags glib-2.0)
LIBS += $(shell $(PKG_CONFIG) --libs glib-2.0)
endif

ifeq ($(WITH_GNUTLS), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags gnutls)
LIBS += $(shell $(PKG_CONFIG) --libs gnutls)
endif

ifeq ($(WITH_MBEDTLS), 1)
LIBS += -lmbedcrypto
endif

ifeq ($(WITH_MHASH), 1)
LIBS += -lmhash
endif

ifeq ($(WITH_NETTLE), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags nettle)
LIBS += $(shell $(PKG_CONFIG) --libs nettle)
endif

ifeq ($(WITH_NSS), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags nss)
LIBS += $(shell $(PKG_CONFIG) --libs nss)
endif

ifeq ($(WITH_LIBB2), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags libb2)
LIBS += $(shell $(PKG_CONFIG) --libs libb2)
endif

ifeq ($(WITH_LIBGCRYPT), 1)
CFLAGS += $(shell $(BUILD)libgcrypt-config --cflags)
LIBS += $(shell $(BUILD)libgcrypt-config --libs)
endif

ifeq ($(WITH_LIBLZMA), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags liblzma)
LIBS += $(shell $(PKG_CONFIG) --libs liblzma)
endif

ifeq ($(WITH_LIBSODIUM), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags libsodium)
LIBS += $(shell $(PKG_CONFIG) --libs libsodium)
endif

ifeq ($(WITH_OPENSSL), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags libcrypto)
LIBS += $(shell $(PKG_CONFIG) --libs libcrypto)
endif

ifeq ($(WITH_RHASH), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags librhash)
LIBS += $(shell $(PKG_CONFIG) --libs librhash)
endif

ifeq ($(WITH_XXHASH), 1)
LIBS += -lxxhash
endif

ifeq ($(WITH_ZLIB), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags zlib)
LIBS += $(shell $(PKG_CONFIG) --libs zlib)
endif

ifeq ($(WITH_WINDOWS_CNG), 1)
LIBS += -lbcrypt
endif
