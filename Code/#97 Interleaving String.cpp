/*
问题：
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

/*
思路：
一般来说字符串匹配问题都是更新一个二维dp数组，核心就在于找出递推公式。
首先可以根据题中给出的例子写出二维dp数组。
  Ø d b b c a
Ø T F F F F F
a T F F F F F
a T T T T T F
b F T T F T F
c F F T T T T
c F F F T F T
观察可以得知每个点的左边或上边有可能为True或是False，两边都可以更新过来，只要有一条路通着，那么这个点就可以为True。当然当前位置的字符也要和比较的那个字符串的当前字符相等。
即  dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
*/

class Solution {
public:
   bool isInterleave(string s1, string s2, string s3) {
      if (s1.length() + s2.length() != s3.length())return false;
      vector<vector<bool>>dp(s1.length()+1, vector<bool>(s2.length()+1,false));
      dp[0][0] = true;
      for (int i = 1;i <= s1.length();i++) {
         dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
      }
      for (int j = 1;j <= s2.length();j++) {
         dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
      }
      for (int i = 1;i <= s1.length();i++) {
         for (int j = 1;j <= s2.length();j++) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
         }
      }
      return dp[s1.length()][s2.length()];
   }
};