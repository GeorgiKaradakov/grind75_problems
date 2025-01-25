#pragma once

#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;

    while (l <= r) {
      if (!isalnum(s[l])) {
        l++;
        continue;
      }
      if (!isalnum(s[r])) {
        r--;
        continue;
      }

      if (tolower(s[l]) != tolower(s[r]))
        return 0;

      l++, r--;
    }

    return 1;
  }
};
