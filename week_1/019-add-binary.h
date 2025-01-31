#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string res(max(a.size(), b.size()) + 1, '0');

    int ost = 0, i = res.size() - 1;
    while (!a.empty() && !b.empty()) {
      char ai = a.back();
      char bi = b.back();
      a.pop_back();
      b.pop_back();
      if (ai == '1' && bi == '1') {
        res[i] = ost ? '1' : '0';
        ost = 1;
      } else if (ai == '0' && bi == '0') {
        if (ost) {
          res[i] = '1';
          ost = 0;
        } else {
          res[i] = '0';
        }
      } else {
        if (ost) {
          res[i] = '0';
        } else {
          res[i] = '1';
        }
      }
      i--;
    }

    while (!a.empty() || !b.empty()) {
      char ch = a.empty() ? b.back() : a.back();
      if (!a.empty() && b.empty())
        a.pop_back();
      else if (!b.empty())
        b.pop_back();

      if (ch == '1') {
        if (ost) {
          res[i] = '0';
        } else {
          res[i] = '1';
        }
      } else {
        if (ost) {
          res[i] = '1';
          ost = 0;
        } else {
          res[i] = '0';
        }
      }
      i--;
    }

    if (ost)
      res[0] = '1';
    else
      res = res.substr(1);

    return res;
  }

  string addBinaryEasier(string a, string b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      res += (carry % 2) + '0';
      carry /= 2;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
