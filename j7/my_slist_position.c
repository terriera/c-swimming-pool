/*
** slist.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

int	my_slist_position(t_slist *list, t_slist *link)
{
  int	result;

  result = 0;
  while (NULL != list)
  {
    if (list == link)
      return result;
    result++;
    list = list->next;
  }
  return -1;
}
