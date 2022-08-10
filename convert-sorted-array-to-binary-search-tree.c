typedef struct TreeNode TreeNode;

TreeNode *
sortedArrayToBST (int *nums, int len)
{
  if (len <= 0)
    return NULL;

  int middle = len / 2;

  TreeNode *root = malloc (sizeof (TreeNode));
  root->val = nums[middle];
  root->left = sortedArrayToBST (nums, middle);
  root->right = sortedArrayToBST (nums + middle + 1,
                                  len - middle - 1);

  return root;
}
