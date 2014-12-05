public class Solution {
    private int combin(int s,int r){
        int c[][] = new int[s+1][r+1];
        for(int i=0;i<s+1;i++){
            c[i][0] = 1;
        }
        for(int i=0;i<r+1;i++){
            c[i][i] = 1;
        }
        for(int i=1;i<=s;i++){
            for(int j=1;j<=r;j++){
                if(j<i){
                    c[i][j] = c[i-1][j-1] + c[i-1][j];
                }
            }
        }
        return c[s][r];
    }
    
    public int uniquePaths(int m, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        // C_(m+n)^(n)
        int r = Math.min(m-1,n-1);
        int sub = m+n-2;
        return combin(sub,r);
    }
}