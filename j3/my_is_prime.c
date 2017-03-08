/*
** my_is_prime.c for 2002 swimming pool
**
** Made by gumhead
**
*/

unsigned int	my_is_prime(unsigned int a)
{
  unsigned int	i;

  if (a < 2)
    return 0;
  for (i = 2; i <= a / i; ++i)
    if (0 == a % i)
      return 0;
  return 1;
}
