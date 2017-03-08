/*
** my_dlist_sort.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

static t_dlist	*my_dlist_partition(t_dlist *list,
		                    t_dlist **lesser,
		                    t_dlist **greater,
		                    int (*func)(const void *, const void *))
{
  t_dlist	*pivot;
  t_dlist	*first;

  if (NULL == list || NULL == lesser || NULL == greater || NULL == func)
    return NULL;
  *lesser = NULL;
  *greater = NULL;
  pivot = my_dlist_first(list);
  list = my_dlist_remove_link(list, pivot);
  while (NULL != list)
  {
    first = my_dlist_first(list);
    list = my_dlist_remove_link(list, first);
    if (func(first->data, pivot->data) < 0)
      *lesser = my_dlist_concat(*lesser, first);
    else
      *greater = my_dlist_concat(*greater, first);
  }
  return pivot;
}

t_dlist		*my_dlist_sort(t_dlist *list,
		               int (*func)(const void *, const void *))
{
  t_dlist	*pivot;
  t_dlist	*lesser;
  t_dlist	*greater;

  if (NULL == list || NULL == func)
    return NULL;
  pivot = my_dlist_partition(list, &lesser, &greater, func);
  lesser = my_dlist_sort(lesser, func);
  lesser = my_dlist_concat(lesser, pivot);
  greater = my_dlist_sort(greater, func);
  return my_dlist_concat(lesser, greater);
}
