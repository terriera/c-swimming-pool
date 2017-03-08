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

NAME 	= testbin
CC 	= cc
IPATH	= ..
CFLAGS 	= -O2 -W -Wall -Werror -ansi -pedantic -I${IPATH}
#CFLAGS 	= -g3 -Wall -Wextra -Werror -ansi -pedantic -I${IPATH}
SRC 	= ../my_fnmatch.c     \
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
