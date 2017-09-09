/*
问题：

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/*
思路：

两个节点互换，就是一个简单递归。
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
	ListNode* swapPairs(ListNode* head) {
		ListNode* p1 = head;
		if (p1 == NULL)return head;
		ListNode* p2 = head->next;
		if (p2 == NULL)return head;
		p1->next = swapPairs(p2->next);
		p2->next = p1;
		return p2;
	}
};