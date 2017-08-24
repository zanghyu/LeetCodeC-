/*
问题：
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/*
思路：
这道题和#100基本差不多，把#100的比较同侧改成比较异侧就行了
*/

class Solution {
public:
   bool compare(TreeNode* p, TreeNode* q) {
      if (!p && !q)return true;
      if ((!p&&q) || (!q&&p))return false;
      if (!(p->val == q->val))return false;
      if (!compare(p->left, q->right))return false;
      if (!compare(p->right, q->left))return false;
      return true;
   }
   bool isSymmetric(TreeNode* root) {
      if (!root)return true;
      return compare(root, root);
   }
};