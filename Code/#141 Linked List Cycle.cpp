/*
问题：
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
思路：
设置两个指针，一个每次走一步，一个每次走两步。只要有循环，那么他们两个一定会相遇。
*/

class Solution {
public:
   bool hasCycle(ListNode *head) {
      if (!head || !head->next)return false;
      ListNode* p = head;
      ListNode* q = head;
      while (q&&q->next) {
         p = p->next;
         q = q->next->next;
         if (p == q)return true;
      }
      return false;
   }
};