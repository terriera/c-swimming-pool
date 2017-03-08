NAME    = testbin
LIBNAME	= libdlist_`uname -m`-`uname -s`.a
CC      = cc
CFLAGS  = -g -O0 -W -Wall -Werror -ansi -pedantic
OBJ     = $(SRC:.c=.o)
RM      = rm -f
SRC	= ../my_dlist_append.c           \
	  ../my_dlist_prepend.c          \
	  ../my_dlist_insert.c           \
	  ../my_dlist_insert_sorted.c    \
	  ../my_dlist_remove.c           \
	  ../my_dlist_remove_link.c      \
	  ../my_dlist_free.c             \
	  ../my_dlist_alloc.c            \
	  ../my_dlist_free_1.c           \
	  ../my_dlist_length.c           \
	  ../my_dlist_copy.c             \
	  ../my_dlist_reverse.c          \
	  ../my_dlist_sort.c             \
	  ../my_dlist_concat.c           \
	  ../my_dlist_foreach.c          \
	  ../my_dlist_first.c            \
	  ../my_dlist_last.c             \
	  ../my_dlist_previous.c         \
	  ../my_dlist_next.c             \
	  ../my_dlist_nth.c              \
	  ../my_dlist_nth_data.c         \
	  ../my_dlist_find.c             \
	  ../my_dlist_find_custom.c      \
	  ../my_dlist_position.c         \
	  ../my_dlist_index.c

# rules
all: $(LIBNAME)

check: $(NAME)

$(LIBNAME): $(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

$(NAME): main.o
	$(CC) -o $(NAME) main.o $(LIBNAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) main.o *~ \#*

distclean: clean
	$(RM) $(LIBNAME) $(NAME)

re: distclean all
