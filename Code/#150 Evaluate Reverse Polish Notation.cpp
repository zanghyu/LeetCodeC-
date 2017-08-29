/*
问题：
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

/*
思路：
后缀表达式，用stack辅助计算就可
*/

class Solution {
public:
   int strToNum(string a) {
      return atoi(a.c_str());
   }
   int calculate(int a, int b, string opt) {
      if (opt == "+") {
         return a + b;
      }
      else if (opt == "-") {
         return a - b;
      }
      else if (opt == "*") {
         return a * b;
      }
      else if (opt == "/") {
         return a / b;
      }
   }
   int evalRPN(vector<string>& tokens) {
      int sum = 0;
      stack<int> st;
      int a, b;
      for (int i = 0;i < tokens.size();i++) {
         if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            sum = calculate(b, a, tokens[i]);
            st.push(sum);
         }
         else {
            st.push(strToNum(tokens[i]));
         }
      }
      return st.top();
   }
};