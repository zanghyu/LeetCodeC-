/*
问题：
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
思路：
也是dfs,和上一道题类似。
*/

class Solution {
public:
   vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>subs;
      vector<int>sub;
      getSub(nums, 0, sub, subs);
      return subs;
   }
   void getSub(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
      subs.push_back(sub);
      for (int i = start;i < nums.size();i++) {
         sub.push_back(nums[i]);
         getSub(nums, i + 1, sub, subs);
         sub.pop_back();
      }
   }
};