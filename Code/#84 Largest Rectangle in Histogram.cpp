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
维护一个栈
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.insert(height.begin(),0); // dummy "0" added to make sure stack s will never be empty
        height.push_back(0); // dummy "0" added to clear the stack at the end
        int len = height.size();
        int i, res = 0, idx;
        stack<int> s; // stack to save "height" index
        s.push(0); // index to the first dummy "0"
        for(i=1;i<len;i++)
        {
            while(height[i]<height[idx = s.top()]) // if the current entry is out of order
            {
                s.pop();
                res = max(res, height[idx] * (i-s.top()-1) ); // note how the width is calculated, use the previous index entry
            }
            s.push(i);
        }
        height.erase(height.begin()); // remove two dummy "0"
        height.pop_back();
        return res;
    }
};