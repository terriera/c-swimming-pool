/*
** my_ispunct.c for 2002 swimming pool
**
** Made by gumhead
**
*/

int	my_isalnum(int c);

int	my_ispunct(int c)
{
    return c >= '!' && c <= '~' && !my_isalnum(c);
}
