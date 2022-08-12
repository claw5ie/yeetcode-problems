bool
isAnagram (char *s, char *t)
{
  static unsigned coconuts[128];

  memset (coconuts, 0, 128 * sizeof (unsigned));

  char ch;
  while ((ch = *s++) != '\0')
    ++coconuts[ch];

  while ((ch = *t++) != '\0')
    if (coconuts[ch]-- == 0)
      return false;

  for (size_t i = 0; i < 128; i++)
    if (coconuts[i] > 0)
      return false;

  return true;
}
