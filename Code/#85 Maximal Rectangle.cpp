/*
问题：
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

/*
思路：
参考：
http://www.cnblogs.com/lichen782/p/leetcode_maximal_rectangle.html
这道题其实和#84很像很像，以当前位置为矩形左上角，画出图来就是#84
这道题核心部分其实在循环部分如何初始化height[j]，这种处理方式保证了列上的高度
*/

class Solution {
public:
   int maximalRectangle(vector<vector<char>>& matrix) {
      if (matrix.size() == 0 || matrix[0].size() == 0)return 0;
      int maxArea = 0;
      vector<int>height(matrix[0].size()+1,0);
      for (int i = 0;i < matrix.size();i++) {
         for (int j = 0;j < matrix[0].size();j++) {
            if (matrix[i][j] == '0')height[j] = 0;
            else height[j]++;
         }
         maxArea = max(maxArea, largestRectangleArea(height));
      }
      return maxArea;
   }
   int largestRectangleArea(vector<int>& heights) {
      stack<int> s;
      int res = 0;
      heights.push_back(0);
      for (int i = 0;i < heights.size();i++) {
         while (!s.empty() && heights[s.top()] >= heights[i]) {
            int h = heights[s.top()];
            s.pop();
            int len = s.empty() ? i : (i - 1 - s.top());
            res = max(res, h*len);
         }
         s.push(i);
      }
      return res;
   }
};