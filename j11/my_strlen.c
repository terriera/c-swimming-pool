/*
** my_strlen.c for 2002 swimming pool
**
** Made by gumhead
**
*/

unsigned int	my_strlen(const char *str)
{
  unsigned int	count;

  count = 0;
  while(*str++)
    ++count;
  return count;
}
