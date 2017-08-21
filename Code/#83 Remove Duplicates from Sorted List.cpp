/*
问题：
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/*
思路：
比较简单的一道题
*/

class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return head;
      ListNode* p = head->next;
      ListNode* pre = head;
      while (p != NULL) {
         if (p->val == pre->val) {
            pre->next = p->next;
            p = p->next;
         }
         else pre = pre->next;
         
      }
      return head;
   }
};