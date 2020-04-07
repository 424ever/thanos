#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* Supercalifragilisticexpialidocious has 34 letters. 
 * hope noone wants to print a longer word than that.
 */
#define MAX_LINE_LEN 34

void print_line (char str[]);
void print_heading (void);
void print_body (void);

int main (int argc, char *argv[])
{
  char line [MAX_LINE_LEN + 1];
  line [0] = '\0';
  char word [MAX_LINE_LEN + 1];
  FILE *stream = NULL;

  if (argc > 1)
  {
    stream = fopen (argv [1], "r");
    if (stream == NULL)
    {
      fprintf (stderr, "thanossay: Could not open %s:%s\n", argv[1], strerror (errno));
      exit (1);
    }
  } else {
    stream = stdin;
  }
  print_heading();
  while (fscanf (stream, "%s", word) != EOF)
  {
    if (strlen (line) + strlen (word) > MAX_LINE_LEN - 2) 
    {
      line [strlen (line)] = '\0';
      print_line (line);

      line [0] = '\0';
      strcat (line, word);
    } else if (fgetc (stream) == '\n')
    {
      strcat (line, " ");
      strcat (line, word);
      print_line (line);
      line [0] = '\0';
    } else if (strlen (line) > 0)
    {
      strcat (line, " ");
      strcat (line, word);
    } else // We need to handle the beginning of a line
           // seperately, or else there is a space
           // at the beginning of the first line
      strcat (line, word);
  }
  if (strlen (line) > 0)
  {
    print_line (line);
  }

  print_body();

  fclose (stream);
}

void print_line (char str[])
{
  int spaces = MAX_LINE_LEN - strlen (str) - 1;
  fprintf (stdout, " | %s%*s |\n", str, spaces, "");
}

void print_heading (void)
{
  fprintf (stdout, " +-----------------------------------+\n");
}

void print_body (void)
{
  /*
   * TODO: Good ASCII art of thanos
   */
  fprintf (stdout, " +-----------------------------------+\n"
                   "       \\ \n"
                   "        \\ \n"
                   "         \\    ___\n"
                   "          \\  /   \\\n"
                   "           \\ |o o|\n"
                   "            \\| - |\n"
                   "             |,,,|\n"
                   "             \\---/\n"
                   );
}

