/*
问题：
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

/*
思路：
简单的二分
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
	int start = 0, end = nums.size() - 1;
	int mid = (start + end) / 2;
	while (start < end) { 
	    if (nums[mid] > target)end = mid;
	    if (nums[mid] < target)start = mid;
	    if (nums[start] == target && nums[end] == target) {
		break;
	    }
	    if ((nums[start] == target)&&(nums[end] != target))end--;
	    else if ((nums[end] == target)&&(nums[start] != target))start++;
	    else {
	    	start++;
	    	end--;
	    }
	    mid = (start + end) / 2;
	}
	if (end != -1 && nums[start] != target && nums[end] != target) {
	    start = end = -1;
	}
	else if (end == -1) {
	    start = end = -1;
	}
	int s[2] = { start,end };
	vector<int>res(s,s+2);
	return res;
    }
};