/*
** my_atoi.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "j2.h"

int	my_atoi(const char *str)
{
  return my_atoi_base(str, "0123456789");
}
