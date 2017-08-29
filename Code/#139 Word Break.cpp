/*
���⣺
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

/*
˼·��
ֱ�Ӱ���֮ǰ�ķ�ʽ����DFS�Ļ���TLE��������������Ľ������������һ��bool�����¼�����ĳ������֮ǰ���ж����޽⣬�´�ѭ��ʱ�ͻ�����������䣻����DFSҲ���԰���DP��д��д
*/

class Solution {
public:
   bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> us(wordDict.begin(), wordDict.end());
      if (s.empty())return true;
      vector<bool> res(s.size() + 1, false);
      res[0] = true;
      for (int i = 0;i <= s.size();i++) {
         for (int j = 0;j < i;j++) {
            if (res[j] && us.count(s.substr(j, i - j))) {
               res[i] = true;
               break;
            }
         }
      }
      return res[s.size()];
   }
};