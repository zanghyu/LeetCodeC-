/*
问题：
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

/*
思路：
和#139类似，一个DFS加剪枝。定义一个一维数组possible，其中possible[i] = true表示在[i, n]区间上有解，n为s的长度，如果某个区间之前被判定了无解，下次循环时就会跳过这个区间，从而大大减少了运行时间

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