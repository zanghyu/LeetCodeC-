/*
问题：
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
思路：
用到了栈，这个方法中最精髓的部分在于首先将-1放入栈中，保证从0开始时，i-(-1)=i+1。这点是我没想到的地方。
*/

class Solution {
public:
    int longestValidParentheses(string s) {
	int res = 0;
	stack<int>st;
	st.push(-1);
	for (int i = 0;i < s.length();i++) {
	    int t = st.top();
	    if (t != -1 && s[i] == ')'&&s[t] == '(') { 
		st.pop();
		res = max(res, i - st.top());
	    }
	    else {
		st.push(i);
	    }
	}
	return res;
    }
};