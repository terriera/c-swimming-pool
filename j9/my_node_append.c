/*
** my_node_append.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include "node.h"

t_node	*my_node_append(t_node *parent, t_node *node)
{
  return my_node_insert(parent, -1, node);
}
