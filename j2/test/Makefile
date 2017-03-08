CC	= cc
CFLAGS	= -W -Wall -Werror -ansi -pedantic
NAME	= testbin
SRC		= ../my_putchar.c		\
		  ../my_putstr.c		\
		  ../my_putnbr.c		\
		  ../my_atoi.c			\
		  ../my_putnbr_base.c		\
		  ../my_atoi_base.c		\
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
