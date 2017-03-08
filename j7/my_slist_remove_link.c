/*
** my_slist_remove_link.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

static t_slist	*my_slist_remove_link(t_slist *list, t_slist *link)
{
  t_slist	*first;

  first = list;
  if (NULL == link)
    return list;
  if (first == link && NULL != first)
    first = first->next;
  while (NULL != list && link != list->next)
    list = list->next;
  if (NULL != list)
  {
    list->next = link->next;
    link->next = NULL;
  }
  return first;
}
