#pragma once

#include "../utils/Tree.h"
#include <cstdio>

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return findLCA(root, p, q);
  }

private:
  TreeNode *findLCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return nullptr;

    if (root->val == p->val || root->val == q->val)
      return root;

    TreeNode *left = findLCA(root->left, p, q);
    TreeNode *right = findLCA(root->right, p, q);

    if (left && right)
      return root;

    if (left)
      return left;
    if (right)
      return right;

    return nullptr;
  }
};
