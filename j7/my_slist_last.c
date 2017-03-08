/*
** my_slist_append.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist	*my_slist_last(t_slist *list)
{
  if (NULL != list)
    while (NULL != list->next)
      list = list->next;
  return list;
}
