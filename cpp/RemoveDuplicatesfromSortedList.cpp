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
        ListNode* q = head;
        int last = head->val;
        ListNode* p = head->next;
        while(p!=NULL) {
            if(p->val == last) {
                p = p->next;
            } else {
                last = p->val;
                q->next = p;
                q = q->next;
                p = p->next;
            }
        }
        q->next = NULL;
        return head;
    }
};
