/*
** my_dlist_insert.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_insert(t_dlist *list, void *data, int position)
{
  t_dlist	*new;
  t_dlist	*backup;
  t_dlist	*first;

  if (0 == position || NULL == list)
    return my_dlist_prepend(list, data);
  if (position < 0)
    return my_dlist_append(list, data);
  first = my_dlist_first(list);
  while (position > 0 && NULL != list)
  {
    backup = list;
    list = list->next;
    --position;
  }
  new = my_dlist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  new->next = list;
  new->prev = backup;
  if (NULL != list)
    list->prev = new;
  backup->next = new;
  return first;
}
