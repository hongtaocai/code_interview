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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > solutions;
        vector<int> s;
        helper(root, sum, solutions, s);
        return solutions;
    }
    
    void helper(TreeNode *root, int sum, vector<vector<int> >& solutions, vector<int>& s) {
        if(root==NULL) {
            return;
        }
        s.push_back(root->val);
        if(root->left == NULL && root->right== NULL) {
            if(sum==root->val) {
                solutions.push_back(s);
            }
        }
        else if(root->left == NULL) {
            helper(root->right, sum-root->val, solutions, s);
        }
        else if(root->right == NULL) {
            helper(root->left, sum-root->val, solutions, s);
        }
        else {
            helper(root->left, sum-root->val, solutions, s);
            helper(root->right, sum-root->val, solutions, s);
        }
        s.pop_back();
    }
};
