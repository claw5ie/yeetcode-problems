int
maxSubArray (int *nums, int count)
{
  int highest = INT_MIN, prev_best;

  if (count > 0)
    highest = prev_best = nums[0];

  for (size_t i = 1; i < count; i++)
    {
      int curr = nums[i], sum = curr + prev_best;

      prev_best = sum > curr ? sum : curr;

      if (highest < prev_best)
        highest = prev_best;
    }

  return highest;
}
