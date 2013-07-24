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
    int last =Integer.MIN_VALUE;
    
    public boolean help(TreeNode root){
        
        if(root==null) return true;
        if(!help(root.left)) return false;
        if(last>=root.val) return false;
        last = root.val;
        if(!help(root.right)) return false;
        return true;
    }
    
    public boolean isValidBST(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        last =Integer.MIN_VALUE;
        return help(root);
    }
}