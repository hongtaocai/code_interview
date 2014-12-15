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
    int BREAK_LINE = -0xffff;

    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) {
            return res;
        }
        TreeNode* nextVec = new TreeNode(BREAK_LINE);
        list<TreeNode*> q;
        q.push_back(root);
        q.push_back(nextVec);
        vector<int> thisline;
        
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop_front();
            if(top->val == BREAK_LINE) {
                res.push_back(thisline);
                thisline.clear();
                if(q.empty()) {
                    return res;
                }
                q.push_back(nextVec);
                continue;
            }
            thisline.push_back(top->val);
            if(top->left!=NULL) {
                q.push_back(top->left);
            }
            if(top->right!=NULL) {
                q.push_back(top->right);
            }
        }
        return res;
    }
};
