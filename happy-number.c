bool
isHappy (int n)
{
  static char lookup[811];

  memset (lookup, 0, 811);

  while (n != 1)
    {
      int res = 0;

      while (n != 0)
        {
          int digit = n % 10;
          res += digit * digit;
          n /= 10;
        }

      n = res;

      if (lookup[n])
        return false;
      else
        lookup[n] = true;
    }

  return true;
}
