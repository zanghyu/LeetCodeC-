/*
���⣺
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
˼·��
�����ǹؼ����ʼ��Ϊ��������#3������һ���ظ���ĸ���Ӵ������⡣��������������ˡ�
����Ŀ��Ҫ������Ӵ�
��ô����һ����ַ�����ÿ��λ�ã��Ӹ�λ�����Ҳ���ȡ�������ֵ�Ϳ��ԡ�
��Ҫע����ǣ�
    ���������������λ����ͬ����ĸʱ�Ĵ���ʽ
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