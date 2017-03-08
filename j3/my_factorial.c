/*
** my_factorial.c for 2002 swimming pool
**
** Made by gumhead
**
*/

unsigned int	my_factorial(unsigned int a)
{
  unsigned int	result;

  result = 1;
  while (a >= 2)
    result *= a--;
  return result;
}
