/*
问题：
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

/*
思路：
和#31思路近似
*/

class Solution {
public:
   void nextPermutation(vector<int>& nums) {
      int k = nums.size() - 1;
      for (;k > 0;k--) {
         if (nums[k - 1] < nums[k])break;
      }
      if (k == 0) {
         sort(nums.begin(), nums.end());
         return;
      }
      int l = nums.size() - 1;
      for (;l > -1;l--) {
         if (nums[l] > nums[k - 1])break;
      }
      swap(nums[l], nums[k - 1]);
      reverse(nums.begin() + k, nums.end());
   }
   string getPermutation(int n, int k) {
      vector<int> nums;
      for (int i = 1;i <= n;i++) {
         nums.push_back(i);
      }
      for (int i = 0;i < k - 1;i++) {
         nextPermutation(nums);
      }
      string res = "";
      for (int i = 0;i < n;i++) {
         res.push_back((char)(nums[i] + '0'));
      }
      return res;
   }
};