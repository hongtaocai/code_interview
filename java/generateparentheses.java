public class Solution {
    
    private ArrayList<String> ans;
    private int n;
    
    private void gP(int left, int right, String tmp){
        if(left<right) return;
        if(left>n) return;
        if(right>n) return;
        
        if(left==n && right==n) ans.add(tmp);
        String tmp1 = tmp+"(";
        String tmp2 = tmp+")";
        gP(left+1,right,tmp1);
        gP(left,right+1,tmp2);
    }
    
    public ArrayList<String> generateParenthesis(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ans = new ArrayList<String>();
        this.n = n;
        gP(0,0,"");
        return ans;
    }
}