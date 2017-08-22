/*
问题：
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

/*
思路：
从后往前搜一遍就行了
*/

class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int pos1 = m-1, pos2 = n-1;
      vector<int>tmp;
      for (int i = 0;i < m;i++) {
         tmp.push_back(nums1[i]);
      }
      for (int i = m + n - 1;i > -1;i--) {
         if (pos1<0 || (pos2 > -1 && tmp[pos1] < nums2[pos2])) {
            nums1[i] = nums2[pos2];
            pos2--;
         }
         else {
            nums1[i] = tmp[pos1];
            pos1--;
         }
      }
      return;
   }
};