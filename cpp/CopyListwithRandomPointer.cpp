/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) {
            return NULL;
        }
        map<RandomListNode*, RandomListNode*> oldToNew;
        RandomListNode* p = head;
        while(p) {
            RandomListNode *q = new RandomListNode(p->label);
            oldToNew[p]=q;
            p = p->next;
        }
        p = head;
        while(p) {
            RandomListNode *q = oldToNew[p];
            q->next = oldToNew[p->next];
            q->random = oldToNew[p->random];
            p = p->next;
        }
        return oldToNew[head];
    }
};
