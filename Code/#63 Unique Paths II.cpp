/*
���⣺
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

/*
˼·��
������һ����ֻ�����ѵ�Ϊ1��λ��ȥ�������Ǹ�λ�õ����������0�����ˡ�
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> a(m+1,vector<int>(n+1,0));
        a[0][1]=1;
		for (int i = 1;i <= m;i++) {
			for (int j = 1;j <= n;j++) {
				if(!obstacleGrid[i-1][j-1])
					a[i][j] = a[i][j-1] + a[i-1][j];
			}
		}
		return a[m][n];
	}
};