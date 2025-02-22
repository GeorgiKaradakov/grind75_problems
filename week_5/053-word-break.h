#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> wordDict) {
    int dp[s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++)
      dp[i] = 0;
    dp[s.size()] = 1;

    for (int i = s.size() - 1; i >= 0; i--) {
      for (string w : wordDict) {
        if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
          dp[i] = dp[i + w.size()];
        }

        if (dp[i])
          break;
      }
    }

    return dp[0];
  }
};
