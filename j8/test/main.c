#include <stdio.h>
#include <string.h>
#include "../dlist.h"

/*t_dlist	*my_dlist_partition(t_dlist *list,
		                    t_dlist **lesser,
		                    t_dlist **greater,
		                    int (*func)(const void *, const void *));*/

static void	print_elem(void *data, void *extra)
{
  char		*str;

  (void)extra;
  str = data;
  puts(str);
}

static int	my_compare(const void *data1, const void *data2)
{
  const char	*str1;
  const char	*str2;

  str1 = data1;
  str2 = data2;
  return strcmp(str1, str2);
}

int main()
{
  t_dlist	*list;
  t_dlist	*tokill;
  t_dlist	*copy;
  /*t_dlist	*pivot;
  t_dlist	*lesser;
  t_dlist	*greater;*/

  list = NULL;
  list = my_dlist_append(list, "Steve Jobs");
  list = my_dlist_append(list, "Ron Wayne");
  list = my_dlist_append(list, "Mike Markkula");
  list = my_dlist_append(list, "Bill Fernandez");
  list = my_dlist_append(list, "Randy Wigginton");
  list = my_dlist_append(list, "Michael Scott");
  list = my_dlist_append(list, "Chris Espinosa");
  list = my_dlist_insert(list, "Rod Holt", 5);
  list = my_dlist_insert(list, "Dummy", 42);
  list = my_dlist_prepend(list, "Steve Wozniak");
  my_dlist_foreach(list, print_elem, 0);
  puts("---");
  list = my_dlist_nth(list, 5);
  printf("!!!%s!!!\n", (char *)list->data);
  list = my_dlist_first(list);
  printf("!!!%s!!!\n", (char *)list->data);
  list = my_dlist_last(list);
  printf("!!!%s!!!\n", (char *)list->data);
  puts("---");
  my_dlist_foreach(list, print_elem, 0);
  puts("---");
  puts("Copying the list:");
  copy = my_dlist_copy(my_dlist_last(list));
  my_dlist_foreach(copy, print_elem, 0);
  puts("---");
  puts("!!!Kill second!!!");
  tokill = my_dlist_first(list);
  tokill = tokill->next;
  my_dlist_remove_link(list, tokill);
  my_dlist_foreach(list, print_elem, 0);
  printf("tokill->next = %p, tokill->prev = %p\n", tokill->next, tokill->prev);
  my_dlist_free(tokill);
  puts("---");
  puts("!!!Kill last!!!");
  tokill = my_dlist_last(list);
  list = my_dlist_remove_link(list, tokill);
  my_dlist_foreach(list, print_elem, 0);
  printf("tokill->next = %p, tokill->prev = %p\n", tokill->next, tokill->prev);
  my_dlist_free(tokill);
  puts("---");
  puts("!!!Kill first!!!");
  tokill = my_dlist_first(list);
  list = my_dlist_remove_link(list, tokill);
  my_dlist_foreach(list, print_elem, 0);
  printf("tokill->next = %p, tokill->prev = %p\n", tokill->next, tokill->prev);
  my_dlist_free(tokill);
  puts("---");
  puts("Sorting the list:");
  list = my_dlist_sort(list, my_compare);
  my_dlist_foreach(list, print_elem, 0);
  /*
  puts("---");
  puts("Partitioning the list");
  pivot = my_dlist_partition(list, &lesser, &greater, my_compare);
  puts("pivot:");
  my_dlist_foreach(pivot, print_elem, 0);
  puts("lesser:");
  my_dlist_foreach(lesser, print_elem, 0);
  puts("greater:");
  my_dlist_foreach(greater, print_elem, 0);
  my_dlist_free(pivot);
  my_dlist_free(lesser);
  my_dlist_free(greater);
  */
  puts("---");
  puts("Sorting the copy:");
  copy = my_dlist_sort(copy, my_compare);
  my_dlist_foreach(copy, print_elem, 0);
  puts("---");
  puts("Custom finding:");
  tokill = my_dlist_find_custom(list, "Randy Wigginton", my_compare);
  print_elem(tokill->data, 0);
  puts("---");
  puts("Reversing the list:");
  copy = my_dlist_reverse(copy);
  my_dlist_foreach(copy, print_elem, 0);
  tokill = my_dlist_last(copy);
  printf("last->next = %p, ", tokill->next);
  tokill = my_dlist_first(copy);
  printf("first->prev = %p\n", tokill->prev);
  puts("---");
  puts("Reversing again:");
  copy = my_dlist_reverse(copy);
  my_dlist_foreach(copy, print_elem, 0);
  tokill = my_dlist_last(copy);
  printf("last->next = %p, ", tokill->next);
  tokill = my_dlist_first(copy);
  printf("first->prev = %p\n", tokill->prev);
  puts("---");
  puts("Inserting sorted:");
  copy = my_dlist_insert_sorted(copy, "Gumhead", my_compare);
  my_dlist_foreach(copy, print_elem, 0);
  puts("---");
  puts("Inserting sorted at the beginning:");
  copy = my_dlist_insert_sorted(copy, "!first", my_compare);
  my_dlist_foreach(copy, print_elem, 0);
  puts("---");
  puts("Inserting sorted at the end:");
  copy = my_dlist_insert_sorted(copy, "Xlast", my_compare);
  my_dlist_foreach(copy, print_elem, 0);
  my_dlist_free(copy);
  my_dlist_free(list);
  return 0;
}
