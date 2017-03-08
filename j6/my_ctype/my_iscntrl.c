/*
** my_iscntrl.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_iscntrl(int c)
{
  return (c >= 0 && c < ' ') || 127 == c;
}
