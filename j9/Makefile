#
# Makefile for 2002 swimming pool
#
# Made by Gumhead
#
#

NAME     = node_`uname -m`-`uname -s`
LIBNAME  = lib$(NAME).a
RM       = rm -f
CC       = cc
IPATH    = .
CFLAGS   = -W -Wall -Werror -ansi -pedantic -O2 -I $(IPATH)
OBJ      = $(SRC:.c=.o)
SRC      = my_node_new.c          \
           my_node_insert.c       \
           my_node_append.c       \
           my_node_prepend.c      \
           my_node_find.c         \
           my_node_n_nodes.c      \
           my_node_max_height.c   \
           my_node_unlink.c       \
           my_node_destroy.c

all : $(LIBNAME)

re : distclean all

$(LIBNAME) : $(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

clean :
	$(RM) $(OBJ) $(TEST_OBJ)
	$(RM) *~ \#* core*

distclean : clean
	$(RM) $(LIBNAME) $(TEST)

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $<

