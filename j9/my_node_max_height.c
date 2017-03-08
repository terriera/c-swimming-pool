/*
** my_node_max__height.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

unsigned int	my_node_max_height(t_node *root)
{
  t_node	*children;
  unsigned int	count;
  unsigned int	max;

  if (NULL == root)
    return 0;
  children = root->children;
  max = 0;
  while (NULL != children)
  {
    count = my_node_max_height(children);
    if (count > max)
      max = count;
    children = children->next;
  }
  return ++max;
}
