/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* p = head;
        int n = 0;
        while(p!=NULL) {
            p = p->next;
            ++n;
        }
        ListNode* midNode = head;
        return helper(midNode, n);
    }
    
    TreeNode *helper(ListNode* & midNode, int n) {
        if(n<=0) return NULL; 
        TreeNode* left = helper(midNode, n/2);
        TreeNode* t = new TreeNode(midNode->val);
        midNode = midNode->next;
        TreeNode* right = helper(midNode, n-1-n/2);
        t->left = left;
        t->right = right;
        return t;
    }
    
};
