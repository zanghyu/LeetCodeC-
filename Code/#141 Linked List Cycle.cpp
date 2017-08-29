/*
���⣺
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
˼·��
��������ָ�룬һ��ÿ����һ����һ��ÿ����������ֻҪ��ѭ������ô��������һ����������
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