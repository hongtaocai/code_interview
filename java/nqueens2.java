public class Solution {
    public int totalNQueens(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n==0){
            return 0;
        }
        res = new int[n];
        colUsed = new boolean[n];
        resnum = 0;
        solvelayer(n,0);
        return resnum;
    }
    
    int res[];
    int resnum;
    boolean colUsed[];
    int resnum1;
    int resnum2;
    
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
            if(row==0){
                if(n%2==1){
                    if(i==n/2){
                        
                    }
                }else{
                    if(i==n/2){
                        resnum = resnum*2;
                        return;
                    }
                }
            }
            if(!colUsed[i] && check(row,i)){
                colUsed[i] = true;
                res[row] = i;
                if(row==n-1){
                    resnum ++;
                }else{
                    solvelayer(n,row+1);
                }
                colUsed[i] = false;
            }
        }
    }
}