/*
���⣺
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/

/*
˼·��
������˼·��ά���ٿ����У�
https://en.wikipedia.org/wiki/Permutation

���岽�����£�
Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].

Find the largest index l greater than k such that nums[k] < nums[l].

Swap the value of nums[k] with that of nums[l].

Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].


�ҵĴ����е�k-1�Ǿ��岽���е�k
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	int k = nums.size() - 1;
	for (;k > 0;k--) {
	    if (nums[k-1] < nums[k])break;
	}
	if (k == 0) {
	    sort(nums.begin(),nums.end());
	    return;
	}
	int l = nums.size()-1;
	for (;l > -1;l--) {
	    if (nums[l] > nums[k - 1])break;
	}
	swap(nums[l], nums[k - 1]);
	reverse(nums.begin()+k,nums.end());
    }
};