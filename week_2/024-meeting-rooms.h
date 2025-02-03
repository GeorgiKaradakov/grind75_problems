#include "../utils/interval.h"
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  bool canAttendMeetings(vector<Interval> intervals) {
    if (intervals.size() <= 1)
      return 1;

    sort(intervals.begin(), intervals.end(),
         [](Interval f, Interval s) { return f.start < s.start; });

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1].end > intervals[i].start)
        return 0;
    }

    return 1;
  }
};
