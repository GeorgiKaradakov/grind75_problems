#pragma once

#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> prices) {
    int l = 0, r = 1, max_prof = 0;

    while (r < prices.size()) {
      int curr_prof = prices[l] - prices[r];

      if (prices[l] < prices[r]) {
        max_prof = max(max_prof, prices[r] - prices[l]);
      } else {
        l = r;
      }

      r++;
    }

    return max_prof;
  }
};
