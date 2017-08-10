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

/*
另一种递归的写法：
*/

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}