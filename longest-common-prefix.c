char *
longestCommonPrefix (char **strs, int len)
{
  size_t min = SIZE_MAX;

  for (size_t i = 1; i < len; i++)
    {
      char *s1 = strs[i], *s2 = strs[i - 1], c1, c2;
      size_t count = 0;

      do
        {
          c1 = *s1++;
          c2 = *s2++;

          if (c1 != c2)
            break;

          ++count;
        }
      while (c1 != '\0');

      if (min > count)
        min = count;
    }

  if (len == 1)
    min = strlen (strs[0]);

  char *r = malloc (min + 1);
  memcpy (r, strs[0], min);
  r[min] = '\0';

  return r;
}
