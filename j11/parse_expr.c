/*
** parse_expr.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

int	parse_expr(char **expr, int *result, char last)
{
  int	error;

  error = parse_add(expr, result);
  if (ERR_NONE != error)
    return error;
  if (last != **expr)
    return ',' == last ? ERR_ARG : ERR_SYN;
  ++*expr;
  return 0;
}
