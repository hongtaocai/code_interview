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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while(true) {
            bool haveValidKNodes = true;
            ListNode* q = p->next;
            for(int i=0;i<k;i++) {
                if(q==NULL) {
                    haveValidKNodes = false;
                    break;
                }
                q = q->next;
            }
            if(haveValidKNodes) {
                ListNode* n0 = p;
                ListNode* n1 = p->next;
                ListNode* n2 = p->next->next;
                ListNode* start = p->next;
                for(int i=0;i<k;i++) {
                    n1->next = n0;
                    n0 = n1;
                    n1 = n2;
                    if(n1!=NULL) {
                        n2 = n1->next;
                    }
                }
                start->next = n1;
                p->next = n0;
                p = start;
            } else{
                break;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
