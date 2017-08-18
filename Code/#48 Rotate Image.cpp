/*
���⣺
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
˼·��
һ������任���⣬��ԭ����˳ʱ����ת90��,ÿ�ζ�ת�ĸ��ǣ�Ȼ�󲻶����м�����
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