/*
** my_toupper.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_toupper(int c)
{
  return my_islower(c) ? c - 'a' + 'A' : c;
}
