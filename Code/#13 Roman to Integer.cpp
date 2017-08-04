/*
问题：
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
思路：
跟上一道题思路相似

*/

class Solution {
public:
	int findInt(char c) {
	    const char ch[] = {'I','V','X','L','C','D','M'};
	    for (int i = 0;i < 7;i++) {
		if (c == ch[i])return i;
	    }
	}
	bool cmp(int a, int b) {
	    if (a == 0 && (b == 1 || b == 2))return true;
	    if (a == 2 && (b == 3 || b == 4))return true;
	    if (a == 4 && (b == 5 || b == 6))return true;
	    return false;
	}
	int toInt(int a) {
	    const int num[] = { 1,5,10,50,100,500,1000 };
	    return num[a];
	}
	int romanToInt(string s) {
	    int res = 0;
	    int flag = 1;
	    for (int i = 0;i < s.length()-1;i++) {
	    	if (cmp(findInt(s[i]), findInt(s[i + 1]))) {
		    flag = -1;
		}
		else flag = 1;
		res += flag*toInt(findInt(s[i]));
	    }
	    res += toInt(findInt(s[s.length() - 1]));
	    return res;
	}
};