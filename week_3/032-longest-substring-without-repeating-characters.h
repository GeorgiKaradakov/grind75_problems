#include <climits>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() <= 1)
      return s.size();

    int max_size = INT_MIN;
    unordered_set<char> curr_wind;
    curr_wind.insert(s[0]);
    for (int i = 0, j = 1; j < s.size(); j++) {
      if (i == j)
        continue;

      while (i < j && curr_wind.count(s[j])) {
        curr_wind.erase(s[i++]);
      }

      curr_wind.insert(s[j]);
      max_size = max(j - i + 1, max_size);
    }

    return max_size;
  }
};
