/*
** my_slist_append.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_prepend(t_slist *list, void *data)
{
  t_slist	*new;

  new = my_slist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  new->next = list;
  return new;
}
