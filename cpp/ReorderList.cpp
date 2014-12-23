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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next == NULL) {
            return;
        }
        ListNode* p = head;
        ListNode* q = head;
        while(true) {
            if(q->next==NULL ||q->next->next==NULL) {
                break;
            }
            q = q->next->next;
            p = p->next;
        }
        ListNode* mid = p;
        
        ListNode* p1 = NULL;
        ListNode* p2 = mid->next;
        ListNode* p3 = mid->next->next;
        mid->next = NULL;
        while(true) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p2==NULL) {
                break;
            }
            p3 = p3->next;
        }
        // merge p1 and head;
        p = head;
        q = p1;
        while(p&& q) {
            ListNode* nextp = p->next;
            ListNode* nextq = q->next;
            p->next = q;
            q->next = nextp;
            p = nextp;
            q = nextq;
        }
    }
};
