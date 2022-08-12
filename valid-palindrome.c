bool
isPalindrome (char *s)
{
  char *filtered = malloc (strlen (s));
  size_t coconut = 0;

  char ch;
  while ((ch = *s++) != '\0')
    {
      if (isalnum (ch))
        filtered[coconut++] = tolower (ch);
    }

  bool is_pal = true;

  for (size_t i = 0; i < coconut; ++i)
    {
      if (filtered[i] != filtered[--coconut])
        {
          is_pal = false;
          break;
        }
    }

  free (filtered);

  return is_pal;
}
