/*
���⣺

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

ͼ����
https://leetcode.com/problems/trapping-rain-water/description/

*/

/*
˼·��
����ʹ������ָ�룬һ���������ұ�����һ����������������������ұ���ʱ����¼���ϴ���ߵķ�ֵ������ұ�һֱû�б������ֵ�ߵģ����Ѿ�������Щ��ֵ�������������ʱ����¼���ϴ��ұߵķ�ֵ��������һֱû�б������ֵ�ߵģ��ͼ�����Щ��ֵ���ѵ����ڣ�������ָ����������ڵķ�ʱ������Ҫѡȡ��С���Ǹ���ֵ�������ֵ�����ԣ������ڱ�����ָ�������ָ��֮ǰ��Ҫ���ж�����������ֵ�Ĵ�С��
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