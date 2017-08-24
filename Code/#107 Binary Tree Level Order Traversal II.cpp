/*
问题：
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/*
思路：
这道题和#102又是一样的，最后时候反转一下就好了

*/
class Solution {
public:
   vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
      reverse(res.begin(), res.end());
      return res;
   }
};