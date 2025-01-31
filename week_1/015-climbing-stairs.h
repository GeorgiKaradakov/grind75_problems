class Solution {
public:
  int climbStairs(int n) {
    long long prev1 = 1, prev2 = 1;

    for (int i = 2; i <= n; i++) {
      long long res = prev1 + prev2;
      prev2 = prev1;
      prev1 = res;
    }

    return prev1;
  }
};
