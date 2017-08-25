/*
问题：
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

/*
思路：
如果有一个位置不符合BST的原则，那么就递归的调整，当不需要再调整时，这个树就恢复好了。
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