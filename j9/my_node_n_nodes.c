/*
** my_node_n_nodes.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

unsigned int	my_node_n_nodes(t_node *root)
{
  t_node	*children;
  unsigned int	count;
 
  if (NULL == root)
    return 0;
  children = root->children;
  count = 1;
  while (NULL != children)
  {
    count += my_node_n_nodes(children);
    children = children->next;
  }
  return count;
}
