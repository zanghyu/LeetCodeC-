/*
问题：
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

/*
思路：
类比#15 3Sum。
其实这个类型的题目可以推广到nSum
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num,int target) {
	vector<vector<int> > res;
	sort(num.begin(), num.end());
	for (int j = 0;j < num.size();j++) {
  	    int target_0 = target-num[j];
	    for (int i = j+1;i < num.size();i++) {
		int target_1 = target_0-num[i];
		int front = i + 1;
		int back = num.size() - 1;
		while (front < back) {
		    int sum = num[front] + num[back];
		    if (sum > target_1) {
			back--;
		    }
		    else if (sum < target_1) {
			front++;
		    }
		    else {
			vector<int> v(4, 0);
			v[0] = num[j];
			v[1] = num[i];
			v[2] = num[front];
			v[3] = num[back];
			res.push_back(v);
			while ((front < back) && (num[front] == v[2]))front++;
			while ((front < back) && (num[back] == v[3]))back--;
		    }
		}
		while ((i + 1 < num.size()) && num[i + 1] == num[i])i++;
	    }
	    while ((j + 1 < num.size()) && num[j + 1] == num[j])j++;
	}
	return res;

    }
};