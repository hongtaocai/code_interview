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
    bool isBalanced(TreeNode *root) {
        int h = 0;
        return isBalanced(root, h);
    }
    
    bool isBalanced(TreeNode* root, int& height) {
        if(root==NULL) {
            height = 0;
            return true;
        }
        int heightLeft = 0;
        int heightRight = 0;
        bool isBLeft = isBalanced(root->left, heightLeft);
        bool isBRight = isBalanced(root->right, heightRight);
        height = 1+max(heightLeft, heightRight);
        return abs(heightLeft-heightRight)<=1 && isBLeft && isBRight;
    }
};
