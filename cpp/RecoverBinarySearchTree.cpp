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
    void recoverTree(TreeNode *root) {
        TreeNode* last = NULL;
        vector<TreeNode*> disorder;
        recoverTree(root, last, disorder);
        if(disorder.size()==4) {
            int tmp = disorder[0]->val;
            disorder[0]->val = disorder[3]->val;
            disorder[3]->val = tmp;
        }
        if(disorder.size()==2) {
            int tmp = disorder[0]->val;
            disorder[0]->val = disorder[1]->val;
            disorder[1]->val = tmp;
        }
    }
    
    void recoverTree(TreeNode* root, TreeNode*& last, vector<TreeNode*>& disorder) {
        if(root==NULL) return;
        TreeNode* current = root;
        TreeNode* pre = root->left;
        while(current) {
            if(current->left == NULL) {
                visit(current, last, disorder);
                current = current->right;
            } else {
                pre = current->left;
                while(pre->right!=NULL && pre->right!=current) {
                    pre = pre->right;
                }
                if(pre->right==NULL) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = NULL;
                    visit(current, last, disorder);
                    current = current->right;
                }
            }
        }
    }
    
    void visit(TreeNode*& root, TreeNode*& last, vector<TreeNode*>& disorder) {
        if(last && root->val < last->val) {
            disorder.push_back(last);
            disorder.push_back(root);
        }
        last = root;
    }
};
