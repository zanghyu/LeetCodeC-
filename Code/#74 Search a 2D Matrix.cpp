/*
问题：
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

/*
思路：
其实是一个二维的二分，先按行二分，再按列二分。
*/

class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.empty())return false;
      int left = 0, right = matrix.size() - 1;
      int row = -1, col = -1;
      while (left < right - 1) {
         int mid = (left + right) / 2;
         if (matrix[mid][0] < target) {
            left = mid;
         }
         else if (matrix[mid][0] > target) {
            right = mid;
         }
         else {
            row = mid;
            break;
         }
      }
      if(!matrix[right].empty() && row==-1 && matrix[right][0] <= target)row = right;
      else if (!matrix[left].empty() && row==-1 && matrix[left][0] <= target) row = left;
      if (row == -1)return false;
      left = 0, right = matrix[0].size() - 1;
      while (left < right - 1) {
         int mid = (left + right) / 2;
         if (matrix[row][mid] < target) {
            left = mid;
         }
         else if (matrix[row][mid] > target) {
            right = mid;
         }
         else return true;
      }
      if (matrix[row][left] == target || matrix[row][right] == target)return true;
      return false;
   }
};