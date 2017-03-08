/*
** my_slist_reverse.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_reverse(t_slist *list)
{
  t_slist	*prev;
  t_slist	*backup;

  prev = NULL;
  while (NULL != list)
  {
    backup = list->next;
    list->next = prev;
    prev = list;
    list = backup;
  }
  return prev;
}
