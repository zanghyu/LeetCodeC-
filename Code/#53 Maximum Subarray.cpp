/*
问题：
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

/*
思路：
贪心
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = nums[0];
        for(int it:nums){
            sum+=it;
            res = max(res,sum);
            sum = max(sum,0);
        }
        return res;
    }
};
