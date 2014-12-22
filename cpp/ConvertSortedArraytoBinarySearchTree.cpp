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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, (int)num.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
        int n = end - start + 1;
        if(n==0) return NULL;
        int mid = (end-start)/2+ start;
        TreeNode* t = new TreeNode(num[mid]);
        t->left = sortedArrayToBST(num, start, mid-1);
        t->right = sortedArrayToBST(num, mid+1, end);
        return t;
    }
};
