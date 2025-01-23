#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<int> st;

    for (auto ch : s) {
      if (ch == '(')
        st.push(')');
      if (ch == '[')
        st.push(']');
      if (ch == '{')
        st.push('}');

      if (ch == ')' || ch == ']' || ch == '}') {
        if (st.empty())
          return 0;

        if (st.top() != ch)
          return 0;
        else
          st.pop();
      }
    }

    return st.empty();
  }
};
