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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) {
            return false;
        }
        ListNode* p = head;
        ListNode* q = head;
        while(true) {
            if(q->next==NULL || q->next->next==NULL) {
                return NULL;
            }
            q = q->next->next;
            p = p->next;
            if(p==q) {
                p = head;
                while(p!=q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return NULL;
    }
};
