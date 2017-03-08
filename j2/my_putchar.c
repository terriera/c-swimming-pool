/*
** my_putchar.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}
