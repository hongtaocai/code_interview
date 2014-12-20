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
    ListNode *partition(ListNode *head, int x) {
        ListNode* smaller = new ListNode(0);
        ListNode* pSmaller = smaller;
        ListNode* bigger = new ListNode(0);
        ListNode* pBigger = bigger;
        ListNode* p = NULL;
        while(head!=NULL) {
            p = head;
            head = head->next;
            p->next = NULL;
            
            if(p->val < x) {
                pSmaller->next = p;
                pSmaller = p;
            } else {
                pBigger->next = p;
                pBigger = p;
            }
        }
        pSmaller->next = bigger->next;
        
        ListNode* res = smaller->next;
        if(res == NULL) {
            res = bigger->next;
        }
        return res;
    }
};
