/*
���⣺
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

/*
˼·��
�����һ��λ�ò�����BST��ԭ����ô�͵ݹ�ĵ�����������Ҫ�ٵ���ʱ��������ͻָ����ˡ�
*/
class Solution {
public:
   void recoverTree(TreeNode* root) {
      int sum = 1;
      while (true) {
         Tree(root, sum);
         if (!sum)break;
         sum = 0;
      }
   }
   TreeNode* maxLeft(TreeNode* root) {
      if (root->left) {
         TreeNode* p = root->left;
         while (p->right != NULL) {
            p = p->right;
         }
         return p;
      }
      return root;
   }
   TreeNode* minRight(TreeNode* root) {
      if (root->right) {
         TreeNode* p = root->right;
         while (p->left != NULL) {
            p = p->left;
         }
         return p;
      }
      return root;
   }
   void Tree(TreeNode* root,int& sum) {
      if (root->left) {
         Tree(root->left,sum);

         if (maxLeft(root)->val > root->val) {
            sum++;
            int tmp = maxLeft(root)->val;
            maxLeft(root)->val = root->val;
            root->val = tmp;
         }
      }
      if (root->right) {
         Tree(root->right,sum);
         if (minRight(root)->val < root->val) {
            sum++;
            int tmp = minRight(root)->val;
            minRight(root)->val = root->val;
            root->val = tmp;
         }
      }
   }
};