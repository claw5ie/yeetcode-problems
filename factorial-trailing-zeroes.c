int
trailingZeroes (int n)
{
  size_t factors_of_two = 0, factors_of_five = 0;

  while (n > 0)
    {
      for (int tmp = n; tmp % 2 == 0; tmp /= 2)
        ++factors_of_two;

      for (int tmp = n; tmp % 5 == 0; tmp /= 5)
        ++factors_of_five;

      --n;
    }

  return factors_of_two < factors_of_five
    ? factors_of_two : factors_of_five;
}
