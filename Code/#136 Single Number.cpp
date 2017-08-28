/*
问题：
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
思路：
见过无数次的一道题...一个数组每个数都出现两次，只有一个出现一次，直接异或就能得到结果。

这道题的变形还有     一个数组里每个数都出现两次，只有两个出现一次，这两个分别是什么。 也是用异或做。

*/

class Solution {
public:
   int singleNumber(vector<int>& nums) {
      int res = nums[0];
      for (int i = 1;i < nums.size();i++) {
         res = res ^ nums[i];
      }
      return res;
   }
};