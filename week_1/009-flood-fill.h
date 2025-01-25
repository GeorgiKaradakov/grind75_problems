#pragma once

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc,
                                int color) {
    int prev_col = image[sr][sc];
    if (prev_col == color)
      return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});

    auto check_bounds = [&](int r, int c) -> bool {
      return (0 <= r && r < image.size()) && (0 <= c && c < image[0].size());
    };

    while (!q.empty()) {
      int r = q.front().first, c = q.front().second;
      q.pop();

      image[r][c] = color;

      for (auto [nr, nc] :
           vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
        int tr = nr + r, tc = nc + c;

        if (check_bounds(tr, tc) && image[tr][tc] == prev_col) {
          // printf("%d - %d\n", tr, tc);
          q.push({tr, tc});
        }
      }
    }
    return image;
  }
};
