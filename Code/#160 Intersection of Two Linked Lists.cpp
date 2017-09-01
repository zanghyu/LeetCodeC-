/*
���⣺
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/*
˼·��
���������������ͬ�Ļ�����ô��Ӧ��һ��������ȥ�����ҵ�������ֻ��Ҫ�ѳ������̼��ɡ������㷨Ϊ���ֱ�������������õ��ֱ��Ӧ�ĳ��ȡ�Ȼ���󳤶ȵĲ�ֵ���ѽϳ����Ǹ���������ƶ������ֵ�ĸ�����Ȼ��һһ�Ƚϼ��ɡ�

*/

class Solution {
public:
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (!headA || !headB)return NULL;
      int len1 = 0, len2 = 0;
      ListNode* p = headA;
      ListNode* q = headB;
      while (p) {
         p = p->next;
         len1++;
      }
      while (q) {
         q = q->next;
         len2++;
      }
      int diff = 0;
      ListNode* tmp1;
      ListNode* tmp2;
      if (len1 > len2) {
         diff = len1 - len2;
         tmp1 = headA;
         tmp2 = headB;
      }
      else {
         diff = len2 - len1;
         tmp1 = headB;
         tmp2 = headA;
      }
      for(int i = 0;i<diff;i++) {
         tmp1 = tmp1->next;
      }
      while (tmp1) {
         if (tmp1 == tmp2)return tmp1;
         tmp1 = tmp1->next;
         tmp2 = tmp2->next;
      }
      return NULL;
   }
};