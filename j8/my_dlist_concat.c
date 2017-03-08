/*
** my_dlist_concat.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_concat(t_dlist *list1, t_dlist *list2)
{
  t_dlist	*first;

  first = NULL != list1 ? list1 : list2;
  if (NULL != list1)
  {
    list1 = my_dlist_last(list1);
    list1->next = list2;
  }
  return first;
}
