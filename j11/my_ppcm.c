/*
** my_ppcmc for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

unsigned int	my_ppcm(unsigned int a, unsigned int b)
{
  return a * b / my_pgcd(a, b);
}
