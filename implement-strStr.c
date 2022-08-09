int
strStr (char *haystack, char *needle)
{
  if (*needle == '\0')
    return 0;

  for (size_t i = 0; haystack[i] != '\0'; i++)
    {
      size_t j = 0;
      char h, n;

      do
        {
          h = haystack[i + j];
          n = needle[j++];
        }
      while (h != '\0' && n == h);

      if (n == '\0')
        return i;
    }

  return -1;
}
