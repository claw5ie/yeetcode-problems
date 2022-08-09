size_t
maxzu (size_t x, size_t y)
{
  return x > y ? x : y;
}

int
lengthOfLongestSubstring (char *s)
{
  size_t len = strlen (s);
  int *best = malloc ((len + 1) * sizeof (int));
  int highest = 0;

  best[len] = 0;

  for (size_t i = len; i-- > 0; )
    {
      size_t j = i + 1;

      for (size_t end = j + best[i + 1]; j < end; j++)
        {
          if (s[i] == s[j])
            break;
        }

      highest = maxzu (highest, best[i] = j - i);
    }

  free (best);

  return highest;
}
