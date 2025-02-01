#include "../utils/Tree.h"

class Solution {
public:
  int maxDepth(TreeNode *root) { return find_depth(root); }

private:
  int find_depth(TreeNode *root) {
    if (!root)
      return 0;

    return std::max(find_depth(root->left), find_depth(root->right)) + 1;
  }
};
