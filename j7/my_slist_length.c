/*
** my_slist_length.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

unsigned int	my_slist_length(t_slist * list)
{
  unsigned int	result;

  for (result = 0; NULL != list; list = list->next)
    ++result;
  return result;
}
