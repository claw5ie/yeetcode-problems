int
removeDuplicates (int *arr, int count)
{
  int *lst = arr + count;
  size_t i = 1;

  for (; i < count; i++)
    {
      if (arr[i] == arr[i - 1])
        {
          lst = &arr[i];
          break;
        }
    }

  for (; i < count; i++)
    {
      if (arr[i] != arr[i - 1])
        *lst++ = arr[i];
    }

  return lst - arr;
}
