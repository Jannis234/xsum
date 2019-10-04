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

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void rand_next(uint32_t *i) {
	
	// Simple LFSR-based PRNG for reproducible pseudorandom data
	uint32_t bit = ((*i >> 31) & 1) ^ ((*i >> 21) & 1) ^ ((*i >> 1) & 1) ^ (*i & 1);
	*i = (*i >> 1) | (bit << 31);
	
}

int main(int argc, char **argv) {
	
	FILE *fd;
	
	// Simple ASCII-only string
	fd = fopen("input/string1", "wb");
	if (fd == NULL) {
		return 1;
	}
	char *string = "abc";
	if (fwrite(string, 1, strlen(string), fd) != strlen(string)) {
		fclose(fd);
		return 1;
	}
	fclose(fd);
	string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	fd = fopen("input/string2", "wb");
	if (fd == NULL) {
		return 1;
	}
	if (fwrite(string, 1, strlen(string), fd) != strlen(string)) {
		fclose(fd);
		return 1;
	}
	fclose(fd);
	
	// Simple binary file
	fd = fopen("input/binary1", "wb");
	if (fd == NULL) {
		return 1;
	}
	uint8_t b = 0;
	while (b < 255) {
		if (fwrite(&b, 1, 1, fd) != 1) {
			fclose(fd);
			return 1;
		}
		b++;
	}
	if (fwrite(&b, 1, 1, fd) != 1) {
		fclose(fd);
		return 1;
	}
	fclose(fd);
	fd = fopen("input/binary2", "wb");
	if (fd == NULL) {
		return 1;
	}
	int count = 100;
	while (count > 0) {
		b = 0;
		while (b < 255) {
			if (fwrite(&b, 1, 1, fd) != 1) {
				fclose(fd);
				return 1;
			}
			b++;
		}
		if (fwrite(&b, 1, 1, fd) != 1) {
			fclose(fd);
			return 1;
		}
		count--;
	}
	fclose(fd);
	
	// Large file (10 + 50MiB)
	fd = fopen("input/large1", "wb");
	if (fd == NULL) {
		return 1;
	}
	uint32_t size = 1024 * 1024 * 10;
	char c = 'a';
	while (size > 0) {
		if (fwrite(&c, 1, 1, fd) != 1) {
			fclose(fd);
			return 1;
		}
		size--;
	}
	fclose(fd);
	fd = fopen("input/large2", "wb");
	if (fd == NULL) {
		return 1;
	}
	size = 1024 * 1024 * 50;
	c = 'a';
	while (size > 0) {
		if (fwrite(&c, 1, 1, fd) != 1) {
			fclose(fd);
			return 1;
		}
		size--;
	}
	fclose(fd);
	
	// Pseudorandom data (1 MiB + 512 KiB)
	fd = fopen("input/random1", "wb");
	if (fd == NULL) {
		return 1;
	}
	size = 1024 * 1024;
	uint32_t lfsr = 0x5853554DU; // "XSUM" (all upper case)
	while (size > 0) {
		rand_next(&lfsr);
		b = lfsr & 255;
		if (fwrite(&b, 1, 1, fd) != 1) {
			fclose(fd);
			return 1;
		}
		size--;
	}
	fclose(fd);
	fd = fopen("input/random2", "wb");
	if (fd == NULL) {
		return 1;
	}
	size = 1024 * 512;
	lfsr = 0x7873756DU; // "xsum" (all lower case)
	while (size > 0) {
		rand_next(&lfsr);
		b = lfsr & 255;
		if (fwrite(&b, 1, 1, fd) != 1) {
			fclose(fd);
			return 1;
		}
		size--;
	}
	fclose(fd);
	
	// Empty input
	fd = fopen("input/empty", "wb");
	if (fd == NULL) {
		return 1;
	}
	fclose(fd);
	
	return 0;
	
}
