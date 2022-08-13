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
          int op = *s++, right = parse_expr (false);

          switch (op)
            {
            case '+':
              left += right;
              break;
            case '-':
              left -= right;
              break;
            }
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
