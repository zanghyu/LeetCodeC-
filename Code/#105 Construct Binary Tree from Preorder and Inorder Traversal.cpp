/*
问题：
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/*
思路：
根据前序和中序遍历构建出这个树，因为没有重复的数，所以前序的第一个一定是根节点，然后中序再查找下该节点，从该节点往两边分，构建左右子树。
*/

class Solution {
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.size() == 0)return NULL;
      int i = 0;
      return construct(preorder, i, inorder, 0, inorder.size());

   }
   TreeNode* construct(vector<int>& preorder, int& i, vector<int>& inorder, int instart, int inend) {
      if (instart == inend)return NULL;
      TreeNode* root = new TreeNode(preorder[i]);
      i = i + 1;
      for (int k = instart;k < inend;k++) {
         if (i == preorder.size())return root;
         if (inorder[k] == preorder[i-1]) {
            root->left = construct(preorder, i, inorder, instart, k);
            root->right = construct(preorder, i, inorder, k+1, inend);
            break;
         }
      }
      return root;
   }
};