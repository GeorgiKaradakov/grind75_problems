#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> nums) {
    unordered_map<int, int> cnt;

    int res = 0;
    for (int n : nums) {
      cnt[n]++;
      if (cnt[n] > nums.size() / 2) {
        res = n;
        break;
      }
    }

    return res;
  }
};
