/*
���⣺
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

*/

/*
˼·��
������ص����ڷ���ֵ����array�ĳ��ȣ�����numsҪ����µ�array��������������Ϊ[1,1,2]��������numsӦΪ[1,2]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int sum = 0;
	int pos = 0;
	if (nums.size() <2)return nums.size();
	nums[pos++] = nums[0];
	for (int i = 1;i < nums.size();i++) {
	    if (nums[i] != nums[i - 1])
		nums[pos++] = nums[i];
	    }
	return pos;
    }
};