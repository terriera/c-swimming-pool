/*
** my_dlist_foreach.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

void	my_dlist_foreach(t_dlist *list,
	                 void (*func)(void *, void *),
	                 void *user_data)
{
  if (NULL == func)
    return;
  list = my_dlist_first(list);
  while (NULL != list)
  {
    func(list->data, user_data);
    list = list->next;
  }
}
