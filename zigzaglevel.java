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
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
           ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        
        if(root==null) return arr;
        
        Stack<TreeNode> qc = new Stack<TreeNode>();
        Stack<TreeNode> qn = new Stack<TreeNode>();
        ArrayList<Integer> al = new ArrayList<Integer>();
        qn.push(root);
        
        TreeNode c;
        
        boolean zigzag = false;
        
        while(true){
            if(qc.isEmpty() && qn.isEmpty()){
                if(al.size()!=0){
                    arr.add(new ArrayList<Integer>(al));
                    al.clear();
                }
                break;
            }
            if(qc.isEmpty()){
                Stack<TreeNode> tmp = qc;
                qc = qn;
                qn = tmp;
                zigzag = !zigzag;
                if(al.size()!=0){
                    arr.add(new ArrayList<Integer>(al));
                    al.clear();
                }
            }else{
                c = qc.pop();
                if(zigzag){
                    if(c.left!=null) qn.push(c.left);
                    if(c.right!=null) qn.push(c.right);
                }
                else{
                    
                    if(c.right!=null) qn.push(c.right);
                    if(c.left!=null) qn.push(c.left);
                }
                al.add(c.val);
            }
        }
        return arr;
    
    }
}