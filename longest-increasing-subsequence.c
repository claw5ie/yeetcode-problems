size_t
maxzu (size_t x, size_t y)
{
  return x < y ? y : x;
}

int
lengthOfLIS (int *nums, int count)
{
  int *best = malloc (count * sizeof (int)), highest = 0;

  for (size_t i = count; i-- > 0; )
    {
      int max = 0;

      for (size_t j = i + 1; j < count; j++)
        {
          if (nums[i] < nums[j])
            max = maxzu (max, best[j]);
        }

      ++max;

      highest = maxzu (highest, max);
      best[i] = max;
    }

  free (best);

  return highest;
}
