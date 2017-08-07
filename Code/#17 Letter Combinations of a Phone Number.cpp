/*
���⣺
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

1      2       3
      abc     def
4      5       6
ghi   jkl     mno
7      8       9
pqrs  tuv     wxyz
       0


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

/*
˼·��
�ʼ�������������dfs���������������뵽�õݹ���������֮��������Լ���˼·̫�����ˡ�
����discuss���һ���㷨��ֻ��������ѭ������������������Ĺ������о���ֵ��ѧϰ����
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
	vector<string>res;
	if (digits.empty())return vector<string>();
	res.push_back("");
	vector<string> v = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	for (int i = 0;i < digits.size();i++) {
	    int num = digits[i] - '0';
	    if (num < 0 || num>9)break;
    	    string str1 = v[num];
	    if (str1.empty())continue;
	    vector<string>tmp;
	    for (int j = 0;j < res.size();j++) {
		for (int k = 0;k < str1.size();k++) {
		    tmp.push_back(res[j] + str1[k]);
		}
	    }
	    res.swap(tmp);
	}
	return res;
    }
};