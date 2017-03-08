/*
** my_strncpy.c for 2002 swimming pool
**
** Made by gumhead
**
*/

char	*my_strncpy(char *dest, const char *src, int n)
{
  char	*cpydest;

  cpydest = dest;
  while (n--)
    *dest++ = '\0' == *src ? '\0' : *src++;
  return cpydest;
}
