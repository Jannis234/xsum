/* This file is part of xsum.
 *
 * xsum is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xsum is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xsum. If not, see <http://www.gnu.org/licenses/>. */

#include <stdio.h>
#include "config.h"

void xsum_print_help() {
	 
	printf("Usage: xsum [OPTION(S)] [FILE(S)]\n");
	printf("\n");
	printf("If no file is specified, data is read from standard input\n");
	printf("\n");
	printf("  -h, --help:       Show this message and exit\n");
	printf("  -v, --version:    Show xsum's version number and exit\n");
	printf("  -c, --check:      Read checksums from FILE(S) and verify them\n");
	printf("  -q, --quiet:      Don't print status information while checking\n");
	printf("  --ignore-unknown: Don't report an error after encountering unknown checksums\n");
	printf("                    while checking\n");
	printf("  --ignore-missing: Ignore missing files while checking\n");
	printf("  -a, --algo:       Select checksums to calculate (comma-separated)\n");
	printf("  --list-algos:     List all supported checksums and exit\n");
	 
}

void xsum_print_version() {
	
	printf("xsum %s\n", XSUM_VERSION_STRING);
	printf("\n");
	printf("This program is free software; you may redistribute it under the terms of\n");
	printf("the GNU General Public License version 3 or (at your option) a later version.\n");
	printf("This program comes with absolutely no warranty.\n");
	
}
 
