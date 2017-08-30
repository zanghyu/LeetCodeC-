/*
问题：
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?


*/

/*
思路：
从左到右扫一遍，从右到左扫一遍。
*/

class Solution {
public:
   int candy(vector<int>& ratings) {
      int sum = 0;
      if (!ratings.size())return 0;
      vector<int>dp(ratings.size(), 1);
      for (int i = 0;i < ratings.size() - 1;i++) {
         if (ratings[i + 1] > ratings[i]) {
            dp[i + 1] = dp[i] + 1;
         }
      }
      for (int i = ratings.size() - 1;i > 0;i--) {
         if (ratings[i] < ratings[i - 1]) {
            dp[i - 1] = max(dp[i-1],dp[i] + 1);
         }
      }
      for (int i = 0;i < dp.size();i++) {
         sum += dp[i];
      }
      return sum;
   }
};