/*
** my_slist_alloc.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

t_slist		*my_slist_alloc(void)
{
  t_slist 	*result;

  result = malloc(sizeof (t_slist));
  if (NULL != result)
    result->next = NULL;
  return result;
}
