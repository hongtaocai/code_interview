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
    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null) return;
        if(root.left==null && root.right==null) return;
        
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        ArrayList<TreeNode> res = new ArrayList<TreeNode>();
        TreeNode last = root;
        while(!s.isEmpty()){
            TreeNode top = s.pop();
            if(top.right!=null) s.push(top.right);
            if(top.left!=null) s.push(top.left);
            last.right = top;
            last.left = null;
            last = top;
        }
        return;
    }
}