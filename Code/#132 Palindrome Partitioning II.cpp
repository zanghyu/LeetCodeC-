/*
问题：
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/*
思路：
如果按照#131的DFS做，则会TLE。因此我们用一维dp来处理这道题。
参考博客：
http://www.cnblogs.com/springfor/p/3891896.html
*/

class Solution {
public:
   int minCut(string s) {
      if (s.size() <= 1)return 0;
      vector<vector<bool>> p(s.size(),vector<bool> (s.size()));
      vector<int> dp(s.size()+1);
      for (int i = 0;i < s.size();i++) {
         dp[i] = s.size() - i;
      }
      for (int i = s.size() - 1;i > -1;i--) {
         for (int j = i;j < s.size();j++) {
            if (s[i] == s[j]) {
               if (j - i < 2 || p[i + 1][j - 1] ) {
                  p[i][j] = true;
                  dp[i] = min(dp[i], dp[j + 1]+1);
               }
            }
         }
      }
      return dp[0]-1;
   };
};