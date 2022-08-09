int
reverse (int x)
{
  int rev = 0;

  while (x != 0)
    {
      int mod = x % 10;

      if ((rev > 214748364
           || rev == 214748364 && mod > 7)
          || (rev < -214748364 || rev == -214748364 && mod < -8))
        return 0;

      rev = 10 * rev + mod;
      x /= 10;
    }

  return rev;
}
