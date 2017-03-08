/*
** j11.h for 2002 swimming pool
**
** Made by gumhead
**
*/

#ifndef J11_H_
# define J11_H_

# define ERR_NONE 0
# define ERR_DIV  1
# define ERR_SYN  2
# define ERR_ARG  3

# define BIN_BASE "01"
# define DEC_BASE "0123456789"
# define HEX_BASE "0123456789abcdef"

# define MY_ABS(n) (0 > (n) ? -(n) : (n))

int		parse_expr(char **expr, int *result, char last);
int		parse_add(char **expr, int *result);
int		parse_mul(char **expr, int *result);
int		parse_value(char **expr, int *result);
int		parse_function(char **expr, int *result);
int		parse_number(char **expr, int *result);
int		handle_op(int *result, char operator, int operand1, int operand2);
int		my_putchar(int c);
void		my_putstr(const char *str);
void		my_putnbr_base(int nbr, const char *base);
unsigned int	my_factorial(unsigned int n);
unsigned int	my_fibonacci(unsigned int n);
int		my_power(int n, unsigned int p);
unsigned int	my_pgcd(unsigned int n, unsigned int p);
unsigned int	my_ppcm(unsigned int n, unsigned int p);
unsigned int	my_strlen(const char *str);
char		*my_strncpy(char *dest, const char *src, int n);
int		my_strncmp(const char *s1, const char *s2, int n);

#endif /*! J11_H_ */
