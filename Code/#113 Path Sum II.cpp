/*
问题：
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

*/

/*
思路：
和#112一样，加上个DFS，到根节点时候加入到res里
*/


class Solution {
public:
   vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>>res;
           if(!root)return {};
      vector<int> tmp;
      int now = 0;
      generate(root, sum, now, res, tmp);
      return res;
   }
   void generate(TreeNode* root, int sum, int now,vector<vector<int>>& res, vector<int>& tmp) {
      if (sum == now + root->val && !root->left && !root->right) {
         tmp.push_back(root->val);
         res.push_back(tmp);
         tmp.pop_back();
         return;
      }
      if (root->left) {
         tmp.push_back(root->val);
         generate(root->left, sum, now + root->val, res, tmp);
         tmp.pop_back();
      }
      if (root->right) {
         tmp.push_back(root->val);
         generate(root->right, sum, now + root->val, res, tmp);
         tmp.pop_back();
      }
   }
};