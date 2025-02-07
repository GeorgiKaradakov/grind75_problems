#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> grid) {
    bool flag = 0;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1)
          flag = 1;
        if (grid[i][j] == 2)
          q.push({{i, j}, 0});
      }
    }

    if (!flag)
      return 0;

    if (q.empty())
      return -1;

    int ans = 0;
    while (q.size()) {
      auto [ci, cj] = q.front().first;
      int mi = q.front().second;
      q.pop();

      ans = max(ans, mi);

      for (auto [di, dj] :
           vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
        int i = di + ci, j = dj + cj;
        if (0 > i || 0 > j || i >= grid.size() || j >= grid[i].size())
          continue;
        if (grid[i][j] != 1)
          continue;

        grid[i][j] = 2;
        q.push({{i, j}, mi + 1});
      }
    }

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1)
          return -1;
      }
    }

    return ans;
  }
};
