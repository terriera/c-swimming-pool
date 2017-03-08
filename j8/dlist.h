/*
** dlist.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#ifndef DLIST_H_
# define DLIST_H_

struct			s_dlist
{
  void			*data;
  struct s_dlist	*next;
  struct s_dlist	*prev;
};

typedef struct s_dlist	t_dlist;

t_dlist		*my_dlist_append(t_dlist *list, void *data);
t_dlist		*my_dlist_prepend(t_dlist *list, void *data);
t_dlist		*my_dlist_insert(t_dlist *list, void *data, int position);
t_dlist		*my_dlist_insert_sorted(t_dlist *list, void *data,
                                        int (*func)(const void *, const void *));
t_dlist		*my_dlist_remove(t_dlist *list, void *data);
t_dlist		*my_dlist_remove_link(t_dlist *list, t_dlist *llink);
void		my_dlist_free(t_dlist *list);
t_dlist		*my_dlist_alloc(void);
void		my_dlist_free_1(t_dlist *list);
unsigned int	my_dlist_length(t_dlist *list);
t_dlist		*my_dlist_copy(t_dlist *list);
t_dlist		*my_dlist_reverse(t_dlist *list);
t_dlist		*my_dlist_sort(t_dlist *list,
			       int (*func)(const void *, const void *));
t_dlist		*my_dlist_concat(t_dlist *list1, t_dlist *list2);
void		my_dlist_foreach(t_dlist *list,
		                 void (*func)(void *, void *),
		                 void *user_data);
t_dlist		*my_dlist_first(t_dlist *list);
t_dlist		*my_dlist_last(t_dlist *list);
t_dlist		*my_dlist_previous(t_dlist *list);
t_dlist		*my_dlist_next(t_dlist *list);
t_dlist		*my_dlist_nth(t_dlist *list, unsigned int n);
void		*my_dlist_nth_data(t_dlist *list, unsigned int n);
t_dlist		*my_dlist_find(t_dlist *list, void * data);
t_dlist		*my_dlist_find_custom(t_dlist *list, void *data,
		                      int (*func)(const void *, const void *));
int		my_dlist_position(t_dlist *list, t_dlist *llink);
int		my_dlist_index(t_dlist *list, void *data);

#endif /* !DLIST_H_ */
