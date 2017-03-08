/*
** my_power.c for 2002 swimming pool
**
** Made by gumhead
**
*/

unsigned int	my_power(int a, unsigned int p)
{
  unsigned int	result = 1;

  while (p > 0)
  {
    if (0 != (p % 2))
      result *= a;
    a *= a;
    p /= 2;
  }
  return result;
}
