/*
问题：
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/*
思路：
n皇后问题，其实就是回溯问题，通过回溯穷举出所有可能解。
*/

class Solution {
public:
   vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>res;
      vector<string> tmp(n, string(n, '.'));
      solve(res, tmp, 0, n);
      return res;
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