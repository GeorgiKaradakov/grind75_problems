#include "../utils/Tree.h"

class Solution {
private:
  int diameter = 0;

public:
  int diameterOfBinaryTree(TreeNode *root) {
    find_depth(root);
    return diameter;
  }

private:
  int find_depth(TreeNode *root) {
    if (!root)
      return 0;

    int left_depth = find_depth(root->left);
    int right_depth = find_depth(root->right);

    diameter = std::max(diameter, right_depth + left_depth);

    return std::max(left_depth, right_depth) + 1;
  }
};
