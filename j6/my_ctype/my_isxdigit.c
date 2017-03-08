/*
** my_isxdigit.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_isdigit(int c);

int	isxdigit(int c)
{
  return my_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
