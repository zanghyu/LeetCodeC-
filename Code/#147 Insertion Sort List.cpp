/*
问题：
Sort a linked list using insertion sort.
*/

/*
思路：
就是个简单的插入排序
*/

class Solution {
public:
   ListNode* Insert(ListNode* newhead, ListNode* node) {
      ListNode* preNode = newhead;
      ListNode* p = newhead->next;
      int tmp = 0;
      if (newhead->val > node->val) {
         ListNode* New = new ListNode(node->val);
         New->next = newhead;
         return New;
      }
      else {
         while (p) {
            if (preNode->val <= node->val && p->val >= node->val) {
               preNode->next = new ListNode(node->val);
               preNode->next->next = p;
               tmp = 1;
               break;
            }
            preNode = p;
            p = p->next;
         }
         if (!tmp && preNode->val <= node->val) {
            preNode->next = new ListNode(node->val);
            preNode->next->next = NULL;
         }
      }
      return newhead;
   }
   ListNode* insertionSortList(ListNode* head) {
      if (!head)return NULL;
      ListNode* newHead = new ListNode(head->val);
      ListNode* p = head->next;
      while (p) {
         newHead = Insert(newHead, p);
         p = p->next;
      }
      return newHead;
   }
};