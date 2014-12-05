public class Solution {
    
    private boolean withinBound(int x, int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    
    public int[][] generateMatrix(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i=1;
        int nn = n*n;
        int[][] ans = new int[n][n];
        int x =0;
        int y =0;
        int dirx = 0;
        int diry = 1;
        while(i<=nn){
            ans[x][y] = i;
            if(i==nn) break;
            int newx = x+dirx;
            int newy = y+diry;
            if(withinBound(newx,newy,n) && ans[newx][newy]==0 ){
                x = newx;
                y = newy;
            }else{
                int newdirx = diry;
                int newdiry = -dirx;
                dirx = newdirx;
                diry = newdiry;
                x = x+dirx;
                y = y+diry;
            }
            i++;
        }
        return ans;
    }
}