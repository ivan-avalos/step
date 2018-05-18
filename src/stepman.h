/*
 * stepman.h
 *
 * Copyright (C) 2018 - Ivan Avalos
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _STEPMAN_H_
#define _STEPMAN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stackman.h"
#include "mathman.h"

char* step_remove_comments (char* str, size_t size);
void step_eval(char* atom, stack_t* stack);

/* Operations */
void step_sum (stack_t* stack);
void step_sub (stack_t* stack);
void step_mul (stack_t* stack);
void step_div (stack_t* stack);
void step_sin (stack_t* stack);
void step_cos (stack_t* stack);
void step_tan (stack_t* stack);
void step_pow (stack_t* stack);
void step_sqrt (stack_t* stack);
void step_clr (stack_t* stack);
void step_pout (stack_t* stack);
void step_pop (stack_t* stack);
void step_push (stack_t* stack, char* atom);

#endif
