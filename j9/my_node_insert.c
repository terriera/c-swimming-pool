/*
** my_node_insert.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

/*
** Using "while (position != 0 && NULL != parent->children)" instead of
** "while (position > 0 && NULL != parent->children)" allows us to ignore
** position when it's < 0 and so to append node (when parent->children is NULL).
**
** backup will stay NULL if we insert to a node with no child or if we prepend.
*/
t_node		*my_node_insert(t_node *parent, int position, t_node *node)
{
  t_node	*children;
  t_node	*backup;

  if (NULL == parent)
    return node;
  if (NULL == node)
    return NULL;
  children = parent->children;
  backup = NULL;
  while (position != 0 && NULL != children)
  {
    backup = children;
    children = children->next;
    --position;
  }
  node->parent = parent;
  node->prev = backup;
  node->next = children;
  if (NULL != children)
    children->prev = node;
  if (NULL != backup)
    backup->next = node;
  else
    parent->children = node;
  return node;
}
