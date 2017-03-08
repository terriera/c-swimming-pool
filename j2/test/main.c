#include <stdio.h>
#include <limits.h>
#include "../j2.h"

int	main(void) 
{
  char	*str;
  int	i1;
  i1 = 42;
  str = "String:";
  my_putstr(str);
  my_putnbr(i1);
  i1 = my_atoi("24");
  my_putstr("\nSeminaire\n");
  my_putnbr(i1);
  my_putstr("\nAllez-y\n");
  i1 = my_atoi_base("bababa", "ab");
  my_putnbr(i1);
  my_putstr(":Soit en base hexa:");
  my_putnbr_base(i1, "0123456789abcdef");
  my_putstr(":Soit en binaire:");
  my_putnbr_base(i1, "01");
  my_putchar('\n');
  i1 = my_atoi_base("-bababa", "ab");
  my_putnbr(i1);
  my_putstr(":Soit en base hexa:");
  my_putnbr_base(i1, "0123456789abcdef");
  my_putstr(":Soit en binaire:");
  my_putnbr_base(i1, "01");
  my_putstr("\nSeminaire Allez-y\n");
  my_putstr("INT_MIN : ");
  my_putnbr(INT_MIN);
  my_putstr("\nINT_MAX : ");
  my_putnbr(INT_MAX);
  my_putstr("\nINT_MIN : ");
  my_putnbr_base(INT_MIN, "0123456789abcdef");
  my_putstr("\nINT_MAX : ");
  my_putnbr_base(INT_MAX, "0123456789abcdef");
  my_putstr("\nINT_MIN : ");
  my_putnbr_base(INT_MIN, "01");
  my_putstr("\nINT_MAX : ");
  my_putnbr_base(INT_MAX, "01");
  my_putstr("\n42 in base \"!\": ");
  my_putnbr_base(42, "!");
  my_putstr("\n-42 in base \"!\": ");
  my_putnbr_base(-42, "!");
  my_putchar('\n');
  return 0;
}
