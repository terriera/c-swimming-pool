/*
** my_tolower.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_tolower(int c)
{
  return my_isupper(c) ? c - 'A' + 'a' : c;
}
