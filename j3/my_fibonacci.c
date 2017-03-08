/*
 * This is a common iterative form of Fibonacci. It uses the fact that
 * the state of a Fibonacci iteration only contains the two previous values,
 * and a common no-extra-variable swap algorithm.
 */
unsigned	fibonacci(unsigned n)
{
  unsigned int	lo;
  unsigned int	hi;
  unsigned int	i;

  lo = 1;
  hi = 1;
  for (i = 1; i < n; ++i)
  {
    hi += lo;
    lo = hi - lo;
  }
  return hi;
}
