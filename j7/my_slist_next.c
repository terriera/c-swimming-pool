/*
** my_slist_concat.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist	*my_slist_next(t_slist *list)
{
  return NULL == list ? NULL : list->next;
}
