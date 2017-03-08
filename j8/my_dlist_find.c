/*
** my_dlist_find.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist	*my_dlist_find(t_dlist *list, void *data)
{
  list = my_dlist_first(list);
  while (NULL != list && data != list->data)
    list = list->next;
  return list;
}
