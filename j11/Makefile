#
# Makefile for (self)
#
# Made by aterrier
# Login   <aterrier@insia.org>
# 
# Started on  Fri 03 Oct 2003 11:22:36 AM CEST aterrier
# Last update Fri 03 Oct 2003 11:23:58 AM CEST aterrier
#

# variables
# 

NAME 	= eval_expr
CC 	= cc
IPATH	= .
#CFLAGS 	= -O2 -W -Wall -Werror -ansi -pedantic -I${IPATH}
CFLAGS 	= -g3 -W -Wall -Werror -ansi -pedantic -I${IPATH}
SRC 	= my_putchar.c      \
	  my_putstr.c       \
	  my_putnbr_base.c  \
	  my_strlen.c       \
	  my_strncpy.c      \
	  my_strncmp.c      \
	  my_factorial.c    \
	  my_fibonacci.c    \
	  my_power.c        \
	  my_pgcd.c         \
	  my_ppcm.c         \
	  handle_op.c       \
	  parse_number.c    \
	  parse_func.c      \
	  parse_value.c     \
	  parse_mul.c       \
	  parse_add.c       \
	  parse_expr.c      \
	  main.c
OBJ	= $(SRC:.c=.o)
RM	= rm -f


# rules

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) *~ \#*

distclean: clean
	$(RM) $(NAME)

re: distclean all
