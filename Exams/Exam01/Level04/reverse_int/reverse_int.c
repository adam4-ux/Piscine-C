int reverse_int(int n)
{
  int nb = 0;

  int i = 0;
  while (n > 0)
  {
    nb = nb * 10 + (n % 10);
    n /= 10;
  }
  return nb;
}