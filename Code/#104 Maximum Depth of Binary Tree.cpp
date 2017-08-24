/*
问题：
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
思路：
一个简单的递归，没啥可说的
*/

class Solution {
public:
   int maxDepth(TreeNode* root) {
        if(!root)return 0;
      int maxd = 0;
      Depth(root, maxd, 1);
      return maxd;
   }
   void Depth(TreeNode* root, int& maxd, int this_d) {
      maxd = max(maxd, this_d);
      if (!root)return ;
      if (root->left) {
         Depth(root->left, maxd, this_d + 1);
      }
      if (root->right) {
         Depth(root->right, maxd, this_d + 1);
      }
   }
};