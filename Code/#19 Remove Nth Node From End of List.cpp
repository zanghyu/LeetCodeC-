/*
问题：
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/*
思路：
简单的链表题
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
	ListNode* p = head;
	while (p != NULL) {
 	    p = p->next;
	    size++;
	}
	p = head->next;
	if (p == NULL)return NULL;
	if (n == size)return head->next;
	ListNode* pre = head;
	for (int i = 0;i < size - n - 1;i++) {
	    pre = pre->next;
	    p = p->next;
	}
	pre->next = p->next;
	return head;
    }
};