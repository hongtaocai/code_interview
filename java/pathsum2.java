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
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null) return new ArrayList<ArrayList<Integer>>();
        if(root.left==null && root.right==null && sum == root.val) {
            ArrayList<Integer> k = new ArrayList<Integer>();
            k.add(root.val);
            ArrayList<ArrayList<Integer>> kk  = new ArrayList<ArrayList<Integer>>();
            kk.add(k);
            return kk;
        }
        ArrayList<ArrayList<Integer>> res1 = pathSum(root.left,sum-root.val);
        ArrayList<ArrayList<Integer>> res2 = pathSum(root.right,sum-root.val);
        
        res1.addAll(res2);
        
        for(ArrayList<Integer> e : res1 ){
            e.add(0,root.val);
        }
        
        return res1;
        
    }
}