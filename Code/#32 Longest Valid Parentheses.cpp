/*
���⣺
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
˼·��
�õ���ջ��������������Ĳ����������Ƚ�-1����ջ�У���֤��0��ʼʱ��i-(-1)=i+1���������û�뵽�ĵط���
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