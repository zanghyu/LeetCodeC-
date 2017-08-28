/*
问题：
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
思路：
看起来和#136很像，但是思路要复杂一些。
考虑每个元素的为一个32位的二进制数，这样每一位上出现要么为1 ，要么为0。对数组，统计每一位上1 出现的次数count，必定是3N或者3N+1 次。让count对3取模，能够获得到那个只出现1次的元素该位是0还是1。
*/

class Solution {
public:
   int singleNumber(vector<int>& nums) {
      int res = 0;
      for (int i = 0;i < 32;i++) {
         int count = 0;
         int mask = 1 << i;
         for (int j = 0;j < nums.size();j++) {
            if (nums[j] & mask)count++;
         }
         if (count % 3)res |= mask;
      }
      return res;
   }
};