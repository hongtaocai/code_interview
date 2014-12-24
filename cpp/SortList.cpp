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
    
    void merge(ListNode *pd1, ListNode *pd2, ListNode*& pstart, ListNode *tail) {
        ListNode* p1 = pd1->next;
        ListNode* p2 = pd2->next;
        while(p1 || p2) {
            if(p1 && p2) {
                if(p1->val < p2->val) {
                    pstart->next = p1;
                    p1 = p1->next;
                } else {
                    pstart->next = p2;
                    p2 = p2->next;
                }
                pstart = pstart->next;
            }
            else if(p1) {
                pstart->next = p1;
                p1 = p1->next;
                pstart = pstart->next;
            } else if(p2) {
                pstart->next = p2;
                p2 = p2->next;
                pstart = pstart->next;
            }
            
        }
        pd1->next = NULL;
        pd2->next = NULL;
        //pstart->next = tail;
    }
    
    ListNode *sortList(ListNode *head) {
        ListNode dummy(0);
        ListNode* pd = &dummy;
        pd->next = head;
        
        ListNode dummy1(1);
        ListNode* pd1 = &dummy1;
        ListNode dummy2(2);
        ListNode* pd2 = &dummy2;
        
        for(int interval=1;;interval <<=1) {
            ListNode* pstart = pd;
            ListNode* p = pd->next;
            ListNode* ppre = NULL;
            bool firstRound = false;
            
            while(true) {
                //cout << "interval:" << interval << endl;
                pd1->next = p;
                ppre = pd1;
                for(int i=0;i<interval;i++) {
                    if(p==NULL) {
                        break;
                    }
                    ppre = p;
                    p = p->next;
                }
                if(ppre)
                    ppre->next = NULL;
                //cout << p->val << endl;
                
                pd2->next = p;
                ppre = pd2;
                for(int i=0;i<interval;i++) {
                    if(p==NULL) {
                        break;
                    }
                    ppre = p;
                    p = p->next;
                }
                if(ppre)
                    ppre->next = NULL;
                
                //cout << p->val << endl;
                // merge pd1->... and pd2->... to pd1->...->p, move pstart forward
                merge(pd1, pd2, pstart, p);
                if(p==NULL) {
                    break;
                }
                firstRound = true;
            }
            if(!firstRound) {
                break;
            }
        }
        return pd->next;
    }
};
