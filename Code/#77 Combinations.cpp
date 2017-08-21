/*
问题：
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*
思路：
一道简单的dfs的题，只要能想清楚先push再递归再pop就很容易了
*/

class Solution {
public:
   vector<vector<int>> combine(int n, int k) {
      vector<vector<int>>res;
      if (n < k)return res;
      vector<int> tmp(0, k);
      comb(res, tmp, 0, 0, n, k);
        return res;
   }
   void comb(vector<vector<int>>& res, vector<int>& tmp, int start, int num, int n, int k) {
      if (num == k) {
         res.push_back(tmp);
         return;
      }
      for (int i = start;i < n;i++) {
         tmp.push_back(i + 1);
         comb(res, tmp, i+1, num+1, n, k);
         tmp.pop_back();
      }
   }
};