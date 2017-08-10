/*
问题：
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/*
思路：
这道题直接用第一个和第二个合并，一直合并下去这种思路会TLE，时间复杂度太高。因此选择分治法。分治之后时间复杂度会减少很多。
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
		if (l1 == NULL &&l2 == NULL)return NULL;
		if (l1 == NULL)return l2;
		if (l2 == NULL)return l1;
		ListNode* newList = new ListNode(0);
		ListNode* p = newList;
		if (l1->val < l2->val) {
			newList->val = l1->val;
			l1 = l1->next;
		}
		else {
			newList->val = l2->val;
			l2 = l2->next;
		}
		while (l1 != NULL && l2 != NULL){
			if (l1->val < l2->val) {
				p->next = new ListNode(l1->val);
				l1 = l1->next;
				p = p->next;
			}
			else {
				p->next = new ListNode(l2->val);
				l2 = l2->next;
				p = p->next;
			}
		}
		if (l1 != NULL) {
			p->next = l1;
		}
		else p->next = l2;
		return newList;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)return NULL;
		if (lists.size() == 1)return lists[0];
		while (lists.size() > 1) {
			lists.push_back(mergeTwoLists(lists[0], lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists.front();
	}
};