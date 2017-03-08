CC	= cc
CFLAGS	= -W -Wall -Werror -ansi -pedantic
NAME	= testbin
SRC	= ../my_factorial.c		\
	  ../my_square.c	\
	  ../my_power.c		\
	  ../my_is_prime.c	\
	  ../my_strlen.c	\
	  ../my_strncpy.c	\
	  ../my_revstr.c	\
	  ../my_strstr.c	\
	  ../my_strncmp.c	\
	  main.c
OBJS	= $(SRC:.c=.o)
RM	= rm -f

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
