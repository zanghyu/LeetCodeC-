/*
问题：
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

/*
思路：
这道题是一个简单的DFS，直接递归就行了
*/

class Solution {
public:
   vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      if (s.empty())return res;
      vector<string>now;
      dfs(res, now, 0, s);
      return res;
   }
   void dfs(vector<vector<string>>& res, vector<string>& now, int start, string s) {
      if (start == s.length()) {
         res.push_back(now);
         return;
      }
      for (int i = start;i < s.length();i++) {
         if (isPalindrome(s, start, i)) {
            now.push_back(s.substr(start, i - start + 1));
            dfs(res, now, i + 1, s);
            now.pop_back();
         }
      }
   }
   bool isPalindrome(string s, int start, int end) {
      while (start <= end) {
         if (s[start++] != s[end--])return false;
      }
      return true;
   }
};