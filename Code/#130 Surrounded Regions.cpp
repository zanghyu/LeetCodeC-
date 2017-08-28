/*
问题：
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

/*
思路：
这道题告诉我们一个道理，有些时候正向思维困难的时候可以试一下逆向思维。这道题我们要考虑的是O没有被包围的情况。
O没有被包围：即O在边界上开始往中心延伸。若没有被包围则必定这一段上的O最后能到达边界。因此我们先把这部分的O置为'1'，然后把剩下的O都改为X，然后再把这些'1'改回成O
*/

class Solution {
public:
   void solve(vector<vector<char>>& board) {
      if (board.empty())return;
      int row = board.size();
      int colomn = board[0].size();
      for (int i = 0;i < row;i++) {
         check(board,i,0);
         check(board, i, colomn - 1);
      }
      for (int j = 0;j < colomn;j++) {
         check(board, 0, j);
         check(board, row - 1, j);
      }
      for (int i = 0;i < row;i++) {
         for (int j = 0;j < colomn;j++) {
            if (board[i][j] == 'O') {
               board[i][j] = 'X';
            }
            if (board[i][j] == '1') {
               board[i][j] = 'O';
            }
         }
      }
   }
   void check(vector<vector<char>>& board, int i, int j) {
      if (board[i][j] == 'O') {
         board[i][j] = '1';
            if(i+1<board.size())check(board, i + 1, j);
         if(i-1>-1)check(board, i - 1, j);
         if(j+1<board[0].size())check(board, i, j + 1);
         if(j-1>-1)check(board, i, j - 1);
      }
   }
};

