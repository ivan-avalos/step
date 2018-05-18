/*
 * stepman.c
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
#include "stepman.h"

char*
step_remove_comments (char* str, size_t size)
{

  char* output;
  output = (char*) malloc (sizeof(char)*(size+1));

  char comment;
  size_t final = 0;
  size_t i;
  for (i=0;i<size;i++)
    {
      if (str[i] == '{')
	comment = 1;
      else if (str[i] == '}')
	comment = 0;
      else if (!comment)
	{
	  output[final] = str[i];
	  final++;
	}
    }
  output[final+1] = '\0';

  /*printf ("\n---\n%s\n---\n", output);*/

  free (str);
  return output;
}

void
step_eval(char* atom,
	  stack_t* stack)
{
  if(strncmp(atom, "+", 1) == 0)
    step_sum (stack);
  else if(strncmp(atom, "-", 1) == 0)
    step_sub (stack);
  else if(strncmp(atom, "*", 1) == 0)
    step_mul (stack);
  else if(strncmp(atom, "/", 1) == 0)
    step_div (stack);
  else if(strncmp(atom, "sin", 3) == 0)
    step_sin (stack);
  else if(strncmp(atom, "cos", 3) == 0)
    step_cos (stack);
  else if(strncmp(atom, "tan", 3) == 0)
    step_tan (stack);
  else if(strncmp(atom, "pow", 3) == 0)
    step_pow (stack);
  else if(strncmp(atom, "sqrt", 4) == 0)
    step_sqrt (stack);
  else if(strncmp (atom, "!", 1) == 0)
    step_clr (stack);
  else if(strncmp (atom, "#$", 2) == 0)
    step_pout (stack);
  else if(strncmp (atom, "#", 1) == 0)
    step_pop (stack);
  else
    step_push (stack, atom);

  /* stack_print (stack); */
}

void
step_sum (stack_t* stack)
{
  /* params: 2 */
  stackman_check_params(stack, 2);
  double result;
  result = stackman_pop(stack) + stackman_pop(stack);
  stackman_push(stack, result);  
}

void
step_sub (stack_t* stack)
{
  /* params: 2 */
  stackman_check_params(stack, 2);
  double result;
  result = stackman_pop(stack) - stackman_pop(stack);
  stackman_push(stack, result);
}

void
step_mul (stack_t* stack)
{
  /* params: 2 */
  stackman_check_params(stack, 2);
  double result;
  result = stackman_pop(stack) * stackman_pop(stack);
  stackman_push(stack, result);
}

void
step_div (stack_t* stack)
{
  /* params: 2 */
  stackman_check_params(stack, 2);
  double result;
  result = stackman_pop(stack) / stackman_pop(stack);
  stackman_push(stack, result);
}

void
step_sin (stack_t* stack)
{
  /* params: 1 */
  stackman_check_params (stack, 1);
  double result;
  result = sin(math_degrees_to_radians(stackman_pop(stack)));
  stackman_push (stack, result);
}

void
step_cos (stack_t* stack)
{
  /* params: 1 */
  stackman_check_params (stack, 1);
  double result;
  result = cos(math_degrees_to_radians(stackman_pop(stack)));
  stackman_push (stack, result);
}

void
step_tan (stack_t* stack)
{
  /* params: 1 */
  stackman_check_params (stack, 1);
  double result;
  result = tan(math_degrees_to_radians(stackman_pop(stack)));
  stackman_push (stack, result);
}

void
step_pow (stack_t* stack)
{
  /* params: 2 */
  stackman_check_params (stack, 2);
  double result;
  double x = stackman_pop (stack);
  double y = stackman_pop (stack);
  result = pow (x, y);
  stackman_push (stack, result);
}

void
step_sqrt (stack_t* stack)
{
  /* params: 1 */
  stackman_check_params (stack, 1);
  double result;
  result = sqrt (stackman_pop (stack));
  stackman_push (stack, result);
}

void
step_clr (stack_t* stack)
{
  int i;
  for(i=0;i<stack->size;i++)
    stackman_pop (stack);
}

void
step_pout (stack_t* stack)
{
  stackman_check_params (stack, 1);
  printf ("%lf\n", stackman_pop (stack));
}

void
step_pop (stack_t* stack)
{
  stackman_check_params (stack, 1);
  stackman_pop (stack);
}

void
step_push (stack_t* stack,
	   char* atom)
{
  double value;
  sscanf (atom, "%lf", &value);
  stackman_push (stack, value);
}
