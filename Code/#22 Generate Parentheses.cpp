/*
问题：
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

/*
思路：
虽然第一眼看到就觉得用递归做，但是想半天没想出简单的解决办法，看了一个巧妙的解法。
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
	vector<string> res;
	addpair(res, "", n, 0);
	return res;
    }
    void addpair(vector<string>& v, string str, int n, int m) {
	if (n == 0 && m == 0)v.push_back(str);
	if (m > 0)addpair(v, str + ")", n, m-1);
	if (n > 0)addpair(v, str + "(", n-1, m+1);
    }
};