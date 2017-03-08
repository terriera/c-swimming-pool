#
# Makefile for 2002 swimming pool
#
# Made by Gumhead
#
#

CC     = cc
CFLAGS = -Wall -W -ansi -Werror #-pedantic
NAME   = my_banner
SRC    = my_banner.c
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
