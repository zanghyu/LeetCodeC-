/*
���⣺
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/*
˼·��
���Ҫcopyһ������random pointer��list����Ҫ����������п������randomָ���λ�û�û�б�copy�������Խ���������Ƕ��ɨ��list��
����Ȱ��ո���һ����������ķ�ʽ���ƣ����Ƶ�ʱ��Ѹ��ƵĽ����һ��HashMap���Ծɽ��Ϊkey���½ڵ�Ϊvalue����ô����Ŀ����Ϊ�˵ڶ���ɨ���ʱ�����ǰ��������ϣ��ѽ������ָ����ϡ�
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