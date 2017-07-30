/** 考察了一下链表的写法，主要是掌握了一种新的初始化结构体的方式
*   这道题目中定义struct中的初始化函数可以学一下
*   其次我自己写的代码耦合度太高，看起来既臃肿又不好看，在最后贴一个Solution中的简洁代码
*
*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
		ListNode* res = new ListNode((l1->val+l2->val)%10);
		ListNode* p = res;
		if (l1->val + l2->val >= 10)add = 1;
		l1 = l1->next;
		l2 = l2->next;
		for (;l1 != NULL ||l2 != NULL;) {
			if (l1 != NULL&&l2 != NULL) {
				p->next = new ListNode((l1->val + l2->val + add) % 10);
				if (l1->val + l2->val + add >= 10)add = 1;
				else add = 0;
				l1 = l1->next;
				l2 = l2->next;
				
			}
			else if (l1 != NULL) {
				p->next = new ListNode((l1->val + add) % 10);
				if (l1->val + add >= 10)add = 1;
				else add = 0;
				l1 = l1->next;
				
			}
			else if (l2 != NULL) {
				p->next = new ListNode((l2->val + add) % 10);
				if (l2->val + add >= 10)add = 1;
				else add = 0;
				l2 = l2->next;
				
			}
			p = p->next;
		}
		if (add ) {
			p->next = new ListNode(add);
		}
		return res;
        
    }
};

/*
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
*/