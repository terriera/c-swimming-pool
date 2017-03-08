#
# Makefile for libnode
#
# Made by aterrier
# Login   <aterrier@insia.org>
# 
# Started on  ven 16 jan 2004 12:00:07 CET aterrier
# Last update ven 16 jan 2004 12:00:07 CET aterrier
#

NAME     = node_`uname -m`-`uname -s`
LIBNAME  = lib$(NAME).a
TEST     = testbin
CC       = cc
IPATH    = ..
#CFLAGS   = -W -Wall -Werror -ansi -pedantic -O2 -I $(IPATH)
CFLAGS   = -W -Wall -Werror -ansi -pedantic -g3 -I $(IPATH)
LPATH    = .
LDFLAGS	 = -L $(LPATH) -l$(NAME)
SRC      = ../my_node_new.c          \
           ../my_node_insert.c       \
           ../my_node_append.c       \
           ../my_node_prepend.c      \
           ../my_node_find.c         \
           ../my_node_n_nodes.c      \
           ../my_node_max_height.c   \
           ../my_node_unlink.c       \
           ../my_node_destroy.c
TEST_SRC = main.c
OBJ      = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)
RM       = rm -f

all : $(LIBNAME)

test : $(TEST)

both : $(LIBNAME) $(TEST)

re : distclean all

$(LIBNAME) : $(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

$(TEST) : $(TEST_OBJ) $(LIBNAME)
	$(CC) -o $(TEST) $(TEST_OBJ) $(LDFLAGS)

clean :
	$(RM) $(OBJ) $(TEST_OBJ)
	$(RM) *~ \#* core*

distclean : clean
	$(RM) $(LIBNAME) $(TEST)

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $<

