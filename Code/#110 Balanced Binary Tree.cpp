/*
问题：
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
思路：
需要计算一下深度，如果超过1就返回-1
*/

class Solution {
public:
   bool isBalanced(TreeNode* root) {
      if (getDepth(root) == -1)return false;
      return true;
   }
   int getDepth(TreeNode* root) {
      if (!root)return 0;
      int left = getDepth(root->left);
      if (left == -1)return -1;
      int right = getDepth(root->right);
      if (right == -1)return -1;
      int diff = abs(left - right);
      if (diff > 1)return -1;
      else return 1 + max(left, right);

   }
};