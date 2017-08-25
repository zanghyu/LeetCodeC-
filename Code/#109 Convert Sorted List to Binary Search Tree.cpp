/*
问题：
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
思路：
这道题和#108一样，只不过链表没法直接读中间的那个节点。
*/

class Solution {
public:
   TreeNode* sortedListToBST(ListNode* head) {
      int num = 0;
      ListNode* p = head;
      while (p) { p = p->next, num++; }
      return getBST(head, 0, num-1);
   }
   TreeNode* getBST(ListNode* head, int beg, int end) {
      if (beg > end)return NULL;
      ListNode* p = head;
      for (int k = 0; k < (beg+end)/2;k++) {
         p = p->next;
      }
      TreeNode* root = new TreeNode(p->val);
      root->left = getBST(head, beg, (beg + end) / 2 - 1);
      root->right = getBST(head, (beg + end) / 2 + 1, end);
      return root;
   }
};