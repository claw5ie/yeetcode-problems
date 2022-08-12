int
maxi (int x, int y)
{
  return x > y ? x : y;
}

int
maxDepth (struct TreeNode *root)
{
  return root != NULL
    ? 1 + maxi (maxDepth (root->left), maxDepth (root->right)) : 0;
}
