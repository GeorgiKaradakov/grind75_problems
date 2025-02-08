#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> ans;

public:
  vector<vector<int>> combinationSum(vector<int> candidates, int target) {
    helper(candidates, target, {}, 0, 0);
    return ans;
  }

private:
  void helper(const vector<int> &candidates, int target, vector<int> res,
              int curr_sum, int start) {
    if (curr_sum == target) {
      ans.push_back(res);
      return;
    }

    if (curr_sum > target)
      return;

    for (int i = start; i < candidates.size(); i++) {
      res.push_back(candidates[i]);
      helper(candidates, target, res, curr_sum + candidates[i], i);
      res.pop_back();
    }
  }
};
