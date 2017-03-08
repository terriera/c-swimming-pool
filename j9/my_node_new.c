/*
** my_node_new.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "node.h"

t_node		*my_node_new(void *data)
{
  t_node	*new;

  new = malloc(sizeof(t_node));
  if (NULL == new)
    return NULL;
  new->next = NULL;
  new->prev = NULL;
  new->parent = NULL;
  new->children = NULL;
  new->data = data;
  return new;
}
