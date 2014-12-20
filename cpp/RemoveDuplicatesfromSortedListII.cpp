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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* q = dummy;
        int last = head->val;
        int count = 1;
        ListNode* p = head->next;
        ListNode* pp = head;
        while(p!=NULL) {
            if(p->val == last) {
                count++;
            } else{
                if(count==1) {
                    q->next = pp;
                    q = q->next;
                }
                last = p->val;
                pp = p;
                count = 1;
            }
            p = p->next;
        }
        if(count==1) {
            q->next = pp;
            q = q->next;
        }
        q->next = NULL;
        return dummy->next;
    }
};
