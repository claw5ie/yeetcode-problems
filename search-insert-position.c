int
searchInsert (int *nums, int count, int target)
{
  int start = 0, end = count;

  while (start < end)
    {
      int mid = start + (end - start) / 2;

      if (target < nums[mid])
        end = mid;
      else if (target > nums[mid])
        start = mid + 1;
      else
        return mid;
    }

  return start;
}
