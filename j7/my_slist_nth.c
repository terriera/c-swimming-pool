/*
** my_slist_nth.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist	*my_slist_nth(t_slist *list, unsigned int n)
{
  while (n-- && NULL != list)
    list = list->next;
  return list;
}
