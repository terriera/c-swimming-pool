/*
** main.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

int	main(int ac, char *av[])
{
  char	*base;
  char	*expr;
  int	result;
  int	error;

  if (2 > ac)
    return 0;
  expr = av[1];
  base = (3 == ac) ? av[2] : DEC_BASE;
  error = parse_expr(&expr, &result, '\0');
  if (ERR_NONE == error)
  {
    my_putnbr_base(result, base);
    my_putchar('\n');
  }
  return error;
}
