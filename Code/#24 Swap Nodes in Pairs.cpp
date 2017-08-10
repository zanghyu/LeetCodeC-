/*
问题：

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/*
思路：

两个节点互换，画个图仔细想一下就能懂了。
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
	if (head == NULL)return NULL;
	if (head->next == NULL)return head;
	ListNode* p = head;
	ListNode* q = head->next;
	ListNode* res = q;
	ListNode* last = new ListNode(0);
	while (q) {
	    p->next = q->next;
	    q->next = p;
	    last->next = q;
	    last = p;
	    p = p->next;
	    if (!p)break;
	    q = p->next;
	}
	return res;
    }
};

/*
下面这个是题解中的写法，感觉十分牛逼……
*/

ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}