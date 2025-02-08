#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> ans;
    generate(ans, nums, 0);
    return ans;
  }

private:
  void generate(vector<vector<int>> &ans, vector<int> n, int start) {
    if (start == n.size()) {
      ans.push_back(n);
      return;
    }

    for (int i = start; i < n.size(); i++) {
      swap(n[start], n[i]);
      generate(ans, n, start + 1);
      swap(n[start], n[i]);
    }
  }
};
