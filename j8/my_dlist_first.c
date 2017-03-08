/*
** my_dlist_first.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist	*my_dlist_first(t_dlist *list)
{
  if (NULL != list)
    while (NULL != list->prev)
      list = list->prev;
  return list;
}
