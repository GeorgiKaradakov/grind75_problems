#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<string, vector<string>> adj;
  vector<vector<string>> ans;
  unordered_set<string> vis;

private:
  void dfs(string e) {
    vis.insert(e);
    ans.back().push_back(e);

    for (string ne : adj[e]) {
      if (!vis.count(ne))
        dfs(ne);
    }
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
    for (auto acc : accounts) {
      for (int i = 2; i < acc.size(); i++) {
        adj[acc[i]].push_back(acc[i - 1]);
        adj[acc[i - 1]].push_back(acc[i]);
      }
    }

    for (auto acc : accounts) {
      if (!vis.count(acc[1])) {
        ans.push_back({acc[0]});
        dfs(acc[1]);
        sort(ans.back().begin() + 1, ans.back().end());
      }
    }

    return ans;
  }
};
