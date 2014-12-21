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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode* > s;
        TreeNode* n = root; // rightChildOfMostLeftNode
        while(!s.empty() || n) {
            while(n) {
                s.push(n);
                n = n->left;
            }
            if(!s.empty()) {
                TreeNode* t = s.top();
                s.pop();
                res.push_back(t->val);
                n = t->right;
            }
        }
        return res;
    }
};
