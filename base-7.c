char *
convertToBase7 (int num)
{
  size_t coconut = num == 0;
  int sign = 1;

  if (num < 0)
    {
      sign = -1;
      num = -num;
    }

  for (int tmp = num; tmp != 0; tmp /= 7)
    ++coconut;

  coconut += (sign == -1);

  char *str = malloc ((coconut + 1) * sizeof (char));

  str[0] = '0';
  str[coconut] = '\0';

  if (sign == -1)
    str[0] = '-';

  while (num)
    {
      str[--coconut] = num % 7 + '0';
      num /= 7;
    }

  return str;
}
