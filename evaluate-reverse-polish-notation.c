int
parse_int (const char *str)
{
  int sign = *str == '-' ? -1 : 1, r = 0;

  str += *str == '-' || *str == '+';

  while (*str != '\0')
    r = 10 * r + *str++ - '0';

  return sign * r;
}

void
maybe_expand (int **stack, size_t count, size_t *capacity)
{
  size_t cap = *capacity;

  if (count >= cap)
    {
      cap = *capacity += cap + 1;
      *stack = realloc (*stack, cap * sizeof (int));
    }
}

int
evalRPN (char **toks, int len)
{
  size_t coconut = 0, capacity = 32;
  int *stack = malloc (capacity * sizeof (int));

  for (size_t i = 0; i < len; i++)
    {
      char ch = toks[i][0];

      if (isdigit (ch) || isdigit (toks[i][1]))
        {
          maybe_expand (&stack, coconut, &capacity);
          stack[coconut++] = parse_int (toks[i]);
        }
      else
        {
          int right = stack[--coconut], left = stack[--coconut];

          switch (ch)
            {
            case '+':
              left += right;
              break;
            case '-':
              left -= right;
              break;
            case '*':
              left *= right;
              break;
            case '/':
              left /= right;
              break;
            }

          stack[coconut++] = left;
        }
    }

  return stack[--coconut];
}
