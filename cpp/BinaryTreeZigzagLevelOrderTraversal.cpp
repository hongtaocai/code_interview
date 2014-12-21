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

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) {
            return res;
        }
        vector<TreeNode*> vq;
        vector<TreeNode*> vnextq;
        vector<TreeNode*>* q = &vq;
        vector<TreeNode*>* nextq = &vnextq;
        q->push_back(root);
        
        bool flip = false;
        while(!q->empty()) {
            vector<int> line;
            for(int i=0;i<q->size();i++) {
                TreeNode* top = (*q)[i];
                line.push_back(top->val);
                if(top->left!=NULL) {
                    nextq->push_back(top->left);
                }
                if(top->right!=NULL) {
                    nextq->push_back(top->right);
                }
            }
            if(flip) {
                reverse(line.begin(), line.end());
            }
            flip = !flip;
            res.push_back(line);
            q->clear();
            vector<TreeNode*>* tmp = q;
            q = nextq;
            nextq = tmp;
        }
        return res;
    }
};
