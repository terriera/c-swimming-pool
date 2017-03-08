#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RED     "1;31"
#define GREEN   "1;32"
#define CYAN    "1;36"
#define YELLOW  "1;33"
#define ORANGE  "0;31"

static void     print_msg(const char * msg, const char * color, int padding)
{
  char		fmt[7];

  if (isatty(STDOUT_FILENO))
    printf("\033[%sm", color);
  if (0 != padding)
    sprintf(fmt, "%%-%ds", padding);
  else
    sprintf(fmt, "%s", msg);
  printf(fmt, msg);
  if (isatty(STDOUT_FILENO))
    printf("\033[0m");
}

static void     my_assert_equal(const char * msg, int expected, int actual)
{
  int		success;

  success = expected == actual;
  print_msg(msg, YELLOW, 70);
  printf(" -> [");
  print_msg(success ? "OK" : "KO", success ? GREEN : RED, 0);
  puts("]");
  fflush(stdout);
}

void            roman(char *res, unsigned int num);
unsigned int    get_day(char *date);

int	main()
{
  char	res[1024];

  puts("===================");
  puts("  Test de roman.c  ");
  puts("===================");
  roman(res, 42);       /* XLII */
  my_assert_equal("roman(res, 42) donne \"XLII\"", 0, strcmp(res, "XLII"));
  res[0] = '\0';
  roman(res, 2013);     /* MMXIII */
  my_assert_equal("roman(res, 2013) donne \"MMXIII\"", 0, strcmp(res, "MMXIII"));
  res[0] = '\0';
  roman(res, 424242);   /* 0 */
  my_assert_equal("roman(res, 424242) donne \"0\"", 0, strcmp(res, "0"));
  res[0] = '\0';
  roman(res, 0);        /* 0 */
  my_assert_equal("roman(res, 0) donne \"0\"", 0, strcmp(res, "0"));

  puts("===================");
  puts("  Test de get_day  ");
  puts("===================");
  my_assert_equal("27/09/2002", 4, get_day("27/09/2002"));
  my_assert_equal("04/09/2000", 0, get_day("04/09/2000"));
  my_assert_equal("01/01/1980", 1, get_day("01/01/1980"));
  my_assert_equal("26/02/1978", 6, get_day("26/02/1978"));
  my_assert_equal("10/12/1983", 5, get_day("10/12/1983"));

  return 0;
}
