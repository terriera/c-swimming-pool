/*
** my_dlist_remove_link.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_remove_link(t_dlist *list, t_dlist *link)
{
  t_dlist	*first;

  list = my_dlist_first(list);
  first = list;
  if (NULL == link)
    return list;
  if (first == link)
    first = first->next;
  while (NULL != list && link != list)
    list = list->next;
  if (NULL != list)
  {
    if (NULL != link->prev)
      link->prev->next = link->next;
    if (NULL != link->next)
      link->next->prev = link->prev;
    link->next = NULL;
    link->prev = NULL;
  }
  return first;
}
