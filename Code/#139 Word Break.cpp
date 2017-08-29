/*
问题：
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

/*
思路：
直接按照之前的方式进行DFS的话会TLE，对于这种情况的解决方案就是用一个bool数组记录，如果某个区间之前被判定了无解，下次循环时就会跳过这个区间；这种DFS也可以按照DP的写法写
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