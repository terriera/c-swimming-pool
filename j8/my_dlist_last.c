/*
** my_dlist_last.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist	*my_dlist_last(t_dlist *list)
{
  if (NULL != list)
    while (NULL != list->next)
      list = list->next;
  return list;
}
