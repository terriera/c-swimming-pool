/*
** my_putstr.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j2.h"

void	my_putstr(const char *str)
{
  int	length;

  length = 0;
  while ('\0' != str[length])
    ++length;
  write(1, str, length);
}
