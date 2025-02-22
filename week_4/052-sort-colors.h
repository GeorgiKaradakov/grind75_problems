#include <vector>
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      bool swapped = 0;
      for (int j = 0; j < nums.size() - i - 1; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          swapped = 1;
        }
      }
      if (!swapped)
        break;
    }
  }
};
