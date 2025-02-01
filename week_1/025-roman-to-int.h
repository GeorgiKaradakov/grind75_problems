#include <string>
using namespace std;

class Solution {
public:
  int romanToInt(string s) { // overengineered
    int res = 0;

    for (int i = 0; i < s.size(); i++) {
      if ((s[i] == 'I') &&
          (i + 1 < s.size() && (s[i + 1] == 'X' || s[i + 1] == 'V'))) {
        res += convert(s[i + 1]) - 1;
        i++;
      } else if (s[i] == 'X' &&
                 (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C'))) {
        res += convert(s[i + 1]) - 10;
        i++;
      } else if (s[i] == 'C' &&
                 (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
        res += convert(s[i + 1]) - 100;
        i++;
      } else {
        res += convert(s[i]);
      }
    }

    return res;
  }

private:
  int convert(char c) {
    switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return -1;
    }
  }
};
