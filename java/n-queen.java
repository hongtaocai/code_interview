public class Solution {
    
    int res[];
    boolean colUsed[];
    ArrayList<String[]> resarray;
    
    
    public boolean check(int row,int col){
        for(int i=0;i<row;i++){
            if(Math.abs(row-i)==Math.abs(col-res[i])){
                return false;
            }
        }
        return true;
    }
    
    public void solvelayer(int n, int row){
        
        for(int i=0;i<n;i++){
            if(!colUsed[i] && check(row,i)){
                colUsed[i] = true;
                res[row] = i;
                if(row==n-1){
                    String[] ans = new String[n];
                    for(int i1=0;i1<n;i1++){
                        StringBuilder sb =new StringBuilder("");
                        for(int i2=0;i2<n;i2++){
                            if(i2!=res[i1]){
                                sb.append(".");
                            }else{
                                sb.append("Q");
                            }
                        }
                        ans[i1] = sb.toString();
                    }
                    resarray.add(ans);
                }else{
                    solvelayer(n,row+1);
                }
                colUsed[i] = false;
            }
        }
    }
    
    public ArrayList<String[]> solveNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n==0){
            return new ArrayList<String[]>();
        }
        res = new int[n];
        colUsed = new boolean[n];
        resarray = new ArrayList<String[]>();
        solvelayer(n,0);
        return resarray;
    }
}