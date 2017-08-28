/*
问题：
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/*
思路：
用一个vector存最后所有路径，每次往下一层就是下一层的val+num*10
*/


class Solution {
public:
   int sumNumbers(TreeNode* root) {
      int Sum = 0;
      vector<int>res;
      sum(root, Sum, res);
      int tot = 0;
      for (int i = 0;i < res.size();i++) {
         tot += res[i];
      }
      return tot;
   }
   void sum(TreeNode* root, int& nowSum, vector<int>& res) {
      if (root) {
         nowSum = nowSum * 10 + root->val;
         if (root->left) {
            sum(root->left, nowSum, res);
         }
         if (root->right) {
            sum(root->right, nowSum, res);
         }
         if(!root->left && !root->right) {
            res.push_back(nowSum);
         }
         nowSum /= 10;
      }
      
   }
};