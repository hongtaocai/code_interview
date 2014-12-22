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
    int maxPathSum(TreeNode *root) {
        int maxSumGlobal = INT_MIN;
        int maxSumCur = 0;
        maxPathSum(root, maxSumGlobal, maxSumCur);
        return maxSumGlobal;
    }
    
    void maxPathSum(TreeNode *root, int& maxSumGlobal, int& maxSumCur) {
        if(root==NULL) {
            maxSumCur = 0;
            return;
        }
        int maxSumCurLeft = 0;
        maxPathSum(root->left, maxSumGlobal, maxSumCurLeft);
        int maxSumCurRight = 0;
        maxPathSum(root->right, maxSumGlobal, maxSumCurRight);
        maxSumCur = max(maxSumCurLeft, maxSumCurRight) + root->val;
        maxSumCur = max(maxSumCur, root->val);
        maxSumGlobal = max(maxSumGlobal, maxSumCur);
        maxSumGlobal = max(maxSumGlobal, maxSumCurLeft+ maxSumCurRight+ root->val);
    }
};
