/*
问题：
Sort a linked list in O(n log n) time using constant space complexity.
*/

/*
思路：
题目中要求nlgn的时间，因此只考虑归并排序和快速排序两种。
这里给出归并排序。
*/

class Solution {
public:
   ListNode* merge(ListNode* h1, ListNode* h2) {
      if (!h1)return h2;
      if (!h2)return h1;
      if (h1->val < h2->val) {
         h1->next = merge(h1->next, h2);
         return h1;
      }
      else {
         h2->next = merge(h1, h2->next);
         return h2;
      }
   }
   ListNode* sortList(ListNode* head) {
      if (!head)return NULL;
      if (!head->next)return head;
      ListNode* pre = head;
      ListNode* mid = head;
      ListNode* tail = head;
      while (tail&&tail->next) {
         pre = mid;
         mid = mid->next;
         tail = tail->next->next;
      }
      pre->next = NULL;
      ListNode* h1 = sortList(head);
      ListNode* h2 = sortList(mid);
      return merge(h1, h2);
   }
};