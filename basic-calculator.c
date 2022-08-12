int
apply (char ch, int left, int right)
{
  switch (ch)
    {
    case '+':
      return left + right;
    case '-':
      return left - right;
    }

  return -1;
}

const char *s;

int
parse_expr (bool parse_same_prec)
{
  while (isspace (*s))
    ++s;

  int left = 0;

  switch (*s)
    {
    case '(':
      ++s;
      left = parse_expr (true);
      // Skip closing parenthesis. Should skip spaces here as well.
      ++s;
      break;
    case '-':
      ++s;
      left = -parse_expr (false);
      break;
    default:
      while (isdigit (*s))
        left = 10 * left + (*s++ - '0');
    }

  while (isspace (*s))
    ++s;

  if (parse_same_prec)
    {
      while (*s == '+' || *s == '-')
        {
          char op = *s++;
          left = apply (op, left, parse_expr (false));
        }
    }

  return left;
}

int
calculate (char *str)
{
  s = str;

  return parse_expr (true);
}
