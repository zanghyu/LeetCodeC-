/*
问题：
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
思路：
用两个链表存储，一个链表是高位的，一个链表是低位的，然后再合并两个链表就行了。
*/

class Solution {
public:
   ListNode* partition(ListNode* head, int x) {
      ListNode* high = new ListNode(0);
      ListNode* low = new ListNode(0);
      ListNode* h = high;
      ListNode* l = low;
      ListNode* p = head;
      while (p) {
         if (p->val >= x) {
            h->next = p;
            h = h->next;
         }
         else {
            l->next = p;
            l = l->next;
         }
         p = p->next;
      }
      l->next = high->next;
      h->next = NULL;
      return low->next;
   }
};