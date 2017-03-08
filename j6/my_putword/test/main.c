#include <limits.h>
#include <unistd.h>

void	my_putword(int n);

void	my_putstr(const char *str)
{
  while (*str)
    write(STDOUT_FILENO, str++, 1);
}

int	main()
{
  int	i;

  for (i = 0; i < 10; ++i)
    my_putword(i);
  my_putword(INT_MAX);
  my_putstr("--------------------------------\n");
  for (i = 0; i > -10; --i)
    my_putword(i);
  my_putword(INT_MIN);
  return 0;
}
