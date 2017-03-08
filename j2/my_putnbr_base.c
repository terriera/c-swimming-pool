/*
** my_putnbr_base.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j2.h"

static unsigned int	my_strlen(const char *str)
{
  unsigned int		count;

  count = 0;
  while(*str++)
    ++count;
  return count;
}

/*
** my_putnbr_base uses unsigned integers instead of working directly on nbr
** so that it can overcome the -INT_MIN overflow.
** It as also been arbitrary decided that in base one, a number n
** is just n occurences of the character in that base.
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
