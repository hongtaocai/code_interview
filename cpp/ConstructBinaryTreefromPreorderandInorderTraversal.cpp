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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        buildTree(preorder, inorder, 0, (int)preorder.size()-1, 0);
    }
    
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder, int a1, int b1, int a2) {
        if(a1>b1) {
            return NULL;
        }
        if(a1==b1) {
            return new TreeNode(preorder[a1]);
        }
        int b2 = b1-a1+a2;
        int midV = preorder[a1];
        int midIndex = a2;
        for(midIndex = a2; midIndex <= b2; midIndex++) {
            if(inorder[midIndex] == midV) {
                break;
            }
        }
        TreeNode* midNode = new TreeNode(midV);
        TreeNode* left = buildTree(preorder, inorder, a1+1, midIndex-a2+a1 , a2);
        TreeNode* right = buildTree(preorder, inorder, midIndex-a2+a1+1, b1, midIndex+1);
        midNode->left = left;
        midNode->right = right;
        return midNode;
    }
};
