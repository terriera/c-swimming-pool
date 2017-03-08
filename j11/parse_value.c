/*
** parse_value.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

static int	parse_atom(char **expr, int *result)
{
  int		error;

  error = parse_function(expr, result);
  if (ERR_NONE != error)
  {
    error = parse_number(expr, result);
    if (ERR_NONE != error)
      return error;
  }
  return ERR_NONE;
}

int	parse_value(char **expr, int *result)
{
  int	is_neg;
  int	error;
  
  is_neg = ('-' == **expr);
  if ('+' == **expr || '-' == **expr)
    ++*expr;
  if ('(' == **expr)
  {
    ++*expr;
    error = parse_expr(expr, result, ')');
    if (ERR_NONE != error)
      return error;
  }
  else
  {
    error = parse_atom(expr, result);
    if (ERR_NONE != error)
      return error;
  }
  if (is_neg)
    *result = -*result;
  return ERR_NONE;
}
