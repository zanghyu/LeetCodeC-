/*
问题：
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/*
思路：
和#141类似，不过这道题是求循环开始的地方。画个图就可知道从起始点到循环开始位置的距离等于两个点相遇的位置到循环开始位置的距离。这种类型的题目都可以参考博客：
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