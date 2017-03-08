#include <stdio.h>
#include "../slist.h"

int	main()
{
  t_slist	*list;
  t_slist	*woz;
  int		nb;

  list = NULL;
  list = my_slist_append(list, "Steve Jobs");
  list = my_slist_append(list, "Steve Wozniak");
  list = my_slist_append(list, "Ron Wayne");
  list = my_slist_append(list, "Mike Markkula");
  list = my_slist_append(list, "Bill Fernandez");
  list = my_slist_append(list, "Randy Wigginton");
  list = my_slist_append(list, "Michael Scott");
  list = my_slist_append(list, "Chris Espinosa");
  list = my_slist_insert(list, "Rod Holt", 5);
  list = my_slist_remove(list, "Ron Wayne");
  woz  = my_slist_nth(list, 1);
  list = my_slist_remove_link(list, woz);
  list = my_slist_prepend(list, woz->data);
  my_slist_free_1(woz);
  woz = my_slist_find(list, "Steve Wozniak");
  list = my_slist_append(list, "Daniel Kottke");
  nb   = my_slist_length(list);
  list = my_slist_concat(list, my_slist_reverse(my_slist_remove(my_slist_copy(list), "Daniel Kottke")));
  my_printlist(list);
  printf("Number of employees: %d\n", nb);
  printf("Mike is employee n#%d\n", my_slist_index(list, "Mike Markkula") + 1);
  printf("Woz is employee n#%d\n", my_slist_position(list, woz) + 1);
  printf("Employee #3 is %s\n", my_slist_nth_data(list, 2));
  my_slist_free(list);
  return 0;
}
