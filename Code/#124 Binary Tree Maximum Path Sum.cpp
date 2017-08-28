/*
问题：
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/*
思路：
参考博客：
http://www.cnblogs.com/grandyang/p/4280120.html
*/

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = root->val;
        maxPathSumDFS(root, res);
        return res;
    }
    int maxPathSumDFS(TreeNode *root, int &res) {
        if (!root) return 0;
        int left = maxPathSumDFS(root->left, res);
        int right = maxPathSumDFS(root->right, res);
        int top = root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0);
        res = max(res, top);
        return max(left, right) > 0 ? max(left, right) + root->val : root->val; 
    }
};