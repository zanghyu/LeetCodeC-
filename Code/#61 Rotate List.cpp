/*
���⣺
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/*
˼·��
��Ҫע�����k>list����ʱ�Ĵ���ʽ���������ǰ���ȡ�෽ʽ��
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
   ListNode* rotateRight(ListNode* head, int k) {
      ListNode* p = head;
      int sum = 0;
      while (p) {
         sum++;
         p = p->next;
      }
      if (sum <= 1||k==0||k%sum==0)return head;
        k = k%sum;
      p = head;
      for (int i = 0;i < sum-k-1;i++) {
         p = p->next;
      }
      ListNode* res = p->next;
      p->next = NULL;
      p = res;
      for (int i = 0;i < k-1;i++) {
         p = p->next;
      }
      p->next = head;
      return res;
   }
};