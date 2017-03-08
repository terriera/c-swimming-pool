/*
** my_node_find.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

t_node		*my_node_find(t_node *root, void *data)
{
  t_node	*children;
  t_node	*found;

  if (NULL == root)
    return NULL;
  if (root->data == data)
    return root;
  children = root->children;
  while (NULL !=  children)
  {
    found = my_node_find(children, data);
    if (NULL != found)
      return found;
    children = children->next;
  }
  return NULL;
}
