/*
问题：
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/*
思路：
和上题一样
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>>res;
		vector<string> tmp(n, string(n, '.'));
		solve(res, tmp, 0, n);
		return res.size();
    }
	void solve(vector<vector<string>>&res, vector<string>&tmp, int row, int n) {
		if (row == n)
			res.push_back(tmp);
		for (int i = 0;i < n;i++) {
			if (isvalid(tmp, row, i,n)) {
				tmp[row][i] = 'Q';
				solve(res, tmp, row+1, n);
				tmp[row][i] = '.';
			}
		}
	}
	bool isvalid(vector<string>tmp, int row, int colomn,int n) {
		for (int i = 0;i < row;i++) {
			if (tmp[i][colomn] == 'Q')return false;
		}
		for (int i = row-1, j = colomn-1;i > -1 && j > -1;i--, j--) {
			if (tmp[i][j] == 'Q')return false;
		}
		for (int i = row - 1, j = colomn + 1;i > -1 && j < n;i--, j++) {
			if (tmp[i][j] == 'Q')return false;
		}

		return true;
	}
};