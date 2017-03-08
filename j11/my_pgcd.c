/*
** my_pgcd.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

unsigned int	my_pgcd(unsigned int a, unsigned int b)
{
  while (a != b)
    if (a > b)
      a = a - b;
    else
      b = b - a;
  return a;
}
