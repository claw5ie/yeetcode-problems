#define LOWEST_PREC (-127)
#define HIGHEST_PREC (127)

typedef struct Token Token;

struct Token
{
  char type;
  const char *text;
  size_t size;
};

Token
next_token (const char **str)
{
  const char *s = *str;

  while (isspace (*s))
    ++s;

  Token tok = { *s, s, 1 };

  if (isdigit (*s))
    {
      tok.type = '0';
      tok.text = s;

      do
        *s++;
      while  (isdigit (*s));

      tok.size = s - tok.text;
    }
  else
    s += (*s != '\0');

  *str = s;

  return tok;
}

int
prec_of (char op)
{
  switch (op)
    {
    case '+':
    case '-':
      return 0;
    case '*':
    case '/':
      return 1;
    default:
      return LOWEST_PREC - 1;
    }
}

const char *s;

int
parse_expr (int lower_prec)
{
  int left = 0;
  Token tok = next_token (&s);

  switch (tok.type)
    {
    case '(':
      left = parse_expr (LOWEST_PREC);
      tok = next_token (&s);
      // Assume that the next token is closing parentheses.
      break;
    case '-':
      left = -parse_expr (HIGHEST_PREC);
      break;
    case '0':
      for (size_t i = 0; i < tok.size; i++)
        left = 10 * left + (tok.text[i] - '0');
      break;
    }

  tok = next_token (&s);

  int prev_prec = INT_MAX, curr_prec = prec_of (tok.type);

  while (curr_prec >= lower_prec && curr_prec < prev_prec)
    {
      do
        {
          int right = parse_expr (curr_prec + 1);

          switch (tok.type)
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

          tok = next_token (&s);
        }
      while (curr_prec == prec_of (tok.type));

      prev_prec = curr_prec;
      curr_prec = prec_of (tok.type);
    }

  s = tok.text;

  return left;
}

int
calculate (char *str)
{
  s = str;

  return parse_expr (LOWEST_PREC);
}
