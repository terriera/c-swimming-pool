#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../j3.h"

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

int	main()
{
  char	str1[8];
  char	str2[8] = "what ?";

  my_assert_equal("Testing my_factorial(0)",          1, my_factorial(1));
  my_assert_equal("Testing my_factorial(1)",          1, my_factorial(1));
  my_assert_equal("Testing my_factorial(2)",          2, my_factorial(2));
  my_assert_equal("Testing my_factorial(3)",          6, my_factorial(3));
  my_assert_equal("Testing my_factorial(4)",         24, my_factorial(4));
  my_assert_equal("Testing my_factorial(5)",        120, my_factorial(5));
  my_assert_equal("Testing my_factorial(6)",        720, my_factorial(6));
  my_assert_equal("Testing my_factorial(7)",       5040, my_factorial(7));
  my_assert_equal("Testing my_factorial(8)",      40320, my_factorial(8));
  my_assert_equal("Testing my_factorial(9)",     362880, my_factorial(9));
  my_assert_equal("Testing my_factorial(10)",   3628800, my_factorial(10));
  my_assert_equal("Testing my_factorial(11)",  39916800, my_factorial(11));
  my_assert_equal("Testing my_factorial(12)", 479001600, my_factorial(12));

  my_assert_equal("Testing my_square(5)",  25, my_square(5));
  my_assert_equal("Testing my_square(-5)", 25, my_square(-5));

  my_assert_equal("Testing my_power(1, 1)",           1, my_power(1, 1));
  my_assert_equal("Testing my_power(2, 3)",           8, my_power(2, 3));
  my_assert_equal("Testing my_power(4, 5)",        1024, my_power(4, 5));
  my_assert_equal("Testing my_power(7, 6)",      117649, my_power(7, 6));
  my_assert_equal("Testing my_power(8, 9)",   134217728, my_power(8, 9));
  my_assert_equal("Testing my_power(9, 10)", 3486784401, my_power(9, 10));
  my_assert_equal("Testing my_power(42, 0)",          1, my_power(42, 0));
  my_assert_equal("Testing my_power(0, 42)",          0, my_power(0, 42));

  my_assert_equal("Testing my_is_prime(0)",  0, my_is_prime(0));
  my_assert_equal("Testing my_is_prime(1)",  0, my_is_prime(1));
  my_assert_equal("Testing my_is_prime(2)",  1, my_is_prime(2));
  my_assert_equal("Testing my_is_prime(3)",  1, my_is_prime(3));
  my_assert_equal("Testing my_is_prime(4)",  0, my_is_prime(4));
  my_assert_equal("Testing my_is_prime(5)",  1, my_is_prime(5));
  my_assert_equal("Testing my_is_prime(6)",  0, my_is_prime(6));
  my_assert_equal("Testing my_is_prime(7)",  1, my_is_prime(7));
  my_assert_equal("Testing my_is_prime(8)",  0, my_is_prime(8));
  my_assert_equal("Testing my_is_prime(9)",  0, my_is_prime(9));
  my_assert_equal("Testing my_is_prime(10)", 0, my_is_prime(10));
  my_assert_equal("Testing my_is_prime(11)", 1, my_is_prime(11));
  my_assert_equal("Testing my_is_prime(12)", 0, my_is_prime(12));
  my_assert_equal("Testing my_is_prime(13)", 1, my_is_prime(13));
  my_assert_equal("Testing my_is_prime(14)", 0, my_is_prime(14));
  my_assert_equal("Testing my_is_prime(15)", 0, my_is_prime(15));
  my_assert_equal("Testing my_is_prime(16)", 0, my_is_prime(16));
  my_assert_equal("Testing my_is_prime(17)", 1, my_is_prime(17));
  my_assert_equal("Testing my_is_prime(113)", 1, my_is_prime(113));
  my_assert_equal("Testing my_is_prime(119)", 0, my_is_prime(119));
  my_assert_equal("Testing my_is_prime(120)", 0, my_is_prime(120));

  my_assert_equal("Testing my_strlen(\"\")", 0, my_strlen(""));
  my_assert_equal("Testing my_strlen(\"my_strlen\")", 9, my_strlen("my_strlen"));

  my_strncpy(str1, str2, 8);
  my_assert_equal("Testing my_strncpy 1", 0, strcmp(str1, str2));
  my_strncpy(str1, "abcdefg", 8);
  my_assert_equal("Testing my_strncpy 2", 1, strncmp(str1, str2, 20));

  my_revstr(str1, str2);
  my_assert_equal("Testing my_revstr", 0, strcmp("? tahw", str1));

  my_strncpy(str1, "abcdefg", 8);
  my_strncpy(str2, "cde", 4);
  my_assert_equal("Testing my_strstr", (int)(str1 + 2), (int)my_strstr(str1, str2));

  my_strncpy(str1, "abcdefg", 8);
  my_strncpy(str2, "abcdefg", 8);
  my_assert_equal("Testing my_strncmp", 0, my_strncmp(str1, str2, 20));
  return 0;
}
