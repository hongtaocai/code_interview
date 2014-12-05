public class Solution {
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        TreeNode c=root;
        Stack<TreeNode> s = new Stack<TreeNode>();
        
        ArrayList<Integer> res = new ArrayList<Integer>();
        while( !s.empty() || c!=null ){
            if(c!=null){
                s.push(c);
                c = c.left;
            }
            else{
                c = s.pop();
                res.add(c.val);
                c = c.right;
            }
        } 
        return res;
    }
}