/*
问题：
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/*
思路：
很简单的合并链表题目
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* newList = new ListNode(0);
	ListNode* p = newList;
	while (l1 != NULL && l2 != NULL){
	    if (l1->val < l2->val) {
		p->next = new ListNode(l1->val);
		l1 = l1->next;
	    }
	    else {
		p->next = new ListNode(l2->val);
		l2 = l2->next;
	    }
            p = p->next;
	}
	p->next = l1?l1:l2;
	return newList->next;
    }
};