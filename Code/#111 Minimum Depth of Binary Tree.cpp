/*
问题：
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/*
思路：
和#104思路基本一样
*/

class Solution {
public:
   int minDepth(TreeNode* root) {
      int mind = 1e8;
      if (!root)return 0;
      Depth(root, mind, 1);
      return mind;
   }
   void Depth(TreeNode* root, int& mind, int this_d) {
      if (!root)return ;
      if (!root->left&&!root->right)
         mind = min(mind, this_d);
      if (root->left) {
         Depth(root->left, mind, this_d + 1);
      }
      if (root->right) {
         Depth(root->right, mind, this_d + 1);
      }
   }
};