/*
** my_putstr.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

void	my_putstr(const char *str)
{
  while (*str)
    my_putchar(*str++);
}
