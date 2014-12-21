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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, (int)inorder.size()-1, 0);
    }
    
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder, int a1, int b1, int a2) {
        if(a1>b1) {
            return NULL;
        }
        if(a1==b1) {
            return new TreeNode(inorder[a1]);
        }
        int b2 = b1-a1+a2;
        int midV = postorder[b2];
        int midIndex = a1;
        for(midIndex = a1; midIndex <= b1; midIndex++) {
            if(inorder[midIndex] == midV) {
                break;
            }
        }
        TreeNode* midNode = new TreeNode(midV);
        TreeNode* left = buildTree(inorder, postorder, a1, midIndex-1, a2);
        TreeNode* right = buildTree(inorder, postorder, midIndex+1, b1, a2+(midIndex-a1));
        midNode->left = left;
        midNode->right = right;
        return midNode;
    }
};
