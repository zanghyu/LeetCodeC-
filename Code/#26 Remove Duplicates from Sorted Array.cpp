/*
问题：
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

*/

/*
思路：
这道题重点在于返回值是新array的长度，但是nums要变成新的array。像题中若输入为[1,1,2]，则最后的nums应为[1,2]
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