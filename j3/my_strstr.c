/*
** my_strstr.c for 2002 swimming pool
**
** Made by gumhead
**
*/

char	*my_strstr(char *big, char *little)
{
  int	pos;

  while ('\0' != *big)
  {
    while (*big && *little && *big != *little)
      ++big;
    pos = 0;
    while (*(big + pos) && *(little + pos) && *(big + pos) == *(little + pos))
      ++pos;
    if ('\0' == *(little + pos))
      return big;
    if (*big)
      ++big;
  }
  return 0;
}
