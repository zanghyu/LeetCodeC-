/*
���⣺
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/*
˼·��
��#141���ƣ��������������ѭ����ʼ�ĵط�������ͼ�Ϳ�֪������ʼ�㵽ѭ����ʼλ�õľ������������������λ�õ�ѭ����ʼλ�õľ��롣�������͵���Ŀ�����Բο����ͣ�
http://www.cnblogs.com/hiddenfox/p/3408931.html

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};