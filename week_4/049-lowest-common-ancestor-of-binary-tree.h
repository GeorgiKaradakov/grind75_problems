#include "Tree.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return find_lowest(root, p, q);
  }

private:
  TreeNode *find_lowest(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root->val == p->val || root->val == q->val)
      return root;

    TreeNode *left = find_lowest(root->left, p, q);
    TreeNode *right = find_lowest(root->right, p, q);

    if (left && right)
      return root;

    return left ? left : right;
  }
};
