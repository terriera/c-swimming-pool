##
## Makefile for 2002 swimming pool
##
## Made by gumhead
##

CC     = cc
CFLAGS = -W -Wall -Werror -ansi -pedantic
NAME   = testbin
SRC    = ../roman.c	\
	 ../get_day.c 	\
	 main.c

OBJS   = $(SRC:.c=.o)
RM     = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-$(RM) $(OBJS) *~ core \#*

distclean: clean
	-$(RM) $(NAME)

re: distclean all
