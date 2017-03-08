/*
** my_slist_free_1.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>

#include "slist.h"

void	my_slist_free_1(t_slist *list)
{
  if (NULL != list)
    free(list);
}
