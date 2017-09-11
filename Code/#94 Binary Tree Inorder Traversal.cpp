/*
问题：
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
思路：
递归解法很简单：
一个简单的中序遍历，前根后
*/

class Solution {
public:
   vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      inorder(root, res);
      return res;
   }
   void inorder(TreeNode* root,vector<int> &res) {
      if (root) {
         inorder(root->left,res);
         res.push_back(root->val);
         inorder(root->right,res);
      }
   }
};

/*
但是由于这道题目说不用递归写法，所以我们使用栈来解。
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};