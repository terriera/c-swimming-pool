/*
** my_dlist_position.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

int	my_dlist_position(t_dlist *list, t_dlist *link)
{
  int	pos;

  pos = 0;
  list = my_dlist_first(list);
  while (NULL != list)
  {
    if (list == link)
      return pos;
    pos++;
    list = list->next;
  }
  return -1;
}
