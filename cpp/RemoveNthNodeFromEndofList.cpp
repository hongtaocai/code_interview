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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while(n--) {
            p = p->next;
        }
        ListNode* q = dummy;
        while(p->next!=NULL) {
            q = q->next;
            p = p->next;
        }
        q->next = q->next->next;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
