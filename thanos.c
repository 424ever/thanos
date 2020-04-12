#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

struct strfile_header
{
  uint32_t str_version;
  uint32_t str_numstr;
  uint32_t  str_longlen;
  uint32_t  str_shortlen;
  uint32_t  str_flags;
  uint32_t  str_delim;
  uint32_t  *table;
}__attribute__((packed));

int main()
{
  FILE *dat_file = fopen ("/usr/share/thanos/quotes.dat", "rb");
  struct strfile_header header;

  srand (time (NULL));

  fread (&header, sizeof (header) - sizeof (header.table), 1, dat_file);

  header.str_version  = ntohl (header.str_version);
  header.str_numstr   = ntohl (header.str_numstr);
  header.str_longlen  = ntohl (header.str_longlen);
  header.str_shortlen = ntohl (header.str_shortlen);
  header.str_flags    = ntohl (header.str_flags);
  header.str_delim    = ntohl (header.str_delim);

  header.table = malloc (header.str_numstr * 4);

  size_t i;
  for (i = 0; i < header.str_numstr; ++i)
  {
    unsigned int val;
    fread (&val, 4, 1, dat_file);
    header.table[i] = ntohl(val);
  }

  fclose (dat_file);

  unsigned int quote_index;
  quote_index = rand () % header.str_numstr; 
  unsigned int len = header.table[quote_index+1] - header.table[quote_index] - 2;

  char *buf;
  buf = malloc (len+1);
  
  FILE *quotes = fopen ("/usr/share/thanos/quotes", "rb");
  fseek (quotes, header.table[quote_index], SEEK_SET);
  fread (buf, 1, len, quotes);
  buf[len] = '\0';

  fputs (buf, stdout);

  fclose (quotes);
  free (header.table);
  free (buf);

  return EXIT_SUCCESS;
}

