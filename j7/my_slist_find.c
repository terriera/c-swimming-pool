/*
** my_slist_find.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist	*my_slist_find(t_slist *list, void *data)
{
  while (NULL != list && data != list->data)
    list = list->next;
  return list;
}
