/*
** my_dlist_append.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_append(t_dlist *list, void *data)
{
  t_dlist	*new;
  t_dlist	*first;

  new = my_dlist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  first = my_dlist_first(list);
  list = my_dlist_last(list);
  if (NULL == list || NULL == first)
    return new;
  list->next = new;
  new->prev = list;
  return first;
}
