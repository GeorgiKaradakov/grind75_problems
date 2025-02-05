#include <vector>
using namespace std;

class Solution {
public:
  // vector<int> productExceptSelf(vector<int> nums) {   //gen 1
  //   int n = nums.size();
  //   int prefix[n], suffix[n];
  //   prefix[0] = suffix[n - 1] = 1;
  //   for (int i = 1; i < n; i++) {
  //     prefix[i] = prefix[i - 1] * nums[i - 1];
  //     suffix[n - 1 - i] = suffix[n - i] * nums[n - i];
  //   }
  //
  //   vector<int> res;
  //   for (int i = 0; i < n; i++) {
  //     res.push_back(suffix[i] * prefix[i]);
  //   }
  //
  //   return res;
  // }

  vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++) {
      ans[i] *= prefix;
      prefix *= nums[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      ans[i] *= suffix;
      suffix *= nums[i];
    }

    return ans;
  }
};
