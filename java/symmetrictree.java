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
    public boolean check(TreeNode left, TreeNode right){
        if(left==null && right==null) return true;
        if(left==null || right==null) return false;
        return left.val == right.val && check(left.left, right.right) && check(left.right, right.left);
        
    }
    
    public boolean isSymmetric(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null) return true;
        return check(root.left, root.right);
    }
}