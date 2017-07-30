/*
题目
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


/* 
思路
这道题没啥好说的，就是简单的两个循环
值得留意的是vector的用法，vector插入值是调用insert函数
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size();i++) {
	    for (int j = 0;j < i; j++) {
	        if (nums.at(i) + nums.at(j) == target) {
		    vector<int> res;
		    res.insert(res.end(),j);
		    res.insert(res.end(),i);
		    return res;
 		}
            }
	}
    }
};