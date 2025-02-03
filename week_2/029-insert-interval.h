#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> intervals,
                             vector<int> newInterval) {
    if (intervals.empty())
      return {newInterval};

    int i = 0, j = intervals.size() - 1;

    while (i <= j) {
      int mid = i + (j - i) / 2;

      if (newInterval[0] < intervals[mid][0])
        j = mid - 1;
      else
        i = mid + 1;
    }
    intervals.insert(intervals.begin() + i, newInterval);

    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      vector<int> &curr = res.back();

      if (curr[1] >= intervals[i][1])
        continue;

      if (curr[1] >= intervals[i][0]) {
        curr[1] = intervals[i][1];
      } else {
        res.push_back(intervals[i]);
      }
    }

    return res;
  }
};
