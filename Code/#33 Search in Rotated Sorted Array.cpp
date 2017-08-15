/*
问题：
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
思路：
这道题虽然直接遍历o(n)可以过，但是本质应该是考察二分的方法。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
	int pos = -1;
	int low = 0, high = nums.size() - 1;
	while (low < high) {
	    int mid = (low + high) / 2;
	    if (nums[mid] > nums[high])low = mid + 1;
	    else high = mid;
	}
	int tmp = low;
	low = 0, high = nums.size() - 1;
	while (low <= high) {
            int mid = (low + high) / 2;
	    int truemid = (tmp + mid)%nums.size();
	    if (nums[truemid] > target)high = mid - 1;
	    else if (nums[truemid] < target)low = mid + 1;
	    else return truemid;
	}
	return pos;
    }
};