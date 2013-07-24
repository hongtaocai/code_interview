public class Solution {
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        
        if(root==null) return arr;
        
        Queue<TreeNode> qc = new LinkedList<TreeNode>();
        Queue<TreeNode> qn = new LinkedList<TreeNode>();
        ArrayList<Integer> al = new ArrayList<Integer>();
        qn.offer(root);
        
        TreeNode c;
        
        while(true){
            if(qc.isEmpty() && qn.isEmpty()){
                if(al.size()!=0){
                    arr.add(new ArrayList<Integer>(al));
                    al.clear();
                }
                break;
            }
            if(qc.isEmpty()){
                Queue<TreeNode> tmp = qc;
                qc = qn;
                qn = tmp;
                if(al.size()!=0){
                    arr.add(new ArrayList<Integer>(al));
                    al.clear();
                }
            }else{
                c = qc.poll();
                if(c.left!=null) qn.offer(c.left);
                if(c.right!=null) qn.offer(c.right);
                al.add(c.val);
            }
        }
        return arr;
    }
}