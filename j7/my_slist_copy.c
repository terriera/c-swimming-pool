/*
** my_slist_copy.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_copy(t_slist *list)
{
  t_slist	*first;
  t_slist	*prev;
  t_slist	*copy;

  for (first = NULL, prev = NULL; NULL != list; list = list->next)
  {
    copy = my_slist_alloc();
    if (NULL == copy)
      return NULL;
    copy->data = list->data;
    if (NULL != prev)
      prev->next = copy;
    if (NULL == first)
      first = copy;
    prev = copy;
  }
  if (NULL != prev)
    prev->next = NULL;
  return first;
}
