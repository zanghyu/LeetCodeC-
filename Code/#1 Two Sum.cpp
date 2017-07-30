/* 这道题没啥好说的，就是简单的两个循环
*  值得留意的是vector的用法，vector插入值是调用insert函数
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