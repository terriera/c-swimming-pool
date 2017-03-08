#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_fnmatch_flags.h"

#define ERROR_COLOR   "1;31"       /* Errors */
#define HILITE_COLOR  "1;33;4"     /* Matches */
#define INFO_COLOR    "1;32"       /* Information (e.g. current text, globality) */
#define MATCHES_COLOR "37"         /* Match count */
#define PROMPT_COLOR  "1;36"       /* Prompt */
#define TITLE_COLOR   "1;33"       /* Emphasized messages */

int		my_fnmatch(const char *pattern, const char *string, int flags);

static void	test_basics();
static void	test_with_stars();
static void	test_with_qmarks();
static void	test_with_classes();
static void	test_with_ranges();
static void	test_with_complements();
static void	test_with_count_matches();

int	main()
{
  test_basics();
  test_with_stars();
  test_with_qmarks();
  test_with_classes();
  test_with_ranges();
  test_with_complements();
  test_with_count_matches();
  return 0;
}

static void	print_msg(const char * msg, const char * color, int padding)
{
  char fmt[7];

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

static void	my_assert(const char * msg, int ok)
{
  print_msg(msg, TITLE_COLOR, 70);
  printf(" -> [");
  print_msg(ok ? "OK" : "KO", ok ? INFO_COLOR : ERROR_COLOR, 0);
  puts("]");
  fflush(stdout);
}

static void	print_not_handled(const char * msg)
{
  print_msg(msg, TITLE_COLOR, 63);
  printf(" -> ");
  print_msg("not handled\n", ERROR_COLOR, 1);
  fflush(stdout);
}

static void	test_basics()
{
  puts("---------------");
  puts("  Basic tests");
  puts("---------------");
  my_assert("0 < my_fnmatch(\"abba\", \"abba\", 0)",
            0 < my_fnmatch("abba", "abba", 0));
  my_assert("0 < my_fnmatch(\"abba\", \"xabbay\", 0)",
            0 < my_fnmatch("abba", "xabbay", 0));
  my_assert("0 == my_fnmatch(\"abba\", \"uvwxyz\", 0)",
            0 == my_fnmatch("abba", "uvwxyz", 0));
  my_assert("0 == my_fnmatch(\"abba\", \"xabbby\", 0)",
            0 == my_fnmatch("abba", "xabbby", 0));
  my_assert("0 < my_fnmatch(\"\", \"xabbby\", 0)",
            0 < my_fnmatch("", "xabbby", 0));
  my_assert("0 < my_fnmatch(\"\", \"\", 0)",
            0 < my_fnmatch("", "", 0));
}

static void	test_with_stars()
{
  puts("--------------------");
  puts("  Tests with stars");
  puts("--------------------");
  my_assert("0 < my_fnmatch(\"ab*a\", \"abba\", 0)",
            0 < my_fnmatch("ab*a", "abba", 0));
  my_assert("0 < my_fnmatch(\"*ba\", \"abba\", 0)",
            0 < my_fnmatch("*ba", "abba", 0));
  my_assert("0 < my_fnmatch(\"ab*\", \"abba\", 0)",
            0 < my_fnmatch("ab*", "abba", 0));
  my_assert("0 < my_fnmatch(\"a**a\", \"abba\", 0)",
            0 < my_fnmatch("a**a", "abba", 0));
  my_assert("0 < my_fnmatch(\"a**a\", \"dsf sab$*bapi qdsq!\", 0)",
            0 < my_fnmatch("a**a", "dsf sabb$*api qdsq!", 0));
  my_assert("0 < my_fnmatch(\"*b*\", \"abba\", 0)",
            0 < my_fnmatch("*b*", "abba", 0));
  my_assert("0 < my_fnmatch(\"*foo*\", \"foo\", 0)",
            0 < my_fnmatch("*foo*", "foo", 0));
  my_assert("0 < my_fnmatch(\"*foo*\", \"fooxxx\", 0)",
            0 < my_fnmatch("*foo*", "fooxxx", 0));
  my_assert("0 < my_fnmatch(\"*foo*\", \"123foo\", 0)",
            0 < my_fnmatch("*foo*", "123foo", 0));
  my_assert("0 < my_fnmatch(\"*foo*\", \"ZZZfoo@@@\", 0)",
            0 < my_fnmatch("*foo*", "ZZZfoo@@@", 0));
  my_assert("0 < my_fnmatch(\"*******b***\", \"abba\", 0)",
            0 < my_fnmatch("*******b***", "abba", 0));
  my_assert("0 < my_fnmatch(\"*\", \"abba\", 0)",
            0 < my_fnmatch("*", "abba", 0));
  my_assert("0 < my_fnmatch(\"**********\", \"abba\", 0)",
            0 < my_fnmatch("**********", "abba", 0));
  my_assert("0 == my_fnmatch(\"c*\", \"abba\", 0)",
            0 == my_fnmatch("c*", "abba", 0));
  my_assert("0 == my_fnmatch(\"*c\", \"abba\", 0)",
            0 == my_fnmatch("*c", "abba", 0));
  my_assert("0 == my_fnmatch(\"*c*\", \"abba\", 0)",
            0 == my_fnmatch("*c*", "abba", 0));
  my_assert("0 < my_fnmatch(\"*\", \"\", 0)",
            0 < my_fnmatch("*", "", 0));
  my_assert("0 == my_fnmatch(\"*z\", \"\", 0)",
            0 == my_fnmatch("*z", "", 0));
}

static void	test_with_qmarks()
{
  puts("----------------------------------");
  puts("  Tests with MY_FNM_HANDLE_QMARK");
  puts("----------------------------------");
  if (-1 == my_fnmatch("?", "a", MY_FNM_HANDLE_QMARK))
  {
    print_not_handled("MY_FNM_HANDLE_QMARK");
    exit(0);
  }
  my_assert("0 < my_fnmatch(\"ab?a\", \"abba\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("ab?a", "abba", MY_FNM_HANDLE_QMARK));
  my_assert("0 < my_fnmatch(\"?at\", \"Cat\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("?at", "Cat", MY_FNM_HANDLE_QMARK));
  my_assert("0 < my_fnmatch(\"?at\", \"cat\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("?at", "cat", MY_FNM_HANDLE_QMARK));
  my_assert("0 < my_fnmatch(\"?at\", \"this is batman\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("?at", "this is batman", MY_FNM_HANDLE_QMARK));
  my_assert("0 == my_fnmatch(\"?at\", \"at\", MY_FNM_HANDLE_QMARK)",
            0 == my_fnmatch("?at", "at", MY_FNM_HANDLE_QMARK));

  my_assert("0 < my_fnmatch(\"???\", \"abc\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("???", "abc", MY_FNM_HANDLE_QMARK));
  my_assert("0 == my_fnmatch(\"???\", \"at\", MY_FNM_HANDLE_QMARK)",
            0 == my_fnmatch("???", "at", MY_FNM_HANDLE_QMARK));
  my_assert("0 < my_fnmatch(\"???\", \"abcd\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("???", "abcd", MY_FNM_HANDLE_QMARK));
  my_assert("0 < my_fnmatch(\"???*\", \"abc\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("???*", "abc", MY_FNM_HANDLE_QMARK));
  my_assert("0 < my_fnmatch(\"???*\", \"abcdefgh\", MY_FNM_HANDLE_QMARK)",
            0 < my_fnmatch("???*", "abcdefgh", MY_FNM_HANDLE_QMARK));
  my_assert("0 == my_fnmatch(\"*???\", \"at\", MY_FNM_HANDLE_QMARK)",
            0 == my_fnmatch("*???", "at", MY_FNM_HANDLE_QMARK));
}

static void	test_with_classes()
{
  puts ("---------------------------------");
  puts ("  Tests with FNM_HANDLE_CLASSES");
  puts ("---------------------------------");
  if (-1 == my_fnmatch("", "", MY_FNM_HANDLE_CLASSES))
  {
    print_not_handled("MY_FNM_HANDLE_CLASSES");
    exit(0);
  }
  my_assert("0 < my_fnmatch(\"ab[b]a\", \"abba\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("ab[b]a", "abba", MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"ab[abc]a\", \"abba\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("ab[abc]a", "abba", MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"ab[01234567]a\", \"a6b\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("[01234567]", "a6b", MY_FNM_HANDLE_CLASSES));

  my_assert("0 == my_fnmatch(\"ab[xyz]a\", \"abva\", MY_FNM_HANDLE_CLASSES)",
            0 == my_fnmatch("ab[xyz]a", "abva", MY_FNM_HANDLE_CLASSES));

  my_assert("0 == my_fnmatch(\"abb[]a\", \"abba\", MY_FNM_HANDLE_CLASSES)",
            0 == my_fnmatch("abb[]a", "abba", MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"abb[]xyz]a\", \"abb]a\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("abb[]xyz]a", "abb]a", MY_FNM_HANDLE_CLASSES));

  my_assert("0 < my_fnmatch(\"[][!]\", \"[\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("[][!]", "[", MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"[][!]\", \"]\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("[][!]", "]", MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"[][!]\", \"!\", MY_FNM_HANDLE_CLASSES)",
            0 < my_fnmatch("[][!]", "!", MY_FNM_HANDLE_CLASSES));
}

static void	test_with_ranges()
{
  puts ("--------------------------------");
  puts ("  Tests with FNM_HANDLE_RANGES");
  puts ("--------------------------------");
  if (-1 == my_fnmatch("", "", MY_FNM_HANDLE_RANGES))
  {
    print_not_handled("MY_FNM_HANDLE_RANGES");
    exit(0);
  }
  my_assert("0 < my_fnmatch(\"ab[a-z]a\", \"abba\", MY_FNM_HANDLE_RANGES)",
            0 < my_fnmatch("ab[a-z]a", "abba", MY_FNM_HANDLE_RANGES));
  my_assert("0 == my_fnmatch(\"ab[0-9]a\", \"abba\", MY_FNM_HANDLE_RANGES)",
            0 == my_fnmatch("ab[0-9]a", "abba", MY_FNM_HANDLE_RANGES));
  my_assert("0 == my_fnmatch(\"ab[0-9a-f]a\", \"4\", MY_FNM_HANDLE_RANGES)",
            0 == my_fnmatch("ab[0-9a-f]a", "4", MY_FNM_HANDLE_RANGES));
  my_assert("0 < my_fnmatch(\"ab[0-9a-f]a\", \"xabfax\", MY_FNM_HANDLE_RANGES)",
            0 < my_fnmatch("ab[0-9a-f]a", "xabfax", MY_FNM_HANDLE_RANGES));
  my_assert("0 < my_fnmatch(\"ab[0-9a-f]a\", \"abaa\", MY_FNM_HANDLE_RANGES)",
            0 < my_fnmatch("ab[0-9a-f]a", "abaa", MY_FNM_HANDLE_RANGES));
  my_assert("0 == my_fnmatch(\"ab[0-9a-f]a\", \"abAa\", MY_FNM_HANDLE_RANGES)",
            0 == my_fnmatch("ab[0-9a-f]a", "abAa", MY_FNM_HANDLE_RANGES));
}

static void	test_with_complements()
{
  puts ("-------------------------------------");
  puts ("  Tests with FNM_HANDLE_COMPLEMENTS");
  puts ("-------------------------------------");
  if (-1 == my_fnmatch("", "", MY_FNM_HANDLE_COMPLEMENTS))
  {
    print_not_handled("MY_FNM_HANDLE_COMPLEMENTS");
    exit(0);
  }
  my_assert("0 < my_fnmatch(\"[!abcde]\", \"x\", FNM_COMPLEMENTS | FNM_CLASSES)",
            0 < my_fnmatch("[!abcde]", "x", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"[!abcde]\", \"axbc\", FNM_COMPLEMENTS | FNM_CLASSES)",
            0 < my_fnmatch("[!abcde]", "axbc", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_CLASSES));
  my_assert("0 == my_fnmatch(\"[!abcde]\", \"a\", FNM_EOMPLEMENTS | FNM_CLASSES)",
            0 == my_fnmatch("[!abcde]", "a", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"[!abcde]\", \"abcyde\", FNM_COMPLEMENTS | FNM_CLASSES)",
            0 < my_fnmatch("[!abcde]", "abcyde", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_CLASSES));
  my_assert("0 < my_fnmatch(\"[!]a-]\", \"x\", FNM_COMPLEMENTS | FNM_CLASSES)",
            0 < my_fnmatch("[!]a-]", "x", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_CLASSES));
  my_assert("0 == my_fnmatch(\"[!]a-]\", \"]\", FNM_COMPLEMENTS | FNM_CLASSES)",
            0 == my_fnmatch("[!]a-]", "]", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_CLASSES));

  my_assert("0 < my_fnmatch(\"[!a-e]\", \"x\", FNM_COMPLEMENTS | FNM_RANGES)",
            0 < my_fnmatch("[!a-e]", "x", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_RANGES));
  my_assert("0 < my_fnmatch(\"[!a-e]\", \"axbc\", FNM_COMPLEMENTS | FNM_RANGES)",
            0 < my_fnmatch("[!a-e]", "axbc", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_RANGES));
  my_assert("0 == my_fnmatch(\"[!a-e]\", \"a\", FNM_COMPLEMENTS | FNM_RANGES)",
            0 == my_fnmatch("[!a-e]", "a", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_RANGES));
  my_assert("0 < my_fnmatch(\"[!a-e]\", \"abcyde\", FNM_COMPLEMENTS | FNM_RANGES)",
            0 < my_fnmatch("[!a-e]", "abcyde", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_RANGES));
  my_assert("0 < my_fnmatch(\"[!0-9a-f]\", \"abcD7\", FNM_COMPLEMENTS | FNM_RANGES)",
            0 < my_fnmatch("[!0-9a-f]", "abcD7", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_RANGES));
  my_assert("0 == my_fnmatch(\"[!0-9a-f]\", \"abcd7\", FNM_COMPLEMENTS | FNM_RANGES)",
            0 == my_fnmatch("[!0-9a-f]", "abcd7", MY_FNM_HANDLE_COMPLEMENTS | MY_FNM_HANDLE_RANGES));
}

static void	test_with_count_matches()
{
  puts ("-------------------------------------");
  puts ("  Tests with FNM_COUNT_MATCHES");
  puts ("-------------------------------------");
  if (-1 == my_fnmatch("", "", MY_FNM_COUNT_MATCHES))
  {
    print_not_handled("MY_FNM_COUNT_MATCHES");
    exit(0);
  }
  my_assert("1 == my_fnmatch(\"a*a\", \"abba\", MY_FNM_COUNT_MATCHES)",
            1 == my_fnmatch("a*a", "abba", MY_FNM_COUNT_MATCHES));
  my_assert("16 == my_fnmatch(\"*b*\", \"abcbd\", MY_FNM_COUNT_MATCHES)",
            16 == my_fnmatch("*b*", "abcbd", MY_FNM_COUNT_MATCHES));
  my_assert("3 == my_fnmatch(\"a*a\", \"ababa\", MY_FNM_COUNT_MATCHES)",
            3 == my_fnmatch("a*a", "ababa", MY_FNM_COUNT_MATCHES));
  my_assert("3 == my_fnmatch(\"a**a\", \"abba\", MY_FNM_COUNT_MATCHES)",
            3 == my_fnmatch("a**a", "abba", MY_FNM_COUNT_MATCHES));
  my_assert("1 == my_fnmatch(\"a??a\", \"abba\", COUNT_MATCHES | MY_FNM_HANDLE_QMARK)",
            1 == my_fnmatch("a??a", "abba", MY_FNM_COUNT_MATCHES | MY_FNM_HANDLE_QMARK));
  my_assert("10 == my_fnmatch(\"*??*\", \"abba\", COUNT_MATCHES | HANDLE_QMARK)",
            10 == my_fnmatch("*??*", "abba", MY_FNM_COUNT_MATCHES | MY_FNM_HANDLE_QMARK));
  my_assert("2 == my_fnmatch(\"a?a\", \"ababa\", COUNT_MATCHES | HANDLE_QMARK)",
            2 == my_fnmatch("a?a", "ababa", MY_FNM_COUNT_MATCHES | MY_FNM_HANDLE_QMARK));
  my_assert("3 == my_fnmatch(\"\", \"ab\", COUNT_MATCHES)",
            3 == my_fnmatch("", "ab", MY_FNM_COUNT_MATCHES));
  my_assert("6 == my_fnmatch(\"a**\", \"abc\", COUNT_MATCHES)",
            6 == my_fnmatch("a**", "abc", MY_FNM_COUNT_MATCHES));
  my_assert("2 == my_fnmatch(\"a*\", \"ab\", COUNT_MATCHES)",
            2 == my_fnmatch("a*", "ab", MY_FNM_COUNT_MATCHES));
  my_assert("1 == my_fnmatch(\"*\", \"\", COUNT_MATCHES)",
            1 == my_fnmatch("*", "", MY_FNM_COUNT_MATCHES));
  my_assert("3 == my_fnmatch(\"a**\", \"ab\", COUNT_MATCHES)",
            3 == my_fnmatch("a**", "ab", MY_FNM_COUNT_MATCHES));
}

