/*
** my_slist_insert.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_insert(t_slist *list, void *data, int position)
{
  t_slist	*new;
  t_slist	*backup;
  t_slist	*first;

  if (0 == position || NULL == list)
    return my_slist_prepend(list, data);
  if (position < 0)
    return my_slist_append(list, data);
  first = list;
  while (position > 0 && NULL != list)
  {
    backup = list;
    list = list->next;
    position--;
  }
  new = my_slist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  new->next = backup->next;
  backup->next = new;
  return first;
}
