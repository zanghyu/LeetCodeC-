/*
问题：
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/*
思路：
如果要copy一个带有random pointer的list，主要的问题就是有可能这个random指向的位置还没有被copy到，所以解决方法都是多次扫描list。
因此先按照复制一个正常链表的方式复制，复制的时候把复制的结点做一个HashMap，以旧结点为key，新节点为value。这么做的目的是为了第二遍扫描的时候我们按照这个哈希表把结点的随机指针接上。
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *res = new RandomListNode(head->label);
        RandomListNode *node = res;
        RandomListNode *cur = head->next;
        map<RandomListNode*, RandomListNode*> m;
        m[head] = res;
        while (cur) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            node->next = tmp;
            m[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }
        node = res;
        cur = head;
        while (node) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }
};