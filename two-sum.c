int *
twoSum (int *nums, int count, int target, int *size_loc)
{
  *size_loc = 2;

  for (size_t i = 0; i < count; i++)
    {
      for (size_t j = i + 1; j < count; j++)
        {
          if (nums[i] + nums[j] == target)
            {
              int *res = malloc (2 * sizeof (int));

              res[0] = i;
              res[1] = j;

              return res;
            }
        }
    }

  return NULL;
}
