/*
** my_fnmatch.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <stdlib.h>
#include "my_fnmatch_flags.h"

static int	parse_pattern(const char **pattern, char c, int flags, int *matched)
{
  while (']' != **pattern)
  {
    if ((MY_FNM_HANDLE_RANGES & flags) && '-' == *(*pattern + 1))
    {
      if ('\0' ==  *(*pattern + 2) || ']' == *(*pattern + 2))
        return 0;
      if (**pattern <= c && c <= *(*pattern + 2))
        *matched = 1;
      *pattern += 2;
    }
    else if (c == **pattern)
      *matched = 1;
    ++*pattern;
  }
  return 1;
}

static int	handle_classes(const char **pattern, const char **string,
		               int flags)
{
  int		matched;
  int		complement;

  matched = 0;
  ++*pattern;
  if ((complement = (MY_FNM_HANDLE_COMPLEMENTS & flags) && '!' == **pattern))
    ++*pattern;
  if (']' == **pattern)
  {
    matched = (']' == **string);
    ++*pattern;
  }
  if (0 == parse_pattern(pattern, **string, flags, &matched))
    return 0;
  if (complement)
  {
    if (!matched)
      ++*pattern;
    return !matched;
  }
  if (!matched)
    return 0;
  ++*pattern;
  ++*string;
  return 1;
}

static int	handle_qmark(const char **pattern, const char **string)
{
  ++*pattern;
  if ('\0' == **string)
    return 0;
  ++*string;
  return 1;
}

static int	handle_raw_chars(const char **pattern, const char **string)
{
  if (**pattern != **string)
    return 0;
  ++*pattern;
  ++*string;
  return 1;
}

static int	nmatch(const char *pattern, const char *string, int flags)
{
  while ('\0' != *pattern)
  {
    if ('\0' == *string)
    {
      while ('*' == *pattern)
        ++pattern;
      return '\0' == *pattern;
    }
    if ('*' == *pattern)
      return nmatch(pattern, string + 1, flags) +
             nmatch(pattern + 1, string, flags);
    else if ('?' == *pattern && (MY_FNM_HANDLE_QMARK & flags))
    {
      if (0 == handle_qmark(&pattern, &string))
      	return 0;
    }
    else if ('[' == *pattern && (MY_FNM_HANDLE_CLASSES & flags))
    {
      if (0 == handle_classes(&pattern, &string, flags))
        return 0;
    }
    else if (0 == handle_raw_chars(&pattern, &string))
      return 0;
  }
  return 1;
}

/*
**  "while {}" instead of "do {} while" would return 0 in case string is empty.
*/
int	my_fnmatch(const char *pattern, const char *string, int flags)
{
  int	count;

  if (NULL == pattern || NULL == string)
    return 0;
  if (MY_FNM_HANDLE_RANGES == (flags & MY_FNM_HANDLE_RANGES))
    flags |= MY_FNM_HANDLE_CLASSES;
  count = 0;
  do
  {
    count += nmatch(pattern, string, flags);
  }
  while ('\0' != *string++);
  return count;
}
