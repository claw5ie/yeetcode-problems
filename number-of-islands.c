void
floodfill (bool *visited, int row, int col,
           char **grid, int rows, int cols)
{
  if (!(0 <= row && row < rows && 0 <= col && col < cols)
      || visited[row * cols + col]
      || grid[row][col] != '1')
    return;

  visited[row * cols + col] = true;

  floodfill (visited, row, col + 1, grid, rows, cols);
  floodfill (visited, row, col - 1, grid, rows, cols);
  floodfill (visited, row + 1, col, grid, rows, cols);
  floodfill (visited, row - 1, col, grid, rows, cols);
}

int
numIslands (char **grid, int rows, int *cols_arr)
{
  int cols = *cols_arr;
  bool *visited = calloc (rows * cols, sizeof (bool));

  int coconut = 0;

  for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < cols; j++)
        {
          if (grid[i][j] == '1' && !visited[i * cols + j])
            {
              floodfill (visited, i, j, grid, rows, cols);
              ++coconut;
            }
        }
    }

  free (visited);

  return coconut;
}
