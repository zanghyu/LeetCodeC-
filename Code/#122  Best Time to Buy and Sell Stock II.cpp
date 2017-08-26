/*
问题：
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

/*
思路：
由于可以买卖多次，所以只要当前比前一个价格高，就直接加上差价就行了。
*/

class Solution {
public:
   int maxProfit(vector<int>& prices) {
      if (prices.size() == 0)return 0;
      int sum = 0;
      for (int i = 0;i < prices.size() - 1;i++) {
         if (prices[i + 1] > prices[i]) {
            sum += prices[i + 1] - prices[i];
         }
      }
        return sum;
   }
};