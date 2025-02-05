#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
    unordered_map<int, vector<int>> adj;
    vector<int> in_degree(numCourses, 0);

    for (const auto &edge : prerequisites) {
      adj[edge[1]].push_back(edge[0]);
      in_degree[edge[0]]++;
    }

    queue<int> q;
    int node_cnt = 0;

    for (int i = 0; i < numCourses; i++)
      if (in_degree[i] == 0)
        q.push(i);

    while (q.size()) {
      int curr = q.front();
      q.pop();
      node_cnt++;

      for (int neigh : adj[curr]) {
        in_degree[neigh]--;
        if (!in_degree[neigh]) {
          q.push(neigh);
        }
      }
    }

    return node_cnt == numCourses;
  }
};
