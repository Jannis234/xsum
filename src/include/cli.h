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

#ifndef __XSUM_CLI_H__
#define __XSUM_CLI_H__

#include <stddef.h>

typedef enum {
	RETURN_OK = 0,
	RETURN_CHECK_INVALID = 1, // File has a different checksum
	RETURN_CHECK_ERROR = 2, // Error during check
	RETURN_ERROR = 3 // Other errors (incorrect CLI args, etc.)
} xsum_return_t;

typedef struct {
	char *name_long; // Name of the long option (example: --encode) or NULL
	char name_short; // Name of the short option (example: -e) or 0
	bool needs_arg; // Does the option require an extra argument?
	bool found; // Set to true by xsum_argparse if this option was found in argv
	char *arg_out; // If this option takes an argument, xsum_argparse sets this to that argument (pointer into argv)
} xsum_argparse_t;

// Somewhat similar to getopt_long
bool xsum_argparse(xsum_argparse_t *options, size_t options_count, char **argv, int argc);
// Find an option by name and return its index
int xsum_find_option(xsum_argparse_t options[], size_t options_count, bool name_long, char *name);

void xsum_print_help();
void xsum_print_version();

#endif
