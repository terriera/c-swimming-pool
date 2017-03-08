/*
** my_slist_append.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_append(t_slist *list, void *data)
{
  t_slist	*new;
  t_slist	*first;

  first = list;
  new = my_slist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  list = my_slist_last(list);
  if (NULL != list)
    list->next = new;
  else
    first = new;
  return first;
}
