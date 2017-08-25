/*
问题：
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/*
思路：
和#105一样，只不过这个是从后序的最后一个开始查。
*/

class Solution {
public:
   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if (postorder.size() == 0)return NULL;
      int i = 1;
      return construct(postorder, i, inorder, 0, inorder.size());

   }
   TreeNode* construct(vector<int>& postorder, int& i, vector<int>& inorder, int instart, int inend) {
      if (instart == inend)return NULL;
      TreeNode* root = new TreeNode(postorder[postorder.size() - i]);
      i = i + 1;
      for (int k = instart;k < inend;k++) {
         if (i == 0)return root;
         if (inorder[k] == postorder[postorder.size()-i+1]) {
            root->right = construct(postorder, i, inorder, k + 1, inend);
            root->left = construct(postorder, i, inorder, instart, k);
            break;
         }
      }
      return root;
   }
};