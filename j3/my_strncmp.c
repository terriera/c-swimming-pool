/*
** my_strncmp.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_strncmp(const char *s1, const char *s2, int n)
{
  while (n--)
  {
    if (!*s1 || !*s2 || *s1 - *s2)
      return *s1 - *s2;
    ++s1;
    ++s2;
  }
  return 0;
}
