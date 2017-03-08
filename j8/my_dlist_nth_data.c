/*
** dlist.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

void		*my_dlist_nth_data(t_dlist *list, unsigned int n)
{
  t_dlist	*node;

  node = my_dlist_nth(list, n);
  return NULL == node ? NULL : node->data;
}
