#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> mat) {
    queue<pair<int, pair<int, int>>> q;
    set<pair<int, int>> vis;

    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == 0) {
          q.push({0, {i, j}});
          vis.insert({i, j});
        }
      }
    }

    while (!q.empty()) {
      int dist = q.front().first;
      auto [i, j] = q.front().second;
      q.pop();

      for (auto [oi, oj] :
           vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
        int ci = oi + i, cj = oj + j;
        if (0 > ci || 0 > cj || ci >= mat.size() || cj >= mat[ci].size())
          continue;
        if (vis.count({ci, cj}))
          continue;

        mat[ci][cj] = dist + 1;
        q.push({dist + 1, {ci, cj}});
        vis.insert({ci, cj});
      }
    }

    return mat;
  }
};
