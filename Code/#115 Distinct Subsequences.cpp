/*
问题：
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/

/*
思路：
一道二维dp的题，按照例子画出dp图，分析之后可以知道1)当不匹配时dp[i][j] = dp[i][j-1] ,2)当匹配上时dp[i][j] = dp[i][j-1]+dp[i-1][j-1]

*/



class Solution {
public:
   int numDistinct(string s, string t) {
      vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1));
      for (int j = 0; j <= s.length(); j++) {
         dp[0][j] = 1;
      }
      for (int i = 1; i <= t.length();i++) {
         dp[i][0] = 0;
      }
      for (int i = 1;i <= t.length();i++) {
         for (int j = 1;j <= s.length();j++) {
            if (s[j - 1] == t[i - 1]) dp[i][j] = dp[i][j-1] + dp[i-1][j - 1];
            else dp[i][j] = dp[i][j - 1];
         }
      }
      return dp[t.length()][s.length()];
   }
};