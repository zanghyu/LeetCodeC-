/*
问题：
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

/*
思路：
和#78一样，最后加个去重就好了
*/

class Solution {
public:
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>>subs;
      vector<int>sub;
      sort(nums.begin(), nums.end());
      getSub(nums, 0, sub, subs);
      sort(subs.begin(), subs.end());
      subs.erase(unique(subs.begin(), subs.end()), subs.end());
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