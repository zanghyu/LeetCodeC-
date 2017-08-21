/*
问题：
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
思路：
这道题相当于是dfs吧，和前两道题都有点像，因为一个字母不能重复出现，所以在递归前先标记一下出现的字母，递归之后把该位置清0就行了。
*/

class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
      vector<vector<int>> flag(board.size(), vector<int>(board[0].size()));
      for (int i = 0;i < board.size();i++) {
         for (int j = 0;j < board[0].size();j++) {
            if (board[i][j] == word[0]) {
               if (ok(board, i, j, word, 0, flag))return true;
                    if (word.size() == 1)return true;
            }
         }
      }
      return false;
   }
   bool ok(vector<vector<char>>& board, int row, int col, string word, int pos, vector<vector<int>> flag) {
      if (pos == word.size())return true;
      if (flag[row][col] == 1)return false;
      if (board[row][col] == word[pos]) {
         flag[row][col] = 1;
         if ((col + 1 < board[0].size()) && ok(board, row, col + 1, word, pos + 1, flag))return true;
         if ((col - 1 > -1) && ok(board, row, col - 1, word, pos + 1, flag))return true;
         if ((row + 1 < board.size()) && ok(board, row + 1, col, word, pos + 1, flag))return true;
         if ((row - 1 > -1) && ok(board, row - 1, col, word, pos + 1, flag))return true;
         flag[row][col] = 0;
      }
      return false;
   }
};