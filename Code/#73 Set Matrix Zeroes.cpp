/*
问题：
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
思路：
有两种方式，一种是用一个sign数组记录有哪行哪列需要变成0。
*/

class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      int *sign = new int[m+n];
      for (int i = 0;i < m + n;i++) {
         sign[i] = 0;
      }
      for (int i = 0;i < m;i++) {
         for (int j = 0;j < n;j++) {
            if (matrix[i][j] == 0)sign[i] = 1, sign[m+j] = 1;
         }
      }
      for (int i = 0;i < m;i++) {
         if (sign[i] == 1) {
            for (int j = 0;j < n;j++) {
               matrix[i][j] = 0;
            }
         }
      }
      for (int j = 0;j < n;j++) {
         if (sign[m + j] == 1) {
            for (int i = 0;i < m;i++) {
               matrix[i][j] = 0;
            }
         }
      }
      return;
   }

};

/*
思路：
还有一种方式是只用O(1)的空间
*/

void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}