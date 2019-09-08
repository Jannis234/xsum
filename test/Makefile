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

CHECKS = check_md5

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

check_md5: $(INPUT_DEPEND) data/md5.txt
	$(XSUM) -c data/md5.txt
