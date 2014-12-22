/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root) {
            root->next = NULL;
        }
        connect1(root);
    }
    
    void connect1(TreeLinkNode *root) {
        if(root==NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL) {
            return;
        }
        TreeLinkNode* next = root->next;
        while(next!=NULL) {
            if(next->left!=NULL || next->right!=NULL) {
                break;
            }
            next = next->next;
        }
        if(next!=NULL) {
            if(next->left!=NULL) {
                next = next->left;
            }else if(next->right){
                next = next->right;
            }
        }
        if(root->left!=NULL && root->right!=NULL) {
            root->left->next = root->right;
            root->right->next = next;
            connect1(root->right);
            connect1(root->left);
            return;
        }
        if(root->left!=NULL) {
            root->left->next = next;
            connect1(root->left);
            return;
        }
        if(root->right!=NULL) {
            root->right->next = next;
            connect1(root->right);
            return;
        }
        return;
    }
};
