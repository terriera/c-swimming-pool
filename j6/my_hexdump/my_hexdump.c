/*
** my_hexdump.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <unistd.h>

#define MY_BUFSIZE 16

/*
** libmy
*/

static int	my_putchar(int c)
{
  if (0 > write(STDOUT_FILENO, &c, 1))
    return -1;
  return 0;
}

static void	my_putstr(char *str)
{
  int		length;

  length = 0;
  while ('\0' != str[length])
    ++length;
  write(STDOUT_FILENO, str, length);
}

static void	my_putnbr_hex(unsigned int nbr)
{
  char		*base;
  unsigned int	divisor;

  base = "0123456789abcdef";
  divisor = 1;
  while ((nbr / divisor) >= 16)
    divisor *= 16;
  while (1 <= divisor)
  {
    my_putchar(base[nbr / divisor]);
    nbr %= divisor;
    divisor /= 16;
  }
}

static int my_isprint(int c)
{
  return ' ' <= c && '~' >= c ? 1 : 0;
}

/*
** my_hexdump
*/

static void	print_position(unsigned int pos)
{
  unsigned int	n;

  for (n = 0x10000000; n > pos && n > 1; n /= 0x10)
    my_putchar('0');
  my_putnbr_hex(pos);
  my_putstr("  ");
}

static unsigned int	fill_buffer(unsigned char *buffer,
			            void *data,
			            unsigned int pos,
			            unsigned int size)
{
  unsigned char		*bytes;
  unsigned int		nb_read;

  bytes = data;
  nb_read = 0;
  while ('\0' != bytes[pos] && nb_read < MY_BUFSIZE && pos < size)
    buffer[nb_read++] = bytes[pos++];
  return nb_read;
}

static void	print_data(unsigned char *buffer, unsigned int nb_read)
{
  unsigned int	i;
  unsigned int	middle;

  middle = (MY_BUFSIZE / 2) - 1;
  for (i = 0; i < nb_read; ++i)
  {
    if (0xf >= buffer[i])
      my_putchar('0');
    my_putnbr_hex(buffer[i]);
    my_putstr(i == middle ? "  " : " ");
  }
  for (; i < MY_BUFSIZE; ++i)
    my_putstr(i == middle ? "    " : "   ");
}

static void	print_buffer(unsigned char *buffer, unsigned int nb_read)
{
  unsigned int	i;
  char		c;

  my_putstr(" |");
  for (i = 0; i < nb_read; ++i)
  {
    c = buffer[i];
    my_putchar(my_isprint(c) ? c : '.');
  }
  my_putstr("|\n");
}

void		my_hexdump(void *data, unsigned int size)
{
  unsigned char	buffer[MY_BUFSIZE + 1];
  unsigned int	nb_read;
  unsigned int	pos;

  if (0 == size || !data)
    return;
  buffer[MY_BUFSIZE]= '\0';
  nb_read = MY_BUFSIZE;
  for (pos = 0; MY_BUFSIZE == nb_read && pos < size; pos += MY_BUFSIZE)
  {
    print_position(pos);
    nb_read = fill_buffer(buffer, data, pos, size);
    print_data(buffer, nb_read);
    print_buffer(buffer, nb_read);
  }
}
