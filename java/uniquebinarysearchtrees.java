public class Solution {
    
    public int numTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int num[] = new int[n+1];
        num[1] = 1;
        num[2] = 2;
        for(int i=3;i<=n;i++){
            num[i]=0;
            num[i]+=num[i-1]*2;
            for(int j=2;j<=i-1;j++){
                num[i]+=num[j-1]*num[i-j];
            }
        }
        return num[n];
    }
}