/*
问题：
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

/*
思路：
直接遍历可以过。o(lgn)可以用二分
*/

/*
直接遍历
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
	int pos = 0;
	for (int i = 0;i < nums.size();i++) {
	    if (nums[i] == target)
		pos = i;
	    if (i == nums.size()-1 && nums[i]<target) {
		pos = i+1;
		continue;
	    }
	    if (nums[i] < target && nums[i + 1] > target)
		pos = i+1;
	    }
	return pos;
    }
};
/*
二分
*/
