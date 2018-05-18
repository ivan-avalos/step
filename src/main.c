/*
 * main.c
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "fileman.h"
#include "stackman.h"
#include "stepman.h"

void print_help (char* arg0, int rc);

int
main (int argc,
	  char** argv)
{
	
  int iflag = 0;
  char* filename = NULL;
	
  char c;
  while ((c = getopt(argc, argv, "hi:")) != -1)
	{
	  switch (c)
		{
		case 'i':
			iflag = 1;
			filename = optarg;
			break;
		case 'h':
			print_help (argv[0], 0);
			break;
		case '?':
			if (optopt == 'i')
			fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint(optopt))
			fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			else
			fprintf (stderr, "Unknown option `\\x%x'.\n", optopt);

			print_help (argv[0], 1);
		default:
			abort ();
		}
	}

  if(!iflag)
		print_help (argv[0], 1);

  fileman_open_file (filename);

  stack_t* stack;
  stack = stackman_new (255);
  
  /* Remove comments */
  content = step_remove_comments (content, infile_size);

  /* Split into atoms */
  char* cc;
  cc = strtok (content, " \n\t");
  while (cc != NULL)
	{
	  step_eval (cc, stack);
	  cc = strtok (NULL, " \n\t");
	}

  /* Free the malloc */
  stackman_free (stack);
  free (content);

  return (0);
}

void
print_help (char* arg0,
            int rc)
{
	printf (
"Usage:  %s -i <file>\n"
"Or:     %s -h\n\n"
"Options:\n"
"  -i <file> Input file for Step\n"
"  -h        Show this help menu\n", arg0, arg0, arg0);
	exit (0);
}
