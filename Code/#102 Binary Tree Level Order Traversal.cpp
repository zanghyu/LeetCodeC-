/*
���⣺
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*
˼·��
������ǲ�α�������ʵ����BFS��BFSһ�㶼��Ҫ�õ����������б�����
*/

class Solution {
public:
   vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (!root)return res;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty()) {
         vector<int> now;
         int size = q.size();
         for (int i = 0;i < size;i++) {
            TreeNode* node = q.front();
            q.pop();
            now.push_back(node->val);
            if (node->left)q.push(node->left);
            if (node->right)q.push(node->right);
         }
         res.push_back(now);
      }
      return res;
   }
};