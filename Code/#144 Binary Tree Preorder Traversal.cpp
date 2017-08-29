/*
问题：
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
思路：
题目说不能用递归。前序遍历，根左右。

首先给出递归解法如下：
*/

class Solution {
public:
   vector<int> preorderTraversal(TreeNode* root) {
      vector<int>res;
      if (!root)return res;
      preorder(root, res);
      return res;
   }
   void preorder(TreeNode* root, vector<int>& res) {
      if (root) {
         res.push_back(root->val);
         preorder(root->left, res);
         preorder(root->right, res);
      }
   }
};

/*
既然不能用递归，那么我们就用栈来存储一下节点
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (!root) return res;
        s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            res.push_back(p->val);
            s.pop();
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
        return res;
    }
};