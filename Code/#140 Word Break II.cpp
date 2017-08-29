/*
���⣺
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

/*
˼·��
��#139���ƣ�һ��DFS�Ӽ�֦������һ��һά����possible������possible[i] = true��ʾ��[i, n]�������н⣬nΪs�ĳ��ȣ����ĳ������֮ǰ���ж����޽⣬�´�ѭ��ʱ�ͻ�����������䣬�Ӷ�������������ʱ��

*/

class Solution {
public:
   vector<string> wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> us(wordDict.begin(), wordDict.end());
      vector<string> res;
      if (s.empty())return res;
      vector<bool> possible(s.size() + 1, true);
      string now = "";
      canBreak(s, us, res, now, possible, 0);
      return res;
   }
   void canBreak(string s, unordered_set<string>& wordSet, vector<string>& res, string& now, vector<bool>& possible, int start) {
      if (start == s.length()) {
         res.push_back(now);
         return ;
      }
      for (int i = start;i < s.length(); i++) {
         string sub = s.substr(start, i - start + 1);
         if (wordSet.count(sub) && possible[i+1]) {
            string tmp = now;
            int oldSize = res.size();
            if (now == "") now = now + sub;
            else now = now + " " + sub;
            canBreak(s, wordSet, res, now, possible, i + 1);
            if (res.size() == oldSize)possible[i + 1] = false;
            now = tmp;
         }
      }
   }
};