/*
问题：
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
思路：
所谓二叉搜索树，是一种始终满足左<根<右的特性，如果将二叉搜索树按中序遍历的话，得到的就是一个有序数组了。那么反过来，我们可以得知，根节点应该是有序数组的中间点，从中间点分开为左右两个有序数组，在分别找出其中间点作为原中间点的左右两个子节点，这不就是是二分查找法的核心思想么。
*/

class Solution {
public:
   TreeNode* sortedArrayToBST(vector<int>& nums) {
      return getBST(nums, 0, nums.size()-1);
   }
   TreeNode* getBST(vector<int>& nums, int beg, int end) {
      if (beg > end)return NULL;
      TreeNode* root = new TreeNode(nums[(beg + end) / 2]);
      root->left = getBST(nums, beg, (beg + end) / 2 - 1);
      root->right = getBST(nums, (beg + end) / 2 + 1, end);
      return root;
   }
};