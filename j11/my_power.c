/*
** my_power.c for 2002 swimming pool
**
** Made by tdd
**
*/

#include "j11.h"

int	my_power(int n, unsigned p)
{
  int	result;

  result = 1;
  while (p > 0)
  {
    if (0 != (p % 2))
      result *= n;
    n *= n;
    p /= 2;
  }
  return result;
}
