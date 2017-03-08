/*
** dlist.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

int my_dlist_index(t_dlist *list, void *data)
{
  int index;

  index = 0;
  list = my_dlist_first(list);
  while (NULL != list)
  {
    if (list->data == data)
      return index;
    index++;
    list = list->next;
  }
  return -1;
}
