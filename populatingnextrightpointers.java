/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root==null) return;
        Queue<TreeLinkNode> now = new LinkedList<TreeLinkNode>();
        Queue<TreeLinkNode> next = new LinkedList<TreeLinkNode>();
        now.offer(root);
        while(!now.isEmpty() ){
            TreeLinkNode tmp = new TreeLinkNode(0);
            while(!now.isEmpty()){
                TreeLinkNode t = now.poll();
                tmp.next = t;
                tmp = tmp.next;
                if(tmp.left!=null && tmp.right!=null){
                    next.offer(tmp.left);
                    next.offer(tmp.right);
                }
            }
            Queue<TreeLinkNode> t = now;
            now = next;
            next = t;
        }
    }
}