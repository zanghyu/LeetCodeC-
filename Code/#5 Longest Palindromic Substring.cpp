/*
问题：
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
思路：
读题是关键，最开始以为是类似于#3的求有一个重复字母的子串的问题。结果发现是理解错了。
该题目是要求回文子串
那么遍历一遍该字符串的每个位置，从该位置左右查找取其中最大值就可以。
需要注意的是：
    当有连续若干与该位置相同的字母时的处理方式
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int start=0, maxLen=0;
	int rStart=-1, rMaxLen=-1;
	if (s.length() == 0)return "";
	if (s.length() == 1)return s;
	for (int i = 0;i < s.size();i++) {
	    int j = i, k = i;
	    while (k < s.size() - 1 && s[k + 1] == s[k])
		k++;
	    i = k;
	    while (k < s.size() - 1 && j>0 && s[k+1] == s[j-1]) {
		k++;
		j--;
	    }
	    maxLen = k - j + 1;
	    if (maxLen > rMaxLen) {
		rStart = j;
	    }
	    rMaxLen = max(rMaxLen, maxLen);
	}
	return s.substr(rStart, rMaxLen);
    }
};