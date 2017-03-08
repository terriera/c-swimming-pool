/*
** my_atoi_base.c for 2002 swimming pool
**
** Made by gumhead
**
*/

static int	get_char_index(char c, const char *base)
{
  int		count;

  count = 0;
  while (*base && *base != c)
  {
    ++base;
    ++count;
  }
  return *base == c ? count : -1;
}

static unsigned int	my_strlen(const char *str)
{
  unsigned int		count;

  count = 0;
  while (*str++)
    ++count;
  return count;
}

int	my_atoi_base(const char *str, const char *base)
{
  int	base_len;
  int	result;
  int	is_neg;
  int	index;

  base_len = my_strlen(base);
  result = 0;
  is_neg = 0;
  if ('-' == *str)
  {
    is_neg = 1;
    ++str;
  }
  while ('\0' != *str)
  {
    index = get_char_index(*str, base);
    if (-1 == index)
      return 0;
    result += base_len > 1 ? index : 1;
    if ('\0' != *++str)
      result *= base_len;
  }
  return is_neg ? -result : result;
}
