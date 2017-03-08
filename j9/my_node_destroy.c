/*
** my_node_destroy.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

/*
** if (NULL != root->parent && root->parent->children == root), when root is not
** the real root of the tree (i.e. we want to destroy a subtree).
*/
void		my_node_destroy(t_node *root)
{
  t_node	*next;

  if (NULL == root)
    return;
  while (NULL != root->children)
  {
    next = root->children->next;
    my_node_destroy(root->children);
    root->children = next;
  }
  if (NULL != root->next)
    root->next->prev = root->prev;
  if (NULL != root->prev)
    root->prev->next = root->next;
  if (NULL != root->parent && root->parent->children == root)
    root->parent->children = root->next;
  free(root);
}
