/*
问题：
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
思路：
和#144思路类似，用stack来存储

*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *head = root;
        while (!s.empty()) {
            TreeNode *top = s.top();
            if ((!top->left && !top->right) || top->left == head || top->right == head) {
                res.push_back(top->val);
                s.pop();
                head = top;
            } else {
                if (top->right) s.push(top->right);
                if (top->left) s.push(top->left);
            }
        }
        return res;
    }
};