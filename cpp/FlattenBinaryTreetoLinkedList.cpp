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

    TreeNode* last;
    void flatten(TreeNode *root) {
        if(root==NULL) {
            return;
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(last) {
            last->right = root;
            last->left = NULL;
        }
        last = root;
        if(left) {
            flatten(left);
        }
        if(right) {
            flatten(right);
        }
    }
};
