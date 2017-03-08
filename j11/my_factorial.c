/*
** my_factorial.c for 2002 swimming pool
**
** Made by tdd
**
*/

#include "j11.h"

unsigned int	my_factorial(unsigned int n)
{
  unsigned int	result;
  unsigned int	i;

  result = 1;
  i = 0;
  while (i < n)
    result *= ++i;
  return result;
}
