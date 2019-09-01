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
	RETURN_CHECK_UNKNOWN = 1, // At least one hash is not supported by this build of xsum
	RETURN_CHECK_INVALID = 2, // File has a different checksum
	RETURN_CHECK_MALFORMED = 3, // Invalid format while reading hashes from file
	RETURN_FILE_ERROR = 4, // Error while calculating hashes (I/O, etc.)
	RETURN_ERROR = 5 // Other errors (incorrect CLI args, etc.)
} xsum_return_t;

typedef struct {
	char *name_long; // Name of the long option (example: --encode) or NULL
	char name_short; // Name of the short option (example: -e) or 0
	bool needs_arg; // Does the option require an extra argument?
	bool found; // Set to true by xsum_argparse if this option was found in argv
	char *arg_out; // If this option takes an argument, xsum_argparse sets this to that argument (pointer into argv)
} xsum_argparse_t;

// Somewhat similar to getopt_long; remebers which arguments are input filenames
bool xsum_argparse(xsum_argparse_t *options, size_t options_count, char **argv, int argc, bool *filenames);
// Find an option by name and return its index
int xsum_find_option(xsum_argparse_t options[], size_t options_count, bool name_long, char *name);

void xsum_print_help();
void xsum_print_version();

#endif
