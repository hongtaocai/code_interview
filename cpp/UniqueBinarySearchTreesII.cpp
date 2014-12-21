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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> v;
        generateTrees(1,n,v);
        return v;
    }
    
    void generateTrees(int start, int end, vector<TreeNode *>& trees) {
        if(start>end) {
            trees.push_back(NULL);
            return;
        }
        for(int i=start;i<=end;i++) {
            vector<TreeNode *> leftTrees;
            generateTrees(start, i-1, leftTrees);
            vector<TreeNode *> rightTrees;
            generateTrees(i+1, end, rightTrees);
            for(int j=0;j<leftTrees.size();j++) {
                for(int k=0;k<rightTrees.size();k++) {
                    TreeNode* t = new TreeNode(i);
                    t->left = leftTrees[j];
                    t->right = rightTrees[k];
                    trees.push_back(t);
                }
            }
        }
    }
};
