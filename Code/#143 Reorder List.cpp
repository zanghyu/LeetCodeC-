/*
问题：
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/

/*
思路：
又是一道递归的题，思路很简单
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   void reorderList(ListNode* head) {
      ListNode* p = head;
      if (!head)return;
      if (!p->next||!p->next->next)return;
      while (p->next&&p->next->next) {
         reorder(p);
         p = p->next->next;
      }
   }
   void reorder(ListNode* head) {
      ListNode* p = head;
      ListNode* prep = head;
      if (!p->next) {
         return;
      }
      while (p->next) {
         if (p != head)prep = prep->next;
         p = p->next;
      }
      p->next = head->next;
      head->next = p;
      prep->next = NULL;
   }
};