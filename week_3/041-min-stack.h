#include <climits>
#include <stack>
using namespace std;

class MinStack {
private:
  stack<pair<int, int>> s;

public:
  MinStack() {}

  void push(int val) {
    if (this->s.empty())
      this->s.emplace(val, val);
    else
      this->s.emplace(val, min(this->s.top().second, val));
  }

  void pop() { this->s.pop(); }

  int top() { return this->s.top().first; }

  int getMin() { return this->s.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
