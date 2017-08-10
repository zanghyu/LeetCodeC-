/*
���⣺

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/*
˼·��

�����ڵ㻥��������ͼ��ϸ��һ�¾��ܶ��ˡ�
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
�������������е�д�����о�ʮ��ţ�ơ���
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