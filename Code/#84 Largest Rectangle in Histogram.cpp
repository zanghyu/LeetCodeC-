/*
问题：
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

图见 https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

/*
思路：
第一种思路：
遍历数组，每找到一个局部峰值，然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值。
但是这种思路会TLE
*/

class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
      int len = 0, sum = 0, res = 0;
      for (int i = 0;i < heights.size();i++) {
         if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) {
            continue;
         }
         int minH = heights[i];
         for (int j = i;j > -1;j--) {
            minH = min(minH, heights[j]);
            sum = minH*(i - j + 1);
            res = max(res, sum);
         }
      }
      return res;
   }
};

/*
第二种思路：
http://blog.csdn.net/yutianzuijin/article/details/52072427
这里维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值，当当前值小于栈顶值时，取出栈顶元素，然后计算当前矩形面积，然后再对比当前值和新的栈顶值大小，若还是栈顶值大，则再取出栈顶，算此时共同矩形区域面积，照此类推，可得最大矩形。其中i-1-s.top()是当前位置到栈顶位置的距离。
*/

class Solution {
public:
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