/*
** handle_op.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j11.h"

struct	s_op_fct
{
  char	op;
  int	(*fct)(int *result, int op1, int op2);
};

typedef struct s_op_fct t_op_fct;

static int	handle_add(int *result, int op1, int op2)
{
  *result = op1 + op2;
  return ERR_NONE;
}

static int	handle_sub(int *result, int op1, int op2)
{
  *result = op1 - op2;
  return ERR_NONE;
}

static int	handle_mul(int *result, int op1, int op2)
{
  *result = op1 * op2;
  return ERR_NONE;
}

static int	handle_div(int *result, int op1, int op2)
{
  if (0 == op2)
    return ERR_DIV;
  *result = op1 / op2;
  return ERR_NONE;
}

static int	handle_mod(int *result, int op1, int op2)
{
  if (0 == op2)
    return ERR_DIV;
  *result = op1 % op2;
  return ERR_NONE;
}

static int	handle_err(int *result, int op1, int op2)
{
  *result = op1 = op2;
  return ERR_SYN;
}

static const t_op_fct	op_fct[] =
{
  {'+', handle_add},
  {'-', handle_sub},
  {'*', handle_mul},
  {'/', handle_div},
  {'%', handle_mod},
  {'\0', handle_err}
};

int	handle_op(int *result, char operator, int operand1, int operand2)
{
  int	i;

  for (i = 0; 0 != op_fct[i].op ; ++i)
    if (operator == op_fct[i].op)
      break;
  return op_fct[i].fct(result, operand1, operand2);
}
