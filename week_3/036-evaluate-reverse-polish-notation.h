#include <cassert>
#include <cctype>
#include <climits>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> tokens) {
    stack<int> nums;

    auto calc = [](const int &num1, const int &num2, char op) {
      switch (op) {
      case '+':
        return num1 + num2;
      case '-':
        return num1 - num2;
      case '*':
        return num1 * num2;
      case '/':
        return num1 / num2;
      default:
        return 0;
      }
    };

    for (string token : tokens) {
      if ('0' <= token[0] && token[0] <= '9' || token.size() > 1) {
        nums.push(stoi(token));
      } else {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();

        int sum = calc(num1, num2, token[0]);
        nums.push(sum);
      }
    }

    return nums.top();
  }
};
