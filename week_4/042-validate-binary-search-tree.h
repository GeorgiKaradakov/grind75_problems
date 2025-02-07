#include "Tree.h"

class Solution {
public:
  bool isValidBST(TreeNode *root) { return validate(root, LONG_MIN, LONG_MAX); }

private:
  bool validate(TreeNode *root, long min_val, long max_val) {
    if (!root)
      return 1;
    if (root->val <= min_val || root->val >= max_val)
      return 0;

    return validate(root->left, min_val, root->val) &&
           validate(root->right, root->val, max_val);
  }
};
