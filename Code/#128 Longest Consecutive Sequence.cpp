/*
问题：
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/

/*
思路：
用一个集合存储数字，查到一个数字后把这个数字删掉，检查比该数字大一或者小一的是否在数组中，如果在就删掉，最后的长度是next-pre-1。求其中最长的。
*/

class Solution {
public:
   int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(),nums.end());
      int pre, next;
      int res = 0;
      for (int val : nums) {
         if (!s.count(val)) {
            continue;
         }
         s.erase(val);
         pre = val - 1, next = val + 1;
         while (s.count(pre)) {
            s.erase(pre);
            pre--;
         }
         while (s.count(next)) {
            s.erase(next);
            next++;
         }
         res = max(res, next - pre - 1);
      }
      return res;
   }
};