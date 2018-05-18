/*
 * fileman.c
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
#include "fileman.h"

void
fileman_open_file (char* filename)
{
  if ((infile = fopen(filename, "r")) == NULL)
    {
      fprintf(stderr, "Error: Cannot open input file.\n");
      abort ();
    }

  /* Size */
  fseek (infile, 0L, SEEK_END);
  infile_size = ftell (infile);
  rewind (infile);

  content = (char* ) malloc (sizeof(char)*infile_size);
  
  /* Start reading */
  fread (content, sizeof (char), infile_size, infile);

  fclose (infile);
}
