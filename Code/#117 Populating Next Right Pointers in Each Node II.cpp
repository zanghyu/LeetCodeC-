/*
问题：
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/*
思路：
和上一道题基本相似，不过由于这道题中不是完全二叉树，因此需要先找到当前节点的右边节点的最左子节点。然后先右后左的递归。
*/

class Solution {
public:
   void connect(TreeLinkNode *root) {
      if (!root) return;
      TreeLinkNode* p = root->next;
      while (p) {
         if (p->left) {
            p = p->left;
            break;
         }
         if (p->right) {
            p = p->right;
            break;
         }
         p = p->next;
      }
      if (root->right) root->right->next = p;
      if (root->left) root->left->next = root->right?root->right:p;
      connect(root->right);
      connect(root->left);
   }
};