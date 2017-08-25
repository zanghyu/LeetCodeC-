/*
问题：
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
思路：
和#96思路类似，可见博客
https://fisherlei.blogspot.jp/2013/03/leetcode-unique-binary-search-trees.html
https://fisherlei.blogspot.jp/2013/03/leetcode-unique-binary-search-trees-ii.html
*/

class Solution {
public:
   vector<TreeNode*> generateTrees(int n) {
      if (n == 0)return{};
      return *getSubTrees(1, n);
      
   }
   vector<TreeNode*>* getSubTrees(int start, int end) {
      vector<TreeNode*>* res = new vector<TreeNode*>();
      if (start > end)res->push_back(NULL);
      else {
         for (int i = start; i <= end;i++) {
            vector<TreeNode*>* leftTree = getSubTrees(start, i - 1);
            vector<TreeNode*>* rightTree = getSubTrees(i + 1, end);
            for (int j = 0;j < leftTree->size();j++) {
               for (int k = 0;k < rightTree->size();k++) {
                  TreeNode* node = new TreeNode(i);
                  node->left = (*leftTree)[j];
                  node->right = (*rightTree)[k];
                  res->push_back(node);
               }
            }
         }
      }
      return res;
   }
};