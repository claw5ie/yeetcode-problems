typedef struct TreeNode TreeNode;

traverse (TreeNode *left, TreeNode *right)
{
  if (left == NULL && right != NULL
      || left != NULL && right == NULL)
    return false;
  else if (left == NULL && right == NULL)
    return true;
  else if (left->val == right->val)
    return traverse (left->left, right->right)
      && traverse (left->right, right->left);
  else
    return false;
}

bool
isSymmetric (TreeNode *root)
{
  if (root == NULL)
    return true;
  else
    return traverse (root->left, root->right);
}
