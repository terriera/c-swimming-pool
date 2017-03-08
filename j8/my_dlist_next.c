/*
** my_dlist_previous.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist	*my_dlist_next(t_dlist *list)
{
  return NULL == list ? NULL : list->next;
}
