/*
** my_dlist_nth.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist	*my_dlist_nth(t_dlist *list, unsigned int n)
{
  list = my_dlist_first(list);
  while (n-- && NULL != list)
    list = list->next;
  return list;
}
