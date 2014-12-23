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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
    
    void sumNumbers(TreeNode *root, int number, int& sum) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL) {
            sum += (number*10 + root->val);
        }
        sumNumbers(root->left, number*10+root->val, sum);
        sumNumbers(root->right, number*10+root->val, sum);
    }
};
