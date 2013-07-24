class Solution {
public:
    class RB{
    public :
        bool isB;
        int h;
    };

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isBalanced1(root).isB;
    }
    
    RB isBalanced1(TreeNode *root){
        if(root==NULL){
            RB rb;
            rb.isB = true;
            rb.h = 0;
            return rb;
        }
        RB rb1 = isBalanced1(root->left);
        RB rb2 = isBalanced1(root->right);
        RB rb;
        rb.isB = rb1.isB && rb2.isB && (rb1.h-rb2.h)<=1 && rb1.h-rb2.h >= -1 ;
        
        rb.h = rb1.h > rb2.h ? rb1.h : rb2.h;
        rb.h ++;
        return rb;
        
    }
};