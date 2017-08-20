/*
问题：
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
思路：
和#62思路基本差不多，只不过这道题是取最小值
*/


class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();
      vector<vector<int>> res(m,vector<int> (n));
      res[0][0] = grid[0][0];
      for (int i = 1;i < m;i++) {
         res[i][0] = grid[i][0]+res[i-1][0];
      }
      for (int i = 1;i < n;i++) {
         res[0][i] = grid[0][i]+res[0][i-1];
      }
      for (int i = 1;i < m;i++) {
         for (int j = 1;j < n;j++) {
            res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
         }
      }
      return res[m-1][n-1];
   }
};