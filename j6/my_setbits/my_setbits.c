/*
** my_setbits.c for 2002 swimming pool
**
** Made by gumhead
**
*/

unsigned int	my_setbits(unsigned nb, int n, int p, unsigned x)
{
  unsigned int	mask;

  mask = ~(~0 << p);
  return ((x & mask) << n) | (nb & ~(mask << n));
}
