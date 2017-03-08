/*
** my_dlist_copy.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_copy(t_dlist *list)
{
  t_dlist	*first;
  t_dlist	*prev;
  t_dlist	*copy;

  list = my_dlist_first(list);
  for (first = NULL, prev = NULL; NULL != list; list = list->next)
  {
    copy = my_dlist_alloc();
    if (NULL == copy)
      return NULL;
    copy->data = list->data;
    if (NULL != prev)
    {
      prev->next = copy;
      copy->prev = prev;
    }
    if (NULL == first)
    {
      first = copy;
      first->prev = NULL;
    }
    prev = copy;
  }
  if (NULL != prev)
    prev->next = NULL;
  return first;
}
