/*
** roman.c for 2002 swimming pool
**
** Made by gumhead
**
*/

static char		*my_strcpy(char *dest, const char *src);
static unsigned int	my_strlen(const char *str);

#define ROMAN_MAX	3999
#define FACTORS_SIZE	13

static const struct
{
  char	*roman;
  int	decimal;
} factors[] =
{
  {"M", 1000},
  {"CM", 900},
  {"D",  500},
  {"CD", 400},
  {"C",  100},
  {"XC",  90},
  {"L",   50},
  {"XL",  40},
  {"X",   10},
  {"IX",   9},
  {"V",    5},
  {"IV",   4},
  {"I",    1}
};

void		roman(char *res, unsigned int num)
{
  unsigned int	count;
  int		i;

  if (0 == num || ROMAN_MAX < num)
  {
    res[0] = '0';
    res[1] = '\0';
    return;
  }
  for (i = 0; i < FACTORS_SIZE; ++i)
  {
    count = num / factors[i].decimal;
    num = num % factors[i].decimal;
    while (count--)
    {
      my_strcpy(res, factors[i].roman);
      res += my_strlen(factors[i].roman);
    }
  }
}

static char	*my_strcpy(char *dest, const char *src)
{
  int		i;

  for (i = 0; '\0' != src[i]; ++i)
    dest[i] = src[i];
  dest[i] = '\0';
  return dest;
}

static unsigned int	my_strlen(const char *str)
{
  unsigned int		count;

  count = 0;
  while(*str++)
    ++count;
  return count;
}
