/*
��Ŀ
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
˼·
�����Ҫ������ظ��ַ����Ӵ����ù�ϣ�����ַ�����λ�ã�ÿ�θ��¡������һ�����ֵ��

*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> res(256,-1);
        int maxlength=0,start=-1;
        for(int i=0;i<s.length();i++){
            if(res[s[i]]>start){
                start=res[s[i]];
            }
            res[s[i]] = i;
            maxlength = max(maxlength,i-start);
        }
        return maxlength;
    }
};