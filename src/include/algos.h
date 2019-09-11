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

#ifndef __XSUM_ALGOS_H__
#define __XSUM_ALGOS_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "config.h"

typedef void* (*xsum_func_init_t)(); // Initialize the internal state, return a pointer to that state
typedef void (*xsum_func_update_t)(void* state, uint8_t* buf, size_t len); // Process len bytes from buf
typedef uint8_t* (*xsum_func_final_t)(void* state); // Finalize calculation, free memory, return the final hash (or NULL on error)

typedef struct {
	char *name; // Algorithm name (for CLI)
	int length; // Output length in bytes
	xsum_func_init_t func_init;
	xsum_func_update_t func_update;
	xsum_func_final_t func_final;
} xsum_algo_t;

extern xsum_algo_t *xsum_algos[];

#endif
