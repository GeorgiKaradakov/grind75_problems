#include "Graph.h"
using namespace std;

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    Node *copy = new Node(node->val);

    unordered_map<Node *, Node *> clone;
    queue<Node *> nodes;
    clone[node] = new Node(node->val);
    nodes.push(node);

    while (nodes.size()) {
      Node *curr = nodes.front();
      nodes.pop();

      for (Node *neigh : curr->neighbors) {
        if (!clone.count(neigh)) {
          clone[neigh] = new Node(neigh->val);
          nodes.push(neigh);
        }
        clone[curr]->neighbors.push_back(clone[neigh]);
      }
    }

    return clone[node];
  }
};
