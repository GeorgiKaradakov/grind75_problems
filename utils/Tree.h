#include <climits>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

inline TreeNode *from_vec(std::vector<int> vec) {
  if (vec.empty() || vec[0] == INT_MAX)
    return nullptr;

  TreeNode *root = new TreeNode(vec[0]);

  std::queue<TreeNode *> nodes;
  nodes.push(root);

  int i = 1;

  while (!nodes.empty() && i < vec.size()) {
    TreeNode *curr = nodes.front();
    nodes.pop();

    if (vec[i] != INT_MAX) {
      curr->left = new TreeNode(vec[i]);
      nodes.push(curr->left);
    }
    i++;

    if (i < vec.size() && vec[i] != INT_MAX) {
      curr->right = new TreeNode(vec[i]);
      nodes.push(curr->right);
    }
    i++;
  }

  return root;
}

inline std::vector<int> to_vec(TreeNode *root) {
  if (!root)
    return {};

  std::vector<int> res;
  std::queue<TreeNode *> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    TreeNode *curr = nodes.front();
    nodes.pop();

    if (curr) {
      res.push_back(curr->val);

      nodes.push(curr->left);
      nodes.push(curr->right);
    } else {
      res.push_back(INT_MAX);
    }
  }

  while (res.back() == INT_MAX)
    res.pop_back();

  return res;
}
