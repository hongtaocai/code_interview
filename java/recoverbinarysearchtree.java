/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    TreeNode lastNode;
    int flag;
    TreeNode node1;
    TreeNode node2;
    
    public void inorder(TreeNode root){
        if(root==null) return;
        inorder(root.left);
        if(root.val<lastNode.val){
            if(flag==0){
                node1 = lastNode;
                node2 = root;
            }else if(flag==1){
                node2 = root;
            }
            flag++;
        }
        lastNode = root;
        inorder(root.right);
    }
    
    public void recoverTree(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        lastNode = new TreeNode(Integer.MIN_VALUE);
        flag = 0;
        node1 = null;
        node2 = null;
        inorder(root);
        int tmp = node1.val;
        node1.val = node2.val;
        node2.val = tmp;
    }
}