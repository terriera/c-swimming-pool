/*
** my_dlist_length.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

unsigned int	my_dlist_length(t_dlist * list)
{
  unsigned int	length;

  list = my_dlist_first(list);
  for (length = 0; NULL != list; list = list->next)
    ++length;
  return length;
}
