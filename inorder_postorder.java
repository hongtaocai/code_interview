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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(inorder.length==0 || postorder.length==0) return null;
        
        int middle = postorder[postorder.length-1];
        int index = -1;
        for(int i=0;i<inorder.length;i++){
            if(inorder[i]==middle){
                index = i;
                break;
            }
        }
        TreeNode left = buildTree(Arrays.copyOfRange(inorder,0,index), Arrays.copyOfRange(postorder,0,index));
        TreeNode right = buildTree(Arrays.copyOfRange(inorder,index+1,inorder.length), Arrays.copyOfRange(postorder,index,postorder.length-1));
        TreeNode current = new TreeNode(middle);
        current.left = left;
        current.right = right;
        return current;
    }
}