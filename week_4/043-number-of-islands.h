#include <vector>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> grid) {
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          cnt++;
        }
      }
    }

    return cnt;
  }

private:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (0 > i || 0 > j || i >= grid.size() || j >= grid[i].size())
      return;
    if (grid[i][j] != '1')
      return;

    grid[i][j] = '0';
    for (auto [di, dj] :
         vector<pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
      int ni = i + di, nj = dj + j;
      dfs(grid, ni, nj);
    }
  }
};
