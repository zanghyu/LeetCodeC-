/*
���⣺
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
˼·��
������������һ��������Щʱ������˼ά���ѵ�ʱ�������һ������˼ά�����������Ҫ���ǵ���Oû�б���Χ�������
Oû�б���Χ����O�ڱ߽��Ͽ�ʼ���������졣��û�б���Χ��ض���һ���ϵ�O����ܵ���߽硣��������Ȱ��ⲿ�ֵ�O��Ϊ'1'��Ȼ���ʣ�µ�O����ΪX��Ȼ���ٰ���Щ'1'�Ļس�O
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

