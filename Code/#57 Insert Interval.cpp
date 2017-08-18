/*
问题：
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/*
思路：
主要考虑全面，如果有部分重叠，如果没重叠
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
   vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      if (intervals.empty()) {
         vector<Interval>res;
         res.push_back(newInterval);
         return res;
      }
      int flag = 0;
      int i = 0;
      for (;i < intervals.size();i++) {
         if (intervals[i].end >= newInterval.start&&intervals[i].start<=newInterval.start) {
            intervals[i].end = max(newInterval.end, intervals[i].end);
            intervals[i].start = min(newInterval.start, intervals[i].start);
            flag = 1;
            break;
         }
         else if (!flag && intervals[i].end >= newInterval.start && intervals[i].start > newInterval.start) {
            intervals.insert(intervals.begin() + i, newInterval);
            flag = 1;
            break;
         }
      }
      if (!flag) {
         intervals.push_back(newInterval);
         return intervals;
      }
      return merge(intervals);
   }
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