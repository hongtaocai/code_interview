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
    public TreeNode sortedArrayToBST(int[] num, int start, int end){
        if(num==null || num.length==0 || start>end){
            return null;
        }
        
        if(start==end){
            TreeNode tn = new TreeNode(num[start]);
            tn.left = null;
            tn.right = null;
            return tn;
        }
        int mid = start + (end-start)/2;
        TreeNode tn = new TreeNode(num[mid]);
            tn.left = sortedArrayToBST(num,start,mid-1);
            tn.right =  sortedArrayToBST(num,mid+1,end);
            return tn;
    }
    
    
    public TreeNode sortedArrayToBST(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return sortedArrayToBST(num,0,num.length-1);
    }
}