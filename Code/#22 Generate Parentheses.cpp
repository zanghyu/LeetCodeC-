/*
���⣺
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
˼·��
��Ȼ��һ�ۿ����;����õݹ��������������û����򵥵Ľ���취������һ������Ľⷨ��
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