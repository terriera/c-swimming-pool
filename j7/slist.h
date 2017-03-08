/*
** slist.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#ifndef SLIST_H_
# define SLIST_H_

struct			s_slist
{
  struct s_slist	*next;
  void			*data;
};

typedef struct s_slist	t_slist;

t_slist		*my_slist_alloc(void);
t_slist		*my_slist_append(t_slist *list, void *data);
t_slist		*my_slist_prepend(t_slist *list, void *data);
t_slist		*my_slist_insert(t_slist *list, void *data, int position);
t_slist		*my_slist_remove(t_slist *list, void *data);
t_slist		*my_slist_remove_link(t_slist *list, t_slist *link);
void		my_slist_free(t_slist *list);
void		my_slist_free_1(t_slist *list);
unsigned int	my_slist_length(t_slist *list);
t_slist		*my_slist_copy(t_slist *list);
t_slist		*my_slist_reverse(t_slist *list);
t_slist		*my_slist_concat(t_slist *list1, t_slist *list2);
t_slist		*my_slist_last(t_slist *list);
t_slist		*my_slist_next(t_slist *list);
t_slist		*my_slist_nth(t_slist *list, unsigned int n);
void		*my_slist_nth_data(t_slist *list, unsigned int n);
t_slist		*my_slist_find(t_slist *list, void *data);
int		my_slist_position(t_slist *list, t_slist *link);
int		my_slist_index(t_slist *list, void *data);

#endif /* !SLIST_H_ */
