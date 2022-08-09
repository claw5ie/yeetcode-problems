bool
searchMatrix (int **mat, int rows, int *wtf, int target)
{
  int start = 0, end = rows, mid = end - start;

  while (1 < mid)
    {
      mid = start + mid / 2;
      int val = mat[mid][0];

      if (val < target)
        start = mid;
      else if (val > target)
        end = mid;
      else
        {
          start = mid;
          break;
        }

      mid = end - start;
    }

  int *row = mat[start];

  start = 0, end = *wtf;

  while (start < end)
    {
      mid = start + (end - start) / 2;
      int val = row[mid];

      if (val < target)
        start = mid + 1;
      else if (val > target)
        end = mid;
      else
        return true;
    }

  return false;
}
