/*
问题：
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
思路：
用栈来解决这种题目。
*/

class Solution {
public:
    bool isMatch(char a, char b) {
	if (a == '(' && b == ')') {
	    return true;
	}
	else if (a == '['&&b == ']') {
	    return true;
	}
	else if (a == '{' && b == '}') {
	    return true;
	}
	return false;
    }
    bool isValid(string s) {
	stack<char> Stack;
	for (int i = 0;i < s.length();i++) {
	    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
		Stack.push(s[i]);
	    }
	    else {
		if (Stack.empty())return false;
		if (!isMatch(Stack.top(), s[i])) {
		    return false;
		}
		Stack.pop();
	    }
	}
	if (Stack.empty())return true;
	return false;
    }
};
