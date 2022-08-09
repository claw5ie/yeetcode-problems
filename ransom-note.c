bool
canConstruct (char *ransom, char *magazine)
{
  static unsigned lookup[128];

  memset (lookup, 0, 128 * sizeof (unsigned));

  while (*magazine != '\0')
    ++lookup[*magazine++];

  while (*ransom != '\0')
    {
      if (lookup[*ransom] == 0)
        return false;
      else
        --lookup[*ransom];

      ++ransom;
    }

  return true;
}
