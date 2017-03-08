/*
** my_slist_append.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

void		my_slist_free(t_slist *list)
{
  t_slist	*next;

  while (NULL != list)
  {
    next = list->next;
    my_slist_free_1(list);
    list = next;
  }
}
