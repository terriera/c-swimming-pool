/*
** node.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#ifndef NODE_H_
# define NODE_H_

struct			s_node
{
  void			*data;
  struct s_node		*next;
  struct s_node 	*prev;
  struct s_node 	*parent;
  struct s_node 	*children;
};

typedef struct s_node	t_node;

t_node		*my_node_new(void *data);
t_node		*my_node_insert(t_node *parent, int position, t_node *node);
t_node		*my_node_append(t_node *parent, t_node *node);
t_node		*my_node_prepend(t_node *parent, t_node *node);
t_node		*my_node_find(t_node *root, void *data);
unsigned int	my_node_n_nodes(t_node *root);
unsigned int	my_node_max_height(t_node *root);
void		my_node_unlink(t_node *node);
void		my_node_destroy(t_node *root);

#endif /* !NODE_H_ */
