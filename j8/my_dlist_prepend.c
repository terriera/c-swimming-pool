/*
** my_dlist_prepend.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_prepend(t_dlist *list, void *data)
{
  t_dlist	*new;

  new = my_dlist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  new->next = my_dlist_first(list);
  if (NULL != new->next)
    new->next->prev = new;
  new->prev = NULL;
  return new;
}
