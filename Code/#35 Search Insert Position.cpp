/*
���⣺
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 �� 2
[1,3,5,6], 2 �� 1
[1,3,5,6], 7 �� 4
[1,3,5,6], 0 �� 0

*/

/*
˼·��
�������ַ�����ֱ�ӱ���Ҫ��...�������Ϊ������̫�ٵ�ԭ���...
*/

/*
ֱ�ӱ���
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
����
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
	int pos = 0;
	int low = 0, high = nums.size() - 1;
	int mid = (low + high) / 2;
	while (low < high) {
	    if (nums[mid] > target)high = mid - 1;
	    if (nums[mid] < target)low = mid + 1;
	    mid = (low + high) / 2;
	    if (nums[mid] == target)return mid;
	}
	if (target <= nums[low])return low;
	else if (target > nums[high])return high+1;
    }
};
