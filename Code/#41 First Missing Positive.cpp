/*
问题：
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

/*
思路：
这道题挺简单的，不知道为什么难度是hard...
*/

class Solution {
public:
   int firstMissingPositive(vector<int>& nums) {
      if (!nums.size())return 1;
      sort(nums.begin(), nums.end());
      int t = 1;
      for (int i = 0;i < nums.size()-1;i++) {
         if (nums[i] < 1)continue;
         if (nums[i] != t)return t;
         else if (nums[i + 1] != nums[i])t++;
      }
      if(nums[nums.size()- 1]!=t){
            return t;
        }
        else return t+1;
   }
};