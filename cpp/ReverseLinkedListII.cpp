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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode t(0);
        ListNode* dummy = &t;
        dummy->next = head;
        ListNode* n1 = dummy;
        ListNode* n2 = head;
        ListNode* n3 = head->next;
        m--;
        while(m--) {
            n1 = n2;
            n2 = n3;
            n3 = n3->next;
            n--;
        }
        ListNode* reverseBefore = n1;
        ListNode* reverseStart = n2;
        while(n--) {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if(n3) {
                n3 = n3->next;
            }
        }
        reverseBefore->next = n1;
        reverseStart->next = n2;
        return dummy->next;
    }
};
