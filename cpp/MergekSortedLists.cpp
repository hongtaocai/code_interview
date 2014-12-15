/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNodeWrapper{
    ListNode* node;
    int listIndex;
};

bool Compare(ListNodeWrapper lw1, ListNodeWrapper lw2)
{
    return lw1.node->val > lw2.node->val;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNodeWrapper, vector<ListNodeWrapper>, function<bool(ListNodeWrapper, ListNodeWrapper)>> pq(Compare);
        vector<int> indexes(lists.size());
        for(int i=0;i<lists.size();i++) {
            if(lists[i] == NULL) {
                continue;
            }
            ListNodeWrapper lw;
            lw.node = lists[i];
            lw.listIndex = i;
            pq.push(lw);
            lists[i] = lists[i]->next;
        }
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        while(!pq.empty()){
            ListNodeWrapper lw= pq.top();
            pq.pop();
            p->next = lw.node;
            p = p->next;
            if(lists[lw.listIndex] !=NULL) {
                ListNodeWrapper lw1;
                lw1.node = lists[lw.listIndex];
                lw1.listIndex = lw.listIndex;
                pq.push(lw1);
                lists[lw.listIndex] = lists[lw.listIndex]->next;
            }
            p->next = NULL;
        }
        return res->next;
    }
};
