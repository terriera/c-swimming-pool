/*
** my_dlist_insert.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "dlist.h"

/*
** FIXME: check if func == NULL.
*/
t_dlist		*my_dlist_insert_sorted(t_dlist	*list,
		                        void	*data,
		                        int 	(*func)(const void *,
		                        	        const void *))
{
  t_dlist	*new;
  t_dlist	*backup;
  t_dlist	*first;

  list = my_dlist_first(list);
  first = list;
  backup = NULL;
  if (NULL == list)
    return my_dlist_prepend(list, data);
  while (NULL != list && func(list->data, data) < 0)
  {
    backup = list;
    list = list->next;
  }
  new = my_dlist_alloc();
  if (NULL == new)
    return NULL;
  new->data = data;
  new->next = list;
  new->prev = backup;
  if (NULL != list)
    list->prev = new;
  if (NULL != backup)
    backup->next = new;
  return NULL == first->prev ? first : new;
}
