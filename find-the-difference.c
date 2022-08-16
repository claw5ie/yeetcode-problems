char
findTheDifference (char *str, char *shuffled)
{
#define LOOKUP_SIZE ('z' - 'a' + 1)

  static unsigned lookup[LOOKUP_SIZE];

  memset (lookup, 0, LOOKUP_SIZE * sizeof (unsigned));

  char ch;
  while ((ch = *str++) != '\0')
    ++lookup[ch - 'a'];

  while ((ch = *shuffled++) != '\0')
    if (lookup[ch - 'a']-- == 0)
      return ch;

  return -1;
}
