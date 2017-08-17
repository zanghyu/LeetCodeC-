/*
问题：
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
思路：
和#31思路一样。
*/

class Solution {
public:
   vector<int> nextPermutation(vector<int> nums) {
      int k = nums.size() - 1;
      for (;k > 0;k--) {
         if (nums[k - 1] < nums[k])break;
      }
      if (k == 0) {
         sort(nums.begin(), nums.end());
         vector<int> tmp = nums;
         return tmp;
      }
      int l = nums.size() - 1;
      for (;l > -1;l--) {
         if (nums[l] > nums[k - 1])break;
      }
      swap(nums[l], nums[k - 1]);
      reverse(nums.begin() + k, nums.end());
      vector<int> tmp = nums;
      return tmp;
   }
   vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>>res;
      vector<int> tmp = nums;
      tmp = nextPermutation(nums);
      res.push_back(tmp);
      while (tmp != nums) {
         tmp = nextPermutation(tmp);
         res.push_back(tmp);
      }
      return res;
   }
};