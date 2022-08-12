int
mini (int x, int y)
{
  return x < y ? x : y;
}

int
minDepth (struct TreeNode *root)
{
  if (root == NULL)
    return 0;
  else if (root->left == NULL)
    return 1 + minDepth (root->right);
  else if (root->right == NULL)
    return 1 + minDepth (root->left);
  else
    return 1 + mini (minDepth (root->left), minDepth (root->right));
}
