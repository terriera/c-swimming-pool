/*
** my_putword.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <unistd.h>

static void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}

/*
** 1 << ((sizeof(int) * 8) - 1): sets the most significant bit and unset the
** others.
*/
void		my_putword(int n)
{
  unsigned int	mask;
  
  mask = 1 << ((sizeof(int) * 8) - 1);
  while (mask > 0)
  {
    my_putchar(n & mask ? '1' : '0');
    mask >>= 1;
  }
  my_putchar('\n');
}
