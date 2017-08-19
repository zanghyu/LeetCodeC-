/*
问题：
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

/*
思路：
这道题写个表就可以得出结果，其实是一道很简单的dp，当前的步数dp[i][j] = dp[i-1][j]+dp[i][j-1]
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
		int a[100][100];
		for (int i = 0;i < 100;i++) {
			a[i][0] = 1;
		}
		for (int i = 0;i < 100;i++) {
			a[0][i] = 1;
		}
		for (int i = 0;i < 100;i++) {
			a[1][i] = i+1;
		}
		for (int i = 2;i < 100;i++) {
			for (int j = 1;j < 100;j++) {
				a[i][j] = a[i][j-1] + a[i-1][j];
			}
		}
		return a[m - 1][n - 1];
	}
};