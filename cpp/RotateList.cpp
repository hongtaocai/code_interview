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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL) {
            return NULL;
        }
        int n = 0;
        
        ListNode* tail = head;
        while(tail->next!=NULL) {
            n++;
            tail = tail->next;
        }
        n++;
        k = k%n;
        if(k==0) {
            return head;
        }
        int t = n-k-1;
        ListNode* p = head;
        while(t--) {
            p = p->next;
        }
        ListNode* headNew = p->next;
        tail->next = head;
        p->next = NULL;
        return headNew;
    }
};
