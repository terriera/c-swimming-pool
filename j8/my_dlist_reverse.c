/*
** my_dlist_reverse.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_reverse(t_dlist *list)
{
  t_dlist	*prev;
  t_dlist	*next;

  prev = NULL;
  list = my_dlist_first(list);
  while (NULL != list)
  {
    next = list->next;
    list->next = prev;
    list->prev = next;
    prev = list;
    list = next;
  }
  return prev;
}
