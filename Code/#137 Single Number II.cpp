/*
���⣺
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
˼·��
��������#136���񣬵���˼·Ҫ����һЩ��
����ÿ��Ԫ�ص�Ϊһ��32λ�Ķ�������������ÿһλ�ϳ���ҪôΪ1 ��ҪôΪ0�������飬ͳ��ÿһλ��1 ���ֵĴ���count���ض���3N����3N+1 �Ρ���count��3ȡģ���ܹ���õ��Ǹ�ֻ����1�ε�Ԫ�ظ�λ��0����1��
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