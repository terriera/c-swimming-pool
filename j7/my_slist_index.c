/*
** slist.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

int my_slist_index(t_slist *list, void *data)
{
  int result = 0;

  while (NULL != list)
  {
    if (list->data == data)
      return result;
    result++;
    list = list->next;
  }
  return -1;
}
