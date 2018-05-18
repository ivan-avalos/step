/*
 * stackman.h
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
#ifndef _STACKMAN_H_
#define _STACKMAN_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t
{
  int capacity;
  int size;
  double *elements;
}stack_t;

stack_t* stackman_new (int capacity);
double stackman_pop(stack_t* stack);
void stackman_push(stack_t* stack, double element);
int stackman_check_params(stack_t* stack, int min_params);
void stackman_print (stack_t* stack);
void stackman_free (stack_t* stack);

#endif
