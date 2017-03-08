/*
** my_slist_remove.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "slist.h"

t_slist		*my_slist_remove(t_slist *list, void *data)
{
  t_slist	*node;

  node = my_slist_find(list, data);
  list = my_slist_remove_link(list, node);
  my_slist_free_1(node);
  return list;
}
