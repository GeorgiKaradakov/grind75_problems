#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> nums) { // faster with binary search
    if (nums.size() < 3)
      return {};

    vector<vector<int>> res;
    unordered_map<int, int> m;
    sort(nums.begin(), nums.end());

    if (nums[0] > 0)
      return {};

    for (int i = 0; i < nums.size(); i++)
      m[nums[i]] = i;

    for (int i = 0; i < nums.size() - 2; i++) {
      for (int j = i + 1; j < nums.size() - 1; j++) {
        if (m.count((nums[i] + nums[j]) * -1)) {
          int ind = m[(nums[i] + nums[j]) * -1];
          if (ind > j) {
            res.push_back({nums[i], nums[j], nums[ind]});
            j = m[nums[j]];
          }
        }
      }
      i = m[nums[i]];
    }

    return res;
  }
};
