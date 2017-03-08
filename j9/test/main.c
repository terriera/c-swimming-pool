#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

#define SHIFT_LENGTH 2

char 		*strdup(const char *s);

static void	print_str(void *data)
{
  char		*str;

  str = data;
  puts(str);
}

static void	print_tree(t_node *node, int shift, void (*print_fct)(void *data))
{
  t_node	*children;
  int		i;

  if (NULL == node)
    return;
  for (i = 0; i < shift; ++i)
    putchar (' ');
  print_fct(node->data);
  children = node->children;
  while (NULL !=  children)
  {
    print_tree(children, shift + SHIFT_LENGTH, print_fct);
    children = children->next;
  }
}

int	main()
{
  /* append, prepend and insert functions test */
  {
    t_node	*tree;
    t_node	*nd;

    tree = my_node_new("root");
    if (NULL == tree)
      return 1;
    my_node_append(tree, my_node_new("IV"));
    my_node_prepend(tree, my_node_new("II"));
    my_node_insert(tree, 1, my_node_new("III"));
    my_node_insert(tree, -1, my_node_new("V"));
    my_node_insert(tree, 42, my_node_new("VI"));
    my_node_insert(tree, 0, my_node_new("I"));
    nd = my_node_new("...");
    assert(nd == my_node_insert(NULL, 0, nd));
    assert(nd == my_node_append(NULL, nd));
    assert(nd == my_node_prepend(NULL, nd));
    my_node_destroy(nd);    
    assert(NULL == my_node_insert(tree, 0, NULL));
    assert(NULL == my_node_append(tree, NULL));
    assert(NULL == my_node_prepend(tree, NULL));
    /* display the tree and free ressources */
    print_tree(tree, 0, print_str);
    printf("nodes number: %d\n", my_node_n_nodes(tree));
    printf("nodes max height: %d\n", my_node_max_height(tree));
    my_node_destroy(tree);
  }
  /* find function test */
  {
    t_node	*haystack;
    t_node	*needle;
    char	*str;
    
    str = strdup("42");
    needle = my_node_new(str);
    haystack = my_node_new("1");
    printf("node number: %d\n", my_node_n_nodes(needle));
    printf("nodes max height: %d\n", my_node_max_height(needle));
    printf("node number: %d\n", my_node_n_nodes(NULL));
    printf("nodes max height: %d\n", my_node_max_height(NULL));
    my_node_append(haystack, my_node_new("2"));
    my_node_append(haystack, my_node_new("3"));
    my_node_append(haystack, my_node_new("4"));
    my_node_append(haystack->children->next, my_node_new("5"));
    my_node_append(haystack->children->next, needle);
    my_node_append(haystack->children->next, my_node_new("7"));
    /* display the tree and free ressources */
    print_tree(haystack, 0, print_str);
    if (needle == my_node_find(haystack, str))
      puts("Found!");
    else
      puts("Not found!");
    printf("nodes number: %d\n", my_node_n_nodes(haystack));
    printf("nodes max height: %d\n", my_node_max_height(haystack));
    my_node_destroy(haystack);
    free(str);
  }
  /* make a more complex tree and test unlink and destroy */
  {
    t_node	*tree;
    t_node	*to_unlink;
    t_node	*to_destroy;
    
    tree = my_node_new("racine");
    my_node_append(tree, my_node_new("1"));
    my_node_append(tree, my_node_new("2"));
    to_destroy = my_node_new("3");
    my_node_append(tree, to_destroy);
    my_node_append(tree, my_node_new("4"));
    to_unlink = my_node_new("1.1");
    my_node_append(tree->children, to_unlink);
    my_node_append(tree->children, my_node_new("1.2"));
    my_node_append(tree->children, my_node_new("1.3"));
    my_node_append(tree->children, my_node_new("1.4"));
    my_node_append(tree->children, my_node_new("1.5"));
    printf("1.1->prev: %p\n", (void *)to_unlink->prev);
    printf("1.1->next: %p\n", (void *)to_unlink->next);
    my_node_append(tree->children->next, my_node_new("2.1"));
    my_node_append(tree->children->next, my_node_new("2.2"));
    my_node_append(tree->children->next, my_node_new("2.3"));
    my_node_append(to_destroy, my_node_new("3.1"));
    my_node_append(to_destroy, my_node_new("3.2"));
    my_node_append(to_destroy, my_node_new("3.3"));
    my_node_append(to_destroy, my_node_new("3.4"));
    my_node_append(to_destroy, my_node_new("3.5"));
    my_node_append(to_destroy, my_node_new("3.6"));
    my_node_append(to_destroy, my_node_new("3.7"));
    my_node_append(to_destroy, my_node_new("3.8"));
    my_node_append(to_unlink, my_node_new("1.1.1"));
    my_node_append(to_unlink, my_node_new("1.1.2"));
    my_node_append(to_unlink, my_node_new("1.1.3"));
    my_node_append(to_unlink, my_node_new("1.1.4"));
    my_node_append(to_unlink, my_node_new("1.1.5"));
    my_node_append(to_unlink, my_node_new("1.1.6"));
    print_tree(tree, 0, print_str);
    puts("tree with 1.1 unlinked:");
    my_node_unlink(to_unlink);
    print_tree(tree, 0, print_str);
    puts("the unlinked : 1.1");
    print_tree(to_unlink, 0, print_str);
    my_node_destroy(to_unlink);
    puts("tree with 3 unlinked:");
    my_node_destroy(to_destroy);
    print_tree(tree, 0, print_str);
    my_node_destroy(tree);
    puts("unlink a single node");
    tree = my_node_new("single");
    printf("single->parent = %p, single->prev = %p, single->next = %p, single->children = %p\n",
      tree->parent, tree->prev, tree->next, tree->children);
    puts("unlinking");
    my_node_unlink(tree);
    printf("single->parent = %p, single->prev = %p, single->next = %p, single->children = %p\n",
      tree->parent, tree->prev, tree->next, tree->children);
    my_node_destroy(tree);
    puts("unlinking null tree...");
    my_node_unlink(NULL);
  }
  return 0;
}
