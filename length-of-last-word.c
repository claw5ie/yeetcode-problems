int
lengthOfLastWord (char *str)
{
  if (*str == '\0')
    return 0;

  char *lst = str;

  while (*++str != '\0')
    {
      if (!isspace (str[0]) && isspace (str[-1]))
        lst = str;
    }

  while (isspace (*--str))
    ;

  return str - lst + 1;
}
