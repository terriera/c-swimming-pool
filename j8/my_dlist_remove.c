/*
** my_dlist_remove.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "dlist.h"

t_dlist		*my_dlist_remove(t_dlist *list, void *data)
{
  t_dlist	*node;

  node = my_dlist_find(list, data);
  list = my_dlist_remove_link(list, node);
  my_dlist_free_1(node);
  return list;
}
