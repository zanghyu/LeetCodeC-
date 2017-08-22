/*
���⣺
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

ͼ�� https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

/*
˼·��
��һ��˼·��
�������飬ÿ�ҵ�һ���ֲ���ֵ��Ȼ����ǰ�������е�ֵ�������ͬ�ľ��������ÿ�ζԱȱ������ֵ��
��������˼·��TLE
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
�ڶ���˼·��
http://blog.csdn.net/yutianzuijin/article/details/52072427
����ά��һ��ջ����������������У��൱���������ַ������Ҿֲ���ֵ������ǰֵС��ջ��ֵʱ��ȡ��ջ��Ԫ�أ�Ȼ����㵱ǰ���������Ȼ���ٶԱȵ�ǰֵ���µ�ջ��ֵ��С��������ջ��ֵ������ȡ��ջ�������ʱ��ͬ��������������մ����ƣ��ɵ������Ρ�����i-1-s.top()�ǵ�ǰλ�õ�ջ��λ�õľ��롣
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