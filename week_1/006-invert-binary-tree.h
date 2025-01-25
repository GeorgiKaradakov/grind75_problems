#pragma once

#include "../utils/Tree.h"
#include <cstdio>

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    invert(root);
    return root;
  }

private:
  void invert(TreeNode *root) {
    if (!root)
      return;

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invert(root->left);
    invert(root->right);
  }
};
