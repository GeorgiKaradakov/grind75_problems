#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const auto &left, const auto &right) { return left[0] < right[0]; });

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      vector<int> &prev = ans.back();

      if (prev[1] >= intervals[i][1]) {
        continue;
      } else if (prev[1] >= intervals[i][0]) {
        prev[1] = intervals[i][1];
      } else {
        ans.push_back(intervals[i]);
      }
    }

    return ans;
  }
};
