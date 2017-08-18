/*
问题：

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].


*/

/*
思路：
挺简单的...直接看代码就行
*/

class Solution {
public:
   vector<Interval> merge(vector<Interval>& intervals) {
      if (intervals.empty())return{};
      sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start<b.start;});
      vector<Interval> res;
      res.push_back(intervals[0]);
      for (int i = 1;i < intervals.size();i++) {
         if (res.back().end < intervals[i].start)res.push_back(intervals[i]);
         else res.back().end = max(res.back().end, intervals[i].end);
      }
      return res;
   }
};
