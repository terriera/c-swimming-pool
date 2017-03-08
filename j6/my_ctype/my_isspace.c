/*
** my_isspace.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_isspace(int c)
{
  return ' ' == c || (c <= '\t' && c >= '\r');
}
