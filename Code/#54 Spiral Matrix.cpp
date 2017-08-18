/*
问题：
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*
思路：
直接看代码还是挺清楚的
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())return {};
		int m = matrix.size(), n = matrix[0].size();
		int u = 0, d = m - 1, l = 0, r = n - 1;
		vector<int>res;
		while (true) {
			for (int i = l;i <= r;i++) {
				res.push_back(matrix[u][i]);
			}
			if (++u > d)break;

			for (int i = u;i <= d;i++) {
				res.push_back(matrix[i][r]);
			}
			if (--r < l)break;
			for (int i = r;i >= l;i--) {
				res.push_back(matrix[d][i]);
			}
			if (--d < u)break;
			for (int i = d;i >= u;i--) {
				res.push_back(matrix[i][l]);
			}
			if (++l > r)break;
		}
		return res;
	}
};