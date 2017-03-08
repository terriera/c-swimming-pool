/*
** my_dlist_alloc.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

t_dlist		*my_dlist_alloc(void)
{
  t_dlist 	*result;

  result = malloc(sizeof (t_dlist));
  if (NULL == result)
    return NULL;
  result->next = NULL;
  result->prev = NULL;
  return result;
}
