/*
问题：

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/

/*
思路：
和#24类似，都是反转单链表的操作。不过我在这里是写了一个反转从head到tail链表的函数，其他部分和#24一样

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
   ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* p = head;
      ListNode* pre = head;
      if (!p)return head;
      for (int i = 0;i < k-1;i++) {
         if(p->next)p = p->next;
         else return head;
      }
      pre = p;
      p = p->next;
      pre->next = NULL;
      reverse(head);
      head->next = reverseKGroup(p, k);
      return pre;
   }
   ListNode* reverse(ListNode* head) {
      if (!head)return head;
      ListNode* p1 = head;
      ListNode* p2 = head->next;
      if (!p2)return head;
      ListNode* newHead = head;
      while (p2) {
         p1->next = p2->next;
         p2->next = newHead;
         newHead = p2;
         p2 = p1->next;
      }
      return newHead;
   }
};