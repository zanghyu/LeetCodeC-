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
	ListNode* reverse(ListNode* head,ListNode* tail) {
		ListNode* p = head;
		ListNode* q = head->next;
		ListNode* tmp = p;
		ListNode* end = tail->next;
		while (q!=NULL&&q!=end) {
			p->next = q->next;		
			q->next = tmp;
			tmp = q;
			q = p->next;
		}
		return tmp;
	}
	ListNode* reverseKGroup(ListNode* head,int n) {
		if (head == NULL)return NULL;
		if (head->next == NULL)return head;
		ListNode* p = head;
		ListNode* q = p;
		for (int i = 1;i < n;i++) {
			if (q == NULL)break;
			q = q->next;
		}
		if (q == NULL || n == 1)return head;
		ListNode* res = q;
		ListNode* last = new ListNode(0);

		while (q) {
			if (q != NULL)q = reverse(p, q);
			else q = reverse(p, NULL);
			
			last->next = q;
			last = p;
			p = p->next;
			if (!p)break;
			q = p->next;
			for (int i = 2;i < n;i++) {
				if (q == NULL)break;
				q = q->next;
			}
		}
		return res;
	}
};