public class Solution {
    public int numDistinct(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int s1 = S.length();
        int t1 = T.length();
        int k[][] = new int[s1+1][];
        for(int i=0;i<s1+1;i++){
            k[i] =new int[t1+1];
            k[i][0] = 1;
        }
        for(int j=1;j<t1+1;j++){
            k[0][j]=0;
        }
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=t1;j++){
                if(S.charAt(i-1)==T.charAt(j-1)){
                    k[i][j] = k[i-1][j-1] + k[i-1][j];
                }
                else{
                    k[i][j] = k[i-1][j];
                }
            }
        }
        
        
        return k[S.length()][T.length()];
    }
}