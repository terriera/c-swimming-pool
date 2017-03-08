/*
** my_node_unlink.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

void	my_node_unlink(t_node *node)
{
  if (NULL == node)
    return;
  if (NULL != node->prev)
    node->prev->next = node->next;
  if (NULL !=  node->next)
    node->next->prev = node->prev;
  if (NULL != node->parent && node->parent->children == node)
    node->parent->children = node->next;
  node->parent = NULL;
  node->prev = NULL;
  node->next = NULL;
}
