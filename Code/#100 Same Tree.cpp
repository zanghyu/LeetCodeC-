/*
问题：
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/*
思路：
一个简单的递归
*/

class Solution {
public:
   bool isSameTree(TreeNode* p, TreeNode* q) {
      if (!p && !q)return true;
      if ((!p&&q) || (!q&&p))return false;
      if (!(p->val == q->val))return false;
      if (!isSameTree(p->left, q->left))return false;
      if (!isSameTree(p->right, q->right))return false;
      return true;
   }
};