/*
** my_dlist_free.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

void		my_dlist_free(t_dlist *list)
{
  t_dlist	*next;

  list = my_dlist_first(list);
  while (NULL != list)
  {
    next = list->next;
    my_dlist_free_1(list);
    list = next;
  }
}
