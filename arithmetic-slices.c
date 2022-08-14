int
numberOfArithmeticSlices (int *nums, int count)
{
  if (count < 3)
    return 0;

  void *buffer = calloc (2 * count, sizeof (bool));
  bool *front = buffer, *back = front + count;
  int *diff = calloc (count, sizeof (int));

  int coconut = 0;

  for (size_t i = 0; i + 2 < count; i++)
    {
      int difference = nums[i + 1] - nums[i];

      front[i] = (nums[i + 2] - nums[i + 1] == difference);
      coconut += front[i];
      diff[i] = difference;
    }

  for (size_t i = 4; i <= count; i++)
    {
      {
        bool *tmp = front;
        front = back;
        back = tmp;
      }

      for (size_t j = 0; j + i <= count; j++)
        {
          size_t next = j + 1;
          front[j] = back[next]
            && (nums[next] - nums[j] == diff[next]);
          coconut += front[j];
        }
    }

  free (diff);
  free (buffer);

  return coconut;
}
