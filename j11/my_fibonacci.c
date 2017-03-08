/*
** my_fibonacci.c for 2002 swimming pool
**
** Made by gumhead
**
*/
#include "j11.h"

unsigned int	my_fibonacci(unsigned int n)
{
  unsigned int  lo;
  unsigned int	hi;

  if (0 == n)
    return 0;
  for (lo = 0, hi = 1; n >= 2; --n)
  {
    hi += lo;
    lo  = hi - lo;
  }
  return hi;
}
