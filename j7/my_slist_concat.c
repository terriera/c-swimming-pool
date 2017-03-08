/*
** my_slist_concat.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_concat(t_slist *list1, t_slist *list2)
{
  t_slist	*first;

  first = NULL != list1 ? list1 : list2;
  if (NULL != list1)
  {
    list1 = my_slist_last(list1);
    list1->next = list2;
  }
  return first;
}
