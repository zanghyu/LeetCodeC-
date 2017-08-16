/*
���⣺
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

����Sudoku�����ӣ�
http://sudoku.com.au/TheRules.aspx

*/

/*
˼·��
�������һ���򵥵ı������⣬���С��С��飬���α������ɵó������
*/

class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
      int colomn[9][9] = { 0 }, row[9][9] = { 0 }, block[9][9] = { 0 };
      for (int i = 0;i < board.size();i++) {
         for (int j = 0;j < board[i].size();j++) {
            if (board[i][j] != '.') {
               int num = board[i][j] - '1';
               int k = i / 3 * 3 + j / 3;
               if (colomn[i][num] || row[j][num] || block[k][num])
                  return false;
               colomn[i][num] = row[j][num] = block[k][num] = 1;
            }
         }
      }
      return true;
   }
};
