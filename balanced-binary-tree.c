long
maxl (long x, long y)
{
  return x > y ? x : y;
}

long
absl (long x)
{
  return x < 0 ? -x : x;
}

long
max_depth (struct TreeNode *root)
{
  if (root == NULL)
    return 0;

  long left = max_depth (root->left), right = max_depth (root->right);

  if (left == -1 || right == -1 || absl (left - right) > 1)
    return -1;
  else
    return 1 + maxl (left, right);
}

bool
isBalanced (struct TreeNode *root)
{
  return max_depth (root) != -1;
}
