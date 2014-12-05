/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; left = null; right = null; }
 * }
 */
public class Solution {
    
    public ArrayList<TreeNode> g(int left, int right){
        ArrayList<TreeNode> ans = new ArrayList<TreeNode>();
        if(left>right){
            ans.add(null);
            return ans;
        }
        if(left==right){
            ans.add(new TreeNode(left));
            return ans;
        }
        for(int i=left;i<=right;i++){
            ArrayList<TreeNode> tleft = g(left,i-1);
            ArrayList<TreeNode> tright = g(i+1,right);
            for( TreeNode nl : tleft ){
                for( TreeNode nr : tright){
                    TreeNode tn = new TreeNode(i);
                    tn.left = nl;
                    tn.right = nr;
                    ans.add(tn);
                }
            }
        }
        
        return ans;
    }
    
    
    public ArrayList<TreeNode> generateTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return g(1,n);
    }
}