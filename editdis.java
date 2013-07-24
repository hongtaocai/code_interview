public class Solution {
    public int minDistance(String word1, String word2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int t1 = word1.length();
        int t2 = word2.length();
        int[][] k= new int[t1+1][t2+1];
        for(int i=0;i<t1+1;i++){
            k[i][0] = i;
        }
        for(int i=0;i<t2+1;i++){
            k[0][i] = i;
        }
        for(int i=1;i<t1+1;i++){
            for(int j=1;j<t2+1;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    k[i][j]=k[i-1][j-1];
                }else{
                    k[i][j] = Math.min(k[i-1][j-1]+1, k[i][j-1]+1);
                    k[i][j] = Math.min(k[i][j],k[i-1][j]+1);
                }
            }
        }
        return k[t1][t2];
    }