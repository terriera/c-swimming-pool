LIBNAME	= libslist_`uname -m`-`uname -s`.a
CC      = cc
CFLAGS  = -g -O0 -W -Wall -Werror -ansi -pedantic
OBJ     = $(SRC:.c=.o)
RM      = rm -f
SRC	= my_slist_alloc.c        \
	  my_slist_append.c       \
	  my_slist_prepend.c      \
	  my_slist_insert.c       \
	  my_slist_remove.c       \
	  my_slist_remove_link.c  \
	  my_slist_free.c         \
	  my_slist_free_1.c       \
	  my_slist_length.c       \
	  my_slist_copy.c         \
	  my_slist_reverse.c      \
	  my_slist_concat.c       \
	  my_slist_last.c         \
	  my_slist_next.c         \
	  my_slist_nth.c          \
	  my_slist_nth_data.c     \
	  my_slist_find.c         \
	  my_slist_position.c     \
	  my_slist_index.c

# rules
all: $(LIBNAME)

$(LIBNAME): $(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) *~ \#*

distclean: clean
	$(RM) $(LIBNAME)

re: distclean all
