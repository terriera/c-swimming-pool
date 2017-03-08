/*
** get_day.c for 2002 swimming pool
**
** Made by gumhead
**
*/

static const unsigned int	t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
static const unsigned int	convert[] = { 6, 0, 1, 2, 3, 4, 5 };

/*
** Return value: an unsigned integer between 0 and 6 with the following
** pattern: 0 => sunday; 1 => monday ... 6 => saturday.
** So we have to use the "convert" array to conform to the topic.
*/
static unsigned int	day_of_week(int d, int m, int y)
{
  unsigned int		index;

  y -= m < 3;
  index = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
  return convert[index];
}

static int	my_isdigit(int c)
{
  return '0' <= c && '9' >= c;
}

static unsigned		parse_uint(char *nptr, char **endptr)
{
  unsigned		result;

  result = 0;
  if (0 == nptr)
    return 0;
  if ('\0' == *nptr)
  {
    *endptr = nptr;
    return 0;
  }
  while (my_isdigit(*nptr))
  {
    result += *nptr - '0';
    if (my_isdigit(*(++nptr)))
      result *= 10;
  }
  *endptr = nptr;
  return result;
}

unsigned int	get_day(char *date)
{
  int		dmy[3];
  int		i;
  char		*pos;

  for (i = 0; i < 3; ++i)
  {
    dmy[i] = parse_uint(date, &pos);
    date = pos + 1;
  }
  return day_of_week(dmy[0], dmy[1], dmy[2]);
}
