/*
问题：
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/

/*
思路：
一道简单的递归题，代码还是挺简单的
*/

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p[0] == '\0')return s[0] == '\0';
		if (p[1] != '*') {
			if (s[0] == p[0] || (s[0] != '\0'&&p[0] == '.')) {
				return isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
			}
		}
		else {
			if (isMatch(s, p.substr(2, p.size() - 2)))return true;
			int i = 0;
			while (s[i] == p[i] || (s[i] != '\0'&&p[i] == '.')) {
				if (isMatch(s.substr(++i, s.size() - i), p))
					return true;
			}
		}
		return false;
	}
};