char *
longestPalindrome (char *s)
{
  size_t len = strlen (s);
  char *is_pal = calloc (len * len, 1);

  for (size_t i = 0; i < len; i++)
    is_pal[i] = true;

  size_t pallen = 1;
  char *palstr = s;

  for (size_t i = 0; i + 1 < len; i++)
    {
      is_pal[len + i] = s[i] == s[i + 1];

      if (pallen < 2 && is_pal[len + i])
        {
          pallen = 2;
          palstr = s + i;
        }
    }

  for (size_t i = 2; i < len; i++)
    {
      for (size_t j = 0; j + i < len; j++)
        {
          if (s[j] == s[j + i]
              && is_pal[(i - 2) * len + j + 1])
            is_pal[i * len + j] = true;

          if (pallen < i + 1 && is_pal[i * len + j])
            {
              pallen = i + 1;
              palstr = s + j;
            }
        }
    }

  // Reuse "is_pal" for return string.
  is_pal = realloc (is_pal, pallen + 1);
  memcpy (is_pal, palstr, pallen);
  is_pal[pallen] = '\0';

  return is_pal;
}
