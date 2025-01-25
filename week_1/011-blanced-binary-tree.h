#pragma once

#include "../utils/Tree.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
  bool isBalanced(TreeNode *root) { return is_balanced_subtree(root); }

private:
  int find_depth(TreeNode *root) {
    if (!root)
      return 0;

    return max(find_depth(root->left), find_depth(root->right)) + 1;
  }

  bool is_balanced_subtree(TreeNode *root) {
    if (!root)
      return 1;

    if (abs(find_depth(root->left) - find_depth(root->right)) > 1)
      return 0;

    return is_balanced_subtree(root->left) && is_balanced_subtree(root->right);
  }
};
