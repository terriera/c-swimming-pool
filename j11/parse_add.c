/*
** parse_add.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

int	parse_add(char **expr, int *result)
{
  int	error;
  int	tmp;
  char	op;

  if (ERR_NONE != (error = parse_mul(expr, result)))
    return error;
  while ('+' == **expr || '-' == **expr)
  {
    tmp = *result;
    op = **expr;
    ++*expr;
    if (ERR_NONE != (error = parse_mul(expr, result)))
      return error;
    if (ERR_NONE != (error = handle_op(result, op, tmp, *result)))
      return error;
  }
  return ERR_NONE;
}
