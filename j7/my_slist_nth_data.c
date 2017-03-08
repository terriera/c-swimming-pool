/*
 * my_slist_nth_data.c for libslist
 *
 * Made by tdd
 * Login   <tdd@insia.org>
 * 
 * Started on  jeu 09 oct 2003 13:30:42 CEST tdd
 * Last update jeu 09 oct 2003 13:30:42 CEST tdd
 */

#include <stdlib.h>

#include "slist.h"

void *my_slist_nth_data(t_slist *list, unsigned int n)
{
    t_slist *node;

    node = my_slist_nth(list, n);
    return NULL == node ? NULL : node->data;
}
