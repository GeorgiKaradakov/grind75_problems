#include <string>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1;
    while (i >= 0 || j >= 0) {
      i = get_next_valid(s, i);
      j = get_next_valid(t, j);

      if (i < 0 && j < 0)
        return 1;
      if (i < 0 || j < 0)
        return 0;

      if (s[i] != t[j])
        return 0;
      i--, j--;
    }

    return 1;
  }

private:
  int get_next_valid(string s, int prev) {
    int b_cnt = 0;
    while (prev >= 0) {
      if (s[prev] == '#')
        b_cnt++;
      else if (b_cnt)
        b_cnt--;
      else
        break;
      prev--;
    }

    return prev;
  }
};
