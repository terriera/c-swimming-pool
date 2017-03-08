/*
** my_node_prepend.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "node.h"

t_node	*my_node_prepend(t_node *parent, t_node *node)
{
  return my_node_insert(parent, 0, node);
}
