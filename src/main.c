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

#include <stdbool.h>
#include "cli.h"

int main(int argc, char **argv) {
	
	xsum_argparse_t options[] = {
		{ "help", 'h', false, false, NULL },
		{ "version", 'v', false, false, NULL },
		{ "check", 'c', false, false, NULL },
		{ "quiet", 'q', false, false, NULL },
		{ "algo", 'a', true, false, NULL },
		{ "ignore-unknown", 0, false, false, NULL }
	};
	size_t options_count = sizeof(options) / sizeof(xsum_argparse_t);
	if (!xsum_argparse(options, options_count, argv, argc)) {
		return RETURN_ERROR;
	}
	
	if (options[xsum_find_option(options, options_count, false, "h")].found) {
		xsum_print_help();
		return RETURN_OK;
	} else if (options[xsum_find_option(options, options_count, false, "v")].found) {
		xsum_print_version();
		return RETURN_OK;
	}
	
	return 0;
	
}
