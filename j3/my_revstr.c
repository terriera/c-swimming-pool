/*
** my_revstr.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j3.h"

void		my_revstr(char *dest, const char *src)
{
  unsigned	length;
  unsigned	i;
  char		c;

  length = my_strlen(src);
  dest[length] = '\0';
  if (src == dest)
    for (i = 0; i < length; ++i)
    {
      c = dest[--length];
      dest[length] = dest[i];
      dest[i] = c;
    }
  else
    while ('\0' != *src)
      dest[--length] = *src++;
}
