#include <cstdio>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> nums, int target) {
    map<int, int> needed;

    for (int i = 0; i < nums.size(); i++) {
      if (needed.count(target - nums[i])) {
        return {needed[target - nums[i]], i};
      }

      needed[nums[i]] = i;
    }

    for (auto [x, y] : needed)
      printf("%d, %d\n", x, y);

    return {};
  }
};
