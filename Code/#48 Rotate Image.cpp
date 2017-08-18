/*
问题：
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
思路：
一道矩阵变换的题，将原矩阵顺时针旋转90度,每次都转四个角，然后不断向中间缩。
*/

class Solution {
public:
   void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int a = 0;
      int b = n - 1;
      while (a<b) {
         for (int i = 0;i<(b - a);++i) {
            swap(matrix[a][a + i], matrix[a + i][b]);
            swap(matrix[a][a + i], matrix[b][b - i]);
            swap(matrix[a][a + i], matrix[b - i][a]);
         }
         ++a;
         --b;
      }
   }
};