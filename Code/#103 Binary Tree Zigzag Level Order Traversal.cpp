/*
问题：
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/*
思路：
和#102一样，只不过每次扫完一行之后要根据它的行数来判断需不需要反转
*/


class Solution {
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (!root)return res;
      queue<TreeNode*> q;
      q.push(root);
      int num = 0;
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
         if (num % 2) {
            reverse(now.begin(), now.end());
         }
         res.push_back(now);
         num++;
      }
      return res;
   }
};