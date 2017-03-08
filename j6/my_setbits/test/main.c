/*
 * Change p bits à partir de la position n dans l'entier nb, en les remplaçant
 * par le nombre correspondant de bits pris dans les premières positions de x.
 *
 * La fonction renvoie le résultat après modification.
 *
 * Exemple:
 *   my_putword(my_setbits(0, 3, 4, 42))
 * affiche:
 *   00000000000000000000000001010000
 *
 * Autre exemple:
 *   my_putword(0x38)
 * affiche:
 *   00000000000000000000000000111000
 *
 *   my_putword(my_setbits(-1, 5, 7, 0x38))
 * affiche:
 *   11111111111111111111011100011111
 *
 * On remarque bien que les bits proviennent des bits de poids faible de x.
 *
 * Attention, cette fonction n'affiche rien !
 */
#include <unistd.h>

unsigned	my_setbits(unsigned nb, int n, int p, unsigned x);

static void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}

static void	my_putword(int n)
{
  unsigned int	mask;
  
  mask = 1 << ((sizeof(int) * 8) - 1);
  while (mask > 0)
  {
    my_putchar(n & mask ? '1' : '0');
    mask >>= 1;
  }
  my_putchar('\n');
}

int main()
{
  my_putword(my_setbits(0, 3, 4, 42));
  my_putword(my_setbits(-1, 5, 7, 0x38));
  my_putword(my_setbits(-1, 7, 22, 0x12345678));
  return 0;
}
