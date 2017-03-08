/*
** parse_func.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "j11.h"

struct s_parse_func
{
  const char	*name;
  int		name_size;
  int		(*func)(char **expr, int *result);
};

typedef struct s_parse_func t_parse_func;

static int	parse_factorial(char **expr, int *result)
{
  int		error;

  error = parse_expr(expr, result, ')');
  if (ERR_NONE != error)
    return error;
  *result = my_factorial(*result);
  return ERR_NONE;
}

static int	parse_fibo(char **expr, int *result)
{
  int		error;

  error = parse_expr(expr, result, ')');
  if (ERR_NONE != error)
    return error;
  *result = my_fibonacci(*result);
  return ERR_NONE;
}

static int	parse_power(char **expr, int *result)
{
  int		error;
  int		tmp;

  error = parse_expr(expr, &tmp, ',');
  if (ERR_NONE != error)
    return error;
  error = parse_expr(expr, result, ')');
  if (ERR_NONE != error)
    return error;
  *result = my_power(tmp, *result);
  return ERR_NONE;
}

static int	parse_pgcd(char **expr, int *result)
{
  int		error;
  int		tmp;

  error = parse_expr(expr, &tmp, ',');
  if (ERR_NONE != error)
    return error;
  error = parse_expr(expr, result, ')');
  if (ERR_NONE != error)
    return error;
  *result = my_pgcd(tmp, *result);
  return ERR_NONE;
}

static int	parse_ppcm(char **expr, int *result)
{
  int		error;
  int		tmp;

  error = parse_expr(expr, &tmp, ',');
  if (ERR_NONE != error)
    return error;
  error = parse_expr(expr, result, ')');
  if (ERR_NONE != error)
    return error;
  *result = my_ppcm(tmp, *result);
  return ERR_NONE;
}

static int	parse_err(char **expr, int *result)
{
  (void)expr;
  (void)result;
  return ERR_SYN;
}

static const t_parse_func parse_func[] =
{
  { "fact(", 5, parse_factorial },
  { "fibo(", 5, parse_fibo },
  { "pow(" , 4, parse_power },
  { "pgcd(", 5, parse_pgcd },
  { "ppcm(", 5, parse_ppcm },
  { NULL, 0, parse_err }
};

int	parse_function(char **expr, int *result)
{
  int	i;

  for (i = 0; NULL != parse_func[i].name ; ++i)
    if (0 == my_strncmp(*expr, parse_func[i].name, parse_func[i].name_size))
    {
      *expr += parse_func[i].name_size;
      break;
    }
  return parse_func[i].func(expr, result);
}
