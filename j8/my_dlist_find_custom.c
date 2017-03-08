/*
** my_dlist_find_custom.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist	*my_dlist_find_custom(t_dlist *list, void *data,
	                      int (*func)(const void *, const void *))
{
  list = my_dlist_first(list);
  while (NULL != list && func(data, list->data))
    list = list->next;
  return list;
}
