/*
问题：
Write a function to find the longest common prefix string amongst an array of strings.
*/

/*
思路：
两个两个求最长前缀就可以
*/

class Solution {
public:
	string PrefixForTwo(string str1, string str2) {
	    int pos = 0;
	    for (;pos < str1.length() || pos < str2.length();pos++) {
		if (str1[pos] != str2[pos])break;
	    }
	    return str1.substr(0, pos);
	}
	string longestCommonPrefix(vector<string>& strs) {
	    if (strs.size() == 0)return "";
	    if (strs.size() == 1)return strs[0];
	    string res = PrefixForTwo(strs[0], strs[1]);
	    for (int i = 2;i < strs.size();i++) {
		res = PrefixForTwo(res, strs[i]);
	    }
	    return res;
	}
};