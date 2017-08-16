/*
问题：

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

图见：https://leetcode.com/problems/sudoku-solver/description/

*/

/*
思路：
这道题和上一道题几乎一样，思路相似。
*/

class Solution {
public:
   bool check(vector<vector<char>>& board, int i, int j, char c) {
      for (int x = 0;x < 9;x++) {
         if (board[x][j] == c)return false;
      }
      for (int y = 0;y < 9;y++) {
         if (board[i][y] == c)return false;
      }
      for (int x = 0;x < 3;x++) {
         for (int y = 0;y < 3;y++) {
            if (board[i - i % 3 + x][j - j % 3 + y] == c)return false;
         }
      }
      return true;
   }

   bool solvedSudoku(vector<vector<char>>& board, int i, int j) {
      if (i == 9)return true;
      if (j == 9)return solvedSudoku(board, i + 1, 0);
      if (board[i][j] != '.')return solvedSudoku(board, i, j+1);
      for (char c = '1';c <= '9';c++) {
         if (check(board, i, j, c)) {
            board[i][j] = c;
            if (solvedSudoku(board, i, j + 1))return true;
            board[i][j] = '.';
         }
      }
      return false;
   }
   void solveSudoku(vector<vector<char>>& board) {
      solvedSudoku(board, 0, 0);
   }
};