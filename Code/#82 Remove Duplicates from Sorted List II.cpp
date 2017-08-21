/*
���⣺
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/*
˼·��
��#83��࣬���ǲ�֮ͬ������#83����ֱ�Ӹ��£���������ΪֻҪ���ظ����־�Ҫɾ�������Բ�̫�ð���#83��˼·�����������ʺ��õݹ��д����ʵ�֡�
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        int val = head->val;
        ListNode* p = head->next;
        
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};