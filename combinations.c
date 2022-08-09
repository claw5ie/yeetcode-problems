size_t
choose (size_t n, size_t k)
{
  size_t r = 1;

  for (size_t i = 1; i <= k; i++)
    {
      r *= n--;
      r /= i;
    }

  return r;
}

int **
combine (int n, int k, int *rows_loc, int **cols_loc)
{
  *rows_loc = choose (n, k);
  *cols_loc = malloc (*rows_loc * sizeof (int));
  **cols_loc = k;

  for (int i = *rows_loc; i-- > 0; )
    cols_loc[0][i] = k;

  int **r = malloc (*rows_loc * sizeof (int *));
  size_t coconut = 0;

  if (k == 0)
    return r;

  int *digs = malloc (k * sizeof (int));

  --n;
  --k;

  for (int i = k + 1; i-- > 0; )
    digs[i] = k - i;

  while (digs[k] + k <= n)
    {
      {
        int *arr = r[coconut++] = malloc ((k + 1) * sizeof (int));

        // 1 based indexing...
        for (int i = k + 1; i-- > 0; )
          arr[k - i] = digs[i] + 1;
      }

      if (++digs[0] > n)
        {
          int i = 0;

          while (i < k && digs[i] + i >= n)
            ++i;

          ++digs[i];

          while (i-- > 0)
            digs[i] = digs[i + 1] + 1;
        }
    }

  free (digs);

  return r;
}
