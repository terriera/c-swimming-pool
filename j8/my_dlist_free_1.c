/*
** my_dlist_free_1.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "dlist.h"

void	my_dlist_free_1(t_dlist *list)
{
  if (NULL != list)
    free(list);
}
