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
    ListNode *swapPairs(ListNode *head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while(true) {
            if(p->next && p->next->next) {
                ListNode* n0 = p->next;
                ListNode* n1 = p->next->next;
                ListNode* n2 = p->next->next->next;
                p->next = n1;
                n1->next = n0;
                n0->next = n2;
                p = n0;
            } else{
                break;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
