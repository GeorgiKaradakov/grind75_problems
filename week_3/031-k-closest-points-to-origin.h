#include <algorithm>
#include <cassert>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> points, int k) {
    auto comparator = [](const vector<int> &a, const vector<int> &b) {
      float dist_a = sqrt(a[0] * a[0] + a[1] * a[1]);
      float dist_b = sqrt(b[0] * b[0] + b[1] * b[1]);

      return dist_a < dist_b;
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> heap(
        comparator);

    for (int i = 0; i < k; i++) {
      heap.push(points[i]);
    }

    for (int i = k; i < points.size(); i++) {
      float dist_a =
          sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
      float dist_b =
          sqrt(heap.top()[0] * heap.top()[0] + heap.top()[1] * heap.top()[1]);

      if (dist_b > dist_a) {
        heap.pop();
        heap.push(points[i]);
      }
    }

    vector<vector<int>> res;
    while (heap.size()) {
      res.push_back(heap.top());
      heap.pop();
    }

    return res;
  }
};
