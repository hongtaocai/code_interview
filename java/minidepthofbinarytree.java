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
    public int minDepth(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null){
            return 0;
        }
        Queue<TreeNode> now = new LinkedList<TreeNode>();
        Queue<TreeNode> next = new LinkedList<TreeNode>();
        int layer = 0;
        now.offer(root);
        while(!now.isEmpty() || !next.isEmpty()){
            while(!now.isEmpty()){
                TreeNode tn = now.poll();
                if(tn.left!=null) next.offer(tn.left);
                if(tn.right!=null) next.offer(tn.right);
                if(tn.left==null && tn.right==null) return layer+1;
            }
            if(!next.isEmpty()){
                Queue<TreeNode> tmp = now;
                now = next;
                next = tmp;
            }
            layer++;
        }
        return layer;
    }
}