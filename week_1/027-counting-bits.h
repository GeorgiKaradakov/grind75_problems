#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> cnt;
    for (int i = 0; i <= n; i++) {
      int t = i, cn = 0;
      while (t > 0) {
        cn += t % 2;
        t /= 2;
      }
      cnt.push_back(cn);
    }

    return cnt;
  }
};
