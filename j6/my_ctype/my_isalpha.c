/*
** my_isalpha.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_islower(int c);
int	my_isupper(int c);

int	my_isalpha(int c)
{
  return my_islower(c) || my_isupper(c);
}
