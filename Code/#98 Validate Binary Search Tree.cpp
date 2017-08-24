/*
问题：
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

/*
思路：
二叉排序树的遍历，这道题重点在于每次递归时如何更新当前的min和max，以及如何设置初始值
*/

class Solution {
public:
   bool isValidBST(TreeNode* root) {
      return isValid(root, LONG_MIN, LLONG_MAX);
   }
   bool isValid(TreeNode* root, long Min, long Max) {
      if (!root)return true;
      if (Min >= root->val || Max <= root->val)return false;
      if (isValid(root->left,Min,root->val) && isValid(root->right,root->val,Max)) {
         return true;
      }
      return false;
   }
};