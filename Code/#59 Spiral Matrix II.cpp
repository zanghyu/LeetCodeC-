/*
问题：
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/*
思路：
和#54的思路基本一毛一样
*/

class Solution {
public:
   vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>>res;
      for (int i = 0;i < n;i++) {
         vector<int> tmp(n);
         res.push_back(tmp);
      }
      int m = n;
      int u = 0, d = n - 1, l = 0, r = n - 1;
      int num = 1;
      while (true) {
         for (int i = l;i <= r;i++)res[u][i] = num++;
         if (++u > d)break;
         for (int i = u;i <= d;i++)res[i][r] = num++;
         if (--r < l)break;
         for (int i = r;i >= l;i--)res[d][i] = num++;
         if (--d < u)break;
         for (int i = d;i >= u;i--)res[i][l] = num++;
         if (++l > r)break;
      }
      return res;
   }
};