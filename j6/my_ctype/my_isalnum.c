/*
** my_isalnum.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_isalpha(int c);
int	my_isdigit(int c);

int	my_isalnum(int c)
{
  return my_isalpha(c) || my_isdigit(c);
}
