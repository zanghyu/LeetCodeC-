/*
问题：
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
思路：
这道题是一道dp的题，主要有两个解法，一个解法是直接按照两次交易dp做，还有一种是按照第i天最多进行j次交易做。
*/

/*
解法一：
http://blog.csdn.net/u012501459/article/details/46514309
定义4个状态，最后得到sell2表示结果
*/

class Solution {
public:
   int maxProfit(vector<int>& prices) {
      int buy1 = INT_MIN;
      int buy2 = INT_MIN;
      int sell1 = 0;
      int sell2 = 0;
      for (int i = 0;i<prices.size();i++)
      {
         sell2 = max(sell2, buy2 + prices[i]);
         buy2 = max(buy2, sell1 - prices[i]);
         sell1 = max(sell1, buy1 + prices[i]);
         buy1 = max(buy1, -prices[i]);
      }
      return sell2;
   }

};

/*
解法二：
http://blog.csdn.net/linhuanmars/article/details/23236995
用局部最优和全局最优求这类问题的通解
*/

class Solution {
public:
   int maxProfit(vector<int>& prices) {
      if (prices.size() == 0)return 0;
      vector<int>local(3,0);
      vector<int>global(3,0);
      for (int i = 0;i < prices.size()-1;i++) {
         int diff = prices[i + 1] - prices[i];
         for (int j = 2;j >= 1;j--) {
            local[j] = max(global[j - 1] + (diff > 0 ? diff : 0), local[j] + diff);
            global[j] = max(local[j], global[j]);
         }
      }
      return global[2];
   }
};
