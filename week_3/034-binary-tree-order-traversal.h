#include "Tree.h"
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<pair<TreeNode *, int>> nodes;
    nodes.push({root, 0});

    while (nodes.size()) {
      auto [node, level] = nodes.front();
      nodes.pop();

      if (!node)
        continue;

      if (res.size() == level) {
        res.push_back({});
      }

      res[level].push_back(node->val);

      nodes.push({node->left, level + 1});
      nodes.push({node->right, level + 1});
    }

    return res;
  }
};
