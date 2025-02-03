#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> nums) {
    int curr_sum = nums[0], sum = nums[0];

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
      while (i < j && curr_sum < 0) {
        curr_sum -= nums[i++];
      }
      curr_sum += nums[j];
      sum = max(curr_sum, sum);
    }

    return sum;
  }
};
