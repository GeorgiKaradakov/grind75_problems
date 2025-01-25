#pragma once

#include <stack>
using namespace std;

class MyQueue {
private:
  stack<int> f, s;

public:
  MyQueue() {}

  void push(int x) {
    while (!f.empty()) {
      s.push(f.top());
      f.pop();
    }

    f.push(x);
    while (!s.empty()) {
      f.push(s.top());
      s.pop();
    }
  }

  int pop() {
    int val = f.top();
    f.pop();
    return val;
  }

  int peek() { return f.top(); }

  bool empty() { return f.empty(); }
};
