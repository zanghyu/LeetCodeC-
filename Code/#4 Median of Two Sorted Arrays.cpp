/*
���⣺
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/*
˼·��
����������������������������λ������˴���С������ʼ�����ţ�
�ŵ����м�ļ�����λ������Ҫע��������һ����ż����������λ��Ϊ�м���������ƽ����
*/

class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int pos = (nums1.size() + nums2.size()) / 2;
      int i = 0, j = 0, now = 0;
      int a, b;
      int numtmp = -1;
      while (true) {
         if (now == pos)a = numtmp;
         if (now == pos + 1) {
            b = numtmp;
            break;
         }
         if (j<nums2.size() && ((i >= nums1.size()) || (nums1[i]>nums2[j]))) {
            numtmp = nums2[j++];
         }
         else numtmp = nums1[i++];
         now++;
      }
      if ((nums1.size() + nums2.size()) % 2)return b;
      return (double)(a + b) / 2;
   }
};