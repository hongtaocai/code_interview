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
    ListNode *insertionSortList(ListNode *head) {
        if(!head) {
            return head;
        }
        ListNode dummy(0);
        ListNode* dummyp = &dummy;
        dummyp->next = head;
        ListNode* p = dummyp->next;
        while(p) {
            ListNode* node = p->next;
            if(!node) {
                break;
            }
            if(node->val >= p->val) {
                p = p->next;
            } else {
                ListNode* t = dummyp;
                while(t->next->val < node->val) {
                    t = t->next;
                }
                p->next = node->next;
                node->next = t->next;
                t->next = node;
            }
        }
        return dummyp->next;
    }
};
