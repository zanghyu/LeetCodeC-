/*
���⣺
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/*
˼·��
����ǰ�������������������������Ϊû���ظ�����������ǰ��ĵ�һ��һ���Ǹ��ڵ㣬Ȼ�������ٲ����¸ýڵ㣬�Ӹýڵ������߷֣���������������
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