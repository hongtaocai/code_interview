public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null) return false;
        if(root.left==null && root.right==null && sum == root.val) return true;
        return hasPathSum(root.left,sum-root.val) || hasPathSum(root.right,sum-root.val);
    }
}