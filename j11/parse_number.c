/*
** parse_number.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

static int	find_in_base(char c, const char *base)
{
  int		i;

  for (i = 0; '\0' != base[i]; ++i)
    if (base[i] == c)
      return i;
  return -1;
}

static long int	my_strtol(char *nptr, char **endptr, const char *base)
{
  long int	result = 0;
  int		length;
  int		index;
  char		*p;

  *endptr = nptr;
  length = my_strlen(base);
  p = nptr;
  if (1 == length)
    while (*base == *nptr)
    {
      ++result;
      ++nptr;
    }
  else
    while (-1 != (index = find_in_base(*nptr, base)))
    {
      result = result * length + index;
      ++nptr;
    }
  if (p != nptr)
    *endptr = nptr;
  return result;
}

static int	my_isoperator(char c)
{
  return ('\0' == c || ':' == c || '+' == c || '-' == c || '*' == c
          || '/' == c || '%' == c);
}

static char	*parse_base(char *expr, char *base)
{
  char		*p;

  p = expr;
  while (!my_isoperator(*expr))
    ++expr;
  if (':' == *expr)
  {
    my_strncpy(base, p, expr - p + 1);
    base[expr - p] = '\0';
    ++expr;
  }
  else
  {
    my_strncpy(base, DEC_BASE, 11);
    expr = p;
  }
  return expr;
}

int	parse_number(char **expr, int *result)
{
  char	base[128];
  char	*end;

  *expr = parse_base(*expr, base);
  *result = my_strtol(*expr, &end, base);
  if (*expr == end && '\0' != base[1])
    return ERR_SYN;
  *expr = end;
  return ERR_NONE;
}
