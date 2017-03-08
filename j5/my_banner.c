/*
** my_banner.c for 2002 swimming pool
**
** Made by gumhead
**
*/

#include <unistd.h>

#define HEIGHT		8
#define WIDTH		8
#define MAX_CHARS	10

/*
** Since two dimensional arrays are forbidden, we will use a regular string.
** This string can be broken down into 37 segments of 8 sub-segment each.
** A segment represents a letter, a digit or a space and thus is 64 chars long.
** A sub-segment represents a line of the letter and thus is 8 chars long.
** 8 * 8 * 37 = 
*/
static const char	*big_chars = 
  "                                                                " /*   */
  "          ###    #   #  #     # #     # #     #  #   #    ###   " /* 0 */
  "           #      ##     # #       #       #       #     #####  " /* 1 */
  "         #####  #     #       #  #####  #       #       ####### " /* 2 */
  "         #####  #     #       #  #####        # #     #  #####  " /* 3 */
  "        #       #    #  #    #  #    #  #######      #       #  " /* 4 */
  "        ####### #       #       ######        # #     #  #####  " /* 5 */
  "         #####  #     # #       ######  #     # #     #  #####  " /* 6 */
  "        ####### #    #      #      #      #       #       #     " /* 7 */
  "         #####  #     # #     #  #####  #     # #     #  #####  " /* 8 */
  "         #####  #     # #     #  ######       # #     #  #####  " /* 9 */
  "           #      # #    #   #  #     # ####### #     # #     # " /* A */
  "        ######  #     # #     # ######  #     # #     # ######  " /* B */
  "         #####  #     # #       #       #       #     #  #####  " /* C */
  "        ######  #     # #     # #     # #     # #     # ######  " /* D */
  "        ####### #       #       #####   #       #       ####### " /* E */
  "        ####### #       #       #####   #       #       #       " /* F */
  "         #####  #     # #       #  #### #     # #     #  #####  " /* G */
  "        #     # #     # #     # ####### #     # #     # #     # " /* H */
  "          ###      #       #       #       #       #      ###   " /* I */
  "              #       #       #       # #     # #     #  #####  " /* J */
  "        #    #  #   #   #  #    ###     #  #    #   #   #    #  " /* K */
  "        #       #       #       #       #       #       ####### " /* L */
  "        #     # ##   ## # # # # #  #  # #     # #     # #     # " /* M */
  "        #     # ##    # # #   # #  #  # #   # # #    ## #     # " /* N */
  "        ####### #     # #     # #     # #     # #     # ####### " /* O */
  "        ######  #     # #     # ######  #       #       #       " /* P */
  "         #####  #     # #     # #     # #   # # #    #   #### # " /* Q */
  "        ######  #     # #     # ######  #   #   #    #  #     # " /* R */
  "         #####  #     # #        #####        # #     #  #####  " /* S */
  "        #######    #       #       #       #       #       #    " /* T */
  "        #     # #     # #     # #     # #     # #     #  #####  " /* U */
  "        #     # #     # #     # #     #  #   #    # #      #    " /* V */
  "        #     # #  #  # #  #  # #  #  # #  #  # #  #  #  ## ##  " /* W */
  "        #     #  #   #    # #      #      # #    #   #  #     # " /* X */
  "        #     #  #   #    # #      #       #       #       #    " /* Y */
  "        #######      #      #      #      #      #      ####### "; /* Z */

static const char	*small_chars = " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static int	my_printchar(int c)
{
  if (0 > write(1, &c, 1))
    return -1;
  return 0;
}

static void	my_printstr(const char *str)
{
  while ('\0' != *str)
    my_printchar(*str++);
}

static char	*my_strncpy(char *dest, const char *src, int n)
{
  int		i;

  for (i = 0; i < n && '\0' != src[i]; ++i)
    dest[i] = src[i];
  while (i < n)
    dest[i++] = '\0';
  return dest;
}

static unsigned	my_strlen(const char *str)
{
  unsigned	count;

  count = 0;
  while ('\0' != str[count])
    ++count;
  return count;
}

/*
** Appends a copy of src to the end of dest, but not more than n characters.
*/
static char	*my_strncat(char *dest, const char *src, unsigned n)
{
  unsigned	off;

  off = my_strlen(dest);
  do
    dest[off++] = *src;
  while ('\0' != *src++ && --n);
  dest[off] = '\0';
  return dest;
}

/*
** Gets the index of c within the small_chars array.
** The search is case insensitive.
** This helper function is useful the get the right position in the
** big_chars array.
*/
static int	get_small_chars_index(char c)
{
  int		index;

  if (c >= 'a' && c <= 'z')
    c -= 'a' - 'A';
  for (index = 0; '\0' != small_chars[index]; ++index)
    if (c == small_chars[index])
      return index;
  return 0;
}

/*
** The "print_line" function prints the nth line of its "str" argument.
** print_line prints the nth line of str. 0 <= n < HEIGHT.
** In order to print the (shortened) text, it uses a WIDTH * MAX_CHARS
** buffer (+ 1 for '\0').
** For each character in the givent text, it gets its position in small_chars
** and then deduce its position in big_chars by multiplying it by
** WIDTH * HEIGHT, to be positioned at the beginning of the right character.
** We still have to add the "line" argument multiplied by WIDTH to get the
** right offset.
*/
static void	print_line(const char *str, int line)
{
  char		buffer[WIDTH * MAX_CHARS + 1];
  int 		pos;
  int		i;

  buffer[0] = '\0';
  for (i = 0; '\0' != str[i]; ++i)
  {
    pos = get_small_chars_index(str[i]) * WIDTH * HEIGHT;
    my_strncat(buffer, big_chars + pos + line * WIDTH, WIDTH);
  }
  my_printstr(buffer);
  my_printchar('\n');
}

/*
** The "print_banner" function shortens its "str" argument to the maximum
** amount of chars that can be displayed considering the width of a big char.
** Following which it will print the text line after line, thus HEIGHT times.
*/
static void	print_banner(char *str)
{
  char		short_str[MAX_CHARS + 1];
  int		line;

  my_strncpy(short_str, str, MAX_CHARS);
  short_str[MAX_CHARS] = '\0';
  for (line = 0; line < HEIGHT; ++line)
    print_line(short_str, line);
  my_printchar('\n');
}

int main(int ac, char *av[])
{
  while (0 != --ac)
    print_banner(*++av);
  return 0;
}
