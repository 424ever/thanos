#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[])
{
  srand (time (NULL));
  FILE *file = NULL;
  if (argc >= 2)
  {
    file = fopen (argv[1], "r");
    if (file == NULL)
    {
      fprintf (stderr, "Could not open %s: %s", argv[1], strerror (errno));
      exit (1);
    }
  } else
  {
    file = stdin;
  }

  char c;
  while ((c = fgetc (file)) != EOF)
  {
    if (!isspace (c) && !iscntrl (c))
    {
      if (rand () % 2 == 0)
      {
        fputc (c, stdout);
      } else {
        fputc (' ', stdout);
      }
    } else
    {
      fputc (c, stdout);
    }
  }

  fclose (file);
}

