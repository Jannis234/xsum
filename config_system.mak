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

ifeq ($(WITH_NETTLE), 1)
CFLAGS += $(shell $(PKG_CONFIG) --cflags nettle)
LIBS += $(shell $(PKG_CONFIG) --libs nettle)
endif
