#include <stdio.h>

void my_hexdump(void *data, unsigned size);

int	main()
{
  my_hexdump("0123456789ABCDEFfedcba9876543210blah blah\n", 42);
  my_hexdump("toto", 3);
  my_hexdump("toto", 42);
  my_hexdump("lajdfls\20jdfhsdvioh987wrk\300jshdf98y4thjs908duf409ut12\3", 31);
  return 0;
}
