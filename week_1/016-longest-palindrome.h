#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> cnt;

    for (auto ch : s)
      cnt[ch]++;

    int res = 0, has_odd = 0;

    for (auto [ch, cn] : cnt) {
      if (cn % 2 == 0)
        res += cn;
      else {
        res += cn - 1;
        has_odd = 1;
      }
    }

    return has_odd ? res + 1 : res;
  }
};
