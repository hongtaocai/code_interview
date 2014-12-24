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
    vector<int> postorderTraversal(TreeNode *root) {
        
        vector<int> res;
        if(!root) {
            return res;
        }
        stack<TreeNode* > s;
        s.push(root);
        TreeNode* child = root;
        while(!s.empty()) {
            TreeNode* top = s.top();
            if( (!top->left&&!top->right) || top->left == child || top->right == child) {
                res.push_back(top->val);
                child = top;
                s.pop();
                continue;
            }
            if(top->right)
                s.push(top->right);
            if(top->left)
                s.push(top->left);
            child=top;
        }
        return res;
    }
};
