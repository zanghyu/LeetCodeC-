/*
问题：
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

/*
思路：
这道题需要注意的地方就是遍历的同时直接在原数组上改就行了，如果用map记录反而麻烦。
*/

class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if (n == 0)return 0;
      int cnt = 0;
      int sum = 0;
      for (int i = 0;i<n;i++) {
         if (i>0 && nums[i] == nums[i - 1]) {
            cnt++;
            if (cnt >= 3)continue;
         }
         else cnt = 1;
         nums[sum++] = nums[i];
      }
      return sum;
   }
};