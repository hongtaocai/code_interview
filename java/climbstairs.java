public class Solution {
    public int climbStairs(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int k[] = new int[n+1];
        k[1] = 1;
        k[2] = 2;
        for(int i=3;i<=n;i++){
            k[i] = k[i-1]+k[i-2];
        }
        return k[n];
    }
}