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
    bool isSymmetric(TreeNode *root) {
        return !root || isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode *left, TreeNode* right) {
        if(!left && !right) {
            return true;
        }
        if(!left || !right) {
            return false;
        }
        return left->val == right->val
            && isMirror(left->left, right->right)
            && isMirror(left->right, right->left);
    }
};
