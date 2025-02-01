#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> nums) {
    unordered_set<int> dup;

    for (int i : nums) {
      if (dup.count(i))
        return 1;
      dup.insert(i);
    }

    return 0;
  }
};
