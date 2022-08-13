int
countPrimes (int n)
{
  char *is_prime = calloc (n / 8 + 1, 1);
  int coconut = 0;

  for (int i = 2; i < n; i++)
    {
      if (~is_prime[i / 8] & (1 << (i % 8)))
        {
          ++coconut;

          for (int j = i + i; j < n; j += i)
            is_prime[j / 8] |= (1 << (j % 8));
        }
    }

  free (is_prime);

  return coconut;
}
