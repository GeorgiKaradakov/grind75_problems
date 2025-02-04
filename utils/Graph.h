#include <cstdio>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

inline Node *from_adj(vector<pair<int, int>> edges, int start_node) {
  if (edges.empty())
    return nullptr;

  Node *node = new Node(start_node);
  Node *b = node;
  unordered_map<int, vector<int>> adj;

  for (pair<int, int> edge : edges) {
    adj[edge.first].push_back(edge.second);
    adj[edge.second].push_back(edge.first);
  }

  unordered_set<int> vis;
  queue<Node *> nodes;
  nodes.push(b);

  while (nodes.size()) {
    Node *node = nodes.front();
    nodes.pop();

    if (vis.count(node->val))
      continue;
    vis.insert(node->val);

    for (int edge : adj[node->val]) {
      node->neighbors.push_back(new Node(edge));
      nodes.push(node->neighbors.back());
    }
  }

  return node;
}

inline vector<vector<int>> to_edge_list(Node *node) {
  if (!node)
    return {{}};

  vector<vector<int>> res;
  unordered_set<int> vis;
  queue<Node *> nodes;
  nodes.push(node);

  while (nodes.size()) {
    Node *curr = nodes.front();
    nodes.pop();

    vis.insert(curr->val);

    for (Node *neigh : curr->neighbors) {
      if (vis.count(neigh->val))
        continue;
      res.push_back({curr->val, neigh->val});
      nodes.push(neigh);
    }
  }

  return res;
}
