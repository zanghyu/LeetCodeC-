/*
���⣺
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

/*
˼·��
�ȴ�С�������򣬱�֤������ֶ���ظ������С�
Ȼ������Ŀ��Ϊb+c=-a������������ָ�� �Ӵ�С���м俿������������������vector��
�ص�����ͨ���������Ԥ����

�������ͣ�
#1 Two Sum

*/

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
	    vector<vector<int> > res;
	    sort(num.begin(), num.end());
	    for (int i = 0;i < num.size();i++) {
		int target = -num[i];
		int front = i + 1;
		int back = num.size() - 1;
		while (front < back) {
		    int sum = num[front] + num[back];
	    	    if (sum > target) {
			back--;
		    }
		    else if (sum < target) {
			front++;
		    }
		    else {
			vector<int> v(3, 0);
			v[0] = num[i];
			v[1] = num[front];
			v[2] = num[back];
			res.push_back(v);
			while ((front < back)&&(num[front] == v[1]))front++;
			while ((front < back) && (num[back] == v[2]))back--;
		    }
		}
		while ((i + 1 < num.size()) && num[i+1] == num[i])i++;
	    }
            return res;

	}
};