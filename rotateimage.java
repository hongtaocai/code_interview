public class Solution {
    
    private void rotatelayer(int[][] matrix, int x1, int x2){
        
    }
    
    public void rotate(int[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = matrix.length;
        if(m==0) return;
        int x1 = 0;
        int x2 = m-1;
        int tmp = 0;
        
        while(x1<x2){
            int n = x2-x1;
            //[x1,x1][x1,x2] -- [x1,x2][x2,x2]
            for(int i=0;i<n;i++){
                tmp = matrix[x1][x1+i];
                matrix[x1][x1+i] = matrix[x1+i][x2];
                matrix[x1+i][x2] = tmp;
            }
            //[x2,x2][x2,x1]
            for(int i=0;i<n;i++){
                tmp = matrix[x1][x1+i];
                matrix[x1][x1+i] = matrix[x2][x2-i];
                matrix[x2][x2-i] = tmp;
            }
            //[x2,x1][x1,x1]
            for(int i=0;i<n;i++){
                tmp = matrix[x1][x1+i];
                matrix[x1][x1+i] = matrix[x2-i][x1];
                matrix[x2-i][x1] = tmp;
            }
            x1++;
            x2--;
        }
    }
}