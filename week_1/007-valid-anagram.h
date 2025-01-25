#pragma once

#include <string>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return 0;

    int a['z' + 1]{0};

    for (int i = 0; i < s.size(); i++) {
      a[s[i]]++;
      a[t[i]]--;
    }

    for (int i = 'a'; i <= 'z'; i++) {
      if (a[i] != 0)
        return 0;
    }

    return 1;
  }
};
