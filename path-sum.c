bool
check_target (struct TreeNode *root, int target)
{
  return root->left != NULL || root->right != NULL ? false : target == 0;
}

bool
hasPathSum (struct TreeNode *root, int target)
{
  if (root == NULL)
    return false;

  int new_target = target - root->val;

  return check_target (root, new_target)
    || hasPathSum (root->left, new_target)
    || hasPathSum (root->right, new_target);
}
