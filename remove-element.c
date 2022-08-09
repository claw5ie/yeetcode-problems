int
removeElement (int *arr, int count, int val)
{
  for (size_t i = 0; i < count; i++)
    {
      if (arr[i] == val)
        {
          arr[i] = arr[--count];
          --i;
        }
    }

  return count;
}
