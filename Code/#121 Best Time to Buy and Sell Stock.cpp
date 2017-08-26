/*
问题：
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

/*
思路：
记录最小值位置和该位置之后的最大值位置，然后算一下就行了。
*/

class Solution {
public:
   int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
      int sum = 0;
      int minP = 0;
      int maxP = 0;
      for (int i = 0; i < prices.size();i++) {
         if (prices[i] < prices[minP])minP = i;
         if (maxP < minP) maxP = i;
         else if (prices[i] > prices[maxP]) maxP = i;
         sum = max(sum, prices[maxP]-prices[minP]);
      }
      return sum;
   }
};