int
mySqrt (int x)
{
  int start = x == 1, end = x > 46341 ? 46341 : x, mid = end - start;

  while (1 < mid)
    {
      mid = start + mid / 2;
      int y = mid * mid;

      if (y > x)
        end = mid;
      else if (y < x)
        start = mid;
      else
        return mid;

      mid = end - start;
    }

  return start;
}
