char *
int_to_str (int num)
{
  size_t count = num == 0;

  for (int tmp = num; tmp != 0; ++count)
    tmp /= 10;

  char *str = malloc (count + 1);

  str[count] = '\0';

  while (count-- > 0)
    {
      str[count] = '0' + num % 10;
      num /= 10;
    }

  return str;
}

char **
fizzBuzz (int count, int *size_loc)
{
  *size_loc = count;
  char **data = malloc (count * sizeof (char *));

  while (count-- > 0)
    {
      if (count % 3 == 2)
        {
          if (count % 5 == 4)
            {
              data[count] = malloc (9);
              memcpy (data[count], "FizzBuzz", 9);
            }
          else
            {
              data[count] = malloc (5);
              memcpy (data[count], "Fizz", 5);
            }
        }
      else if (count % 5 == 4)
        {
          data[count] = malloc (5);
          memcpy (data[count], "Buzz", 5);
        }
      else
        data[count] = int_to_str (count + 1);
    }

  return data;
}
