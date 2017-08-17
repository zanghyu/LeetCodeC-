/*
问题：

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

图见：
https://leetcode.com/problems/trapping-rain-water/description/

*/

/*
思路：
我们使用两个指针，一个从左向右遍历，一个从右向左遍历。从左向右遍历时，记录下上次左边的峰值，如果右边一直没有比这个峰值高的，就已经加上这些差值。从右向左遍历时，记录下上次右边的峰值，如果左边一直没有比这个峰值高的，就加上这些差值。难点在于，当两个指针遍历到相邻的峰时，我们要选取较小的那个峰值来计算差值。所以，我们在遍历左指针或者右指针之前，要先判断左右两个峰值的大小。
*/

class Solution {
public:
   int trap(vector<int>& height) {
      int l = 0, r = height.size() - 1;
      int lower = 0,h = 0,water = 0;
      while (l < r) {
         lower = height[height[l] < height[r] ? l++ : r--];
         h = max(lower, h);
         water += h - lower;
      }
      return water;
   }
};