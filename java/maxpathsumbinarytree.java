public class Solution {
    class Bundle{
        public int tS;
        public int s;
        public int max;
        Bundle(int tS, int s, int max){
            this.tS = tS;
            this.s = s;
            this.max = max;
        }
        Bundle(){
            this.tS = this.s = this.max = Integer.MIN_VALUE;
        }
    }
    
    public Bundle maxPS(TreeNode root){
        if(root==null){
            return new Bundle();
        }
        Bundle res = new Bundle();
        Bundle left= new Bundle();
        Bundle right= new Bundle();
        if(root.left!=null){
            left = maxPS(root.left);
        }
        if(root.right!=null){
            right = maxPS(root.right);
        }
        res.tS = root.val;
        if(left.s>0) res.tS+= left.s;
        if(right.s>0) res.tS+= right.s;
        res.s = Math.max(Math.max(left.s,right.s),0)+root.val;
        res.max = Math.max(left.max,right.max);
        res.max = Math.max(res.max, res.tS);
        res.max = Math.max(res.max, res.s);
        
        return res;
    }
    
    public int maxPathSum(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        return maxPS(root).max;
        
        
    }
}