/*
** my_putnbr_base.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

/*
** my_putnbr_base uses unsigned integers instead of working directly on nbr
** so that in can overcome the -INT_MIN overflow.
*/
void		my_putnbr_base(int nbr, const char *base)
{
  unsigned int	n;
  unsigned int	divisor;
  unsigned int	base_length;

  n = (0 > nbr) ? -nbr : nbr;
  base_length = my_strlen(base);
  divisor = 1;
  if (0 > nbr)
    my_putchar('-');
  if (1 == base_length)
  {
    while (n--)
      my_putchar(*base);
    return;
  }
  while ((n / divisor) >= base_length)
    divisor *= base_length;
  while (1 <= divisor)
  {
    my_putchar(base[n / divisor]);
    n %= divisor;
    divisor /= base_length;
  }
}
