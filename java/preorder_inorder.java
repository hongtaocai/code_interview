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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(inorder.length==0 || preorder.length==0) return null;
        
        int middle = preorder[0];
        int index = -1;
        for(int i=0;i<inorder.length;i++){
            if(inorder[i]==middle){
                index = i;
                break;
            }
        }
        TreeNode left = buildTree(Arrays.copyOfRange(preorder,1,index+1),Arrays.copyOfRange(inorder,0,index));
        TreeNode right = buildTree(Arrays.copyOfRange(preorder,index+1,preorder.length),Arrays.copyOfRange(inorder,index+1,inorder.length));
        TreeNode current = new TreeNode(middle);
        current.left = left;
        current.right = right;
        return current;
    }
}