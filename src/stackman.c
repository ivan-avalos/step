/*
 * stackman.c
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
#include "stackman.h"

stack_t*
stackman_new (int capacity)
{
  stack_t *stack;
  stack = (stack_t*) malloc (sizeof(stack_t));
  /* Initialise */
  stack->elements = (double *) malloc (sizeof(double)*capacity);
  stack->size = 0;
  stack->capacity = capacity;
  return stack;
}

double
stackman_pop(stack_t* stack)
{
  double output;
  if(stack->size==0)
    {
      fprintf(stderr, "Stack error: Stack is empty.\n");
      exit (1);
    }
  output = stack->elements[stack->size-1];
  stack->size--;
  return output;
}

void
stackman_push(stack_t* stack,
	   double element)
{
  if(stack->size == stack->capacity)
    {
      fprintf (stderr, "Stack error: Stack overflow.\n");
      exit (1);
    }

  stack->elements[stack->size++] = element;
}

int
stackman_check_params(stack_t* stack,
		   int min_params)
{
  if (stack->size >= min_params)
    return 1;
  else
    {
      fprintf(stderr, "Stack error: Missing parameters: Provided %i of %i",
	      stack->size, min_params);
      exit (1);
    }
}

void
stackman_print (stack_t* stack)
{
  printf ("\n[");
  int i;
  for (i=0;i<stack->size;i++)
    {
      printf ("%lf, ", stack->elements[i]);
    }
  printf ("]\n");
}

void
stackman_free (stack_t* stack)
{
  free (stack->elements);
  free (stack);
}
