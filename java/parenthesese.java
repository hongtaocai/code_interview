public class Solution {
    
    public ArrayList<String> res = new ArrayList<String>();
    
    public void doit(int depth, int leftnum, int maxnum, String s){
        if(depth-leftnum>leftnum) return;
        if(leftnum*2==maxnum){
            StringBuilder k = new StringBuilder(s);
            for(int i=0;i<maxnum-depth;i++){
                k.append(")");
            }
            res.add(k.toString());
        }else{
            doit(depth+1,leftnum+1,maxnum,s+"(");
            doit(depth+1,leftnum,maxnum,s+")");
        }
        
        
    }
    
    public ArrayList<String> generateParenthesis(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        res.clear();
        doit(1,1,n*2,"(");
        return res;
    }
}