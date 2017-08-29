/*
���⣺
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
˼·��
��Ŀ˵�����õݹ顣ǰ������������ҡ�

���ȸ����ݹ�ⷨ���£�
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
��Ȼ�����õݹ飬��ô���Ǿ���ջ���洢һ�½ڵ�
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