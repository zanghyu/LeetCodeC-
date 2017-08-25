/*
���⣺
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
˼·��
��ν��������������һ��ʼ��������<��<�ҵ����ԣ��������������������������Ļ����õ��ľ���һ�����������ˡ���ô�����������ǿ��Ե�֪�����ڵ�Ӧ��������������м�㣬���м��ֿ�Ϊ���������������飬�ڷֱ��ҳ����м����Ϊԭ�м������������ӽڵ㣬�ⲻ�����Ƕ��ֲ��ҷ��ĺ���˼��ô��
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