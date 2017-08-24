/*
问题：
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/*
思路：
也是个简单遍历，不过有个需要注意的是得到Sum时必须要是叶节点

*/

class Solution {
public:
   bool hasPathSum(TreeNode* root, int sum) {
      int now = 0;
      return Path(root, now, sum);
   }
   bool Path(TreeNode* root, int sum,int target) {
      if (root) {
         sum += root->val;
         if (sum == target && !root->left && !root->right)return true;
         if (Path(root->left, sum, target))return true;
         if (Path(root->right, sum, target))return true;
         return false;
      }
      return false;
   }
};