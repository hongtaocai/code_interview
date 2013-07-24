public class Solution {
    public void setZeroes(int[][] matrix) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(matrix.length==0){
            return;
        }
        int zerorow = 0;
        loop1: for(zerorow=0;zerorow<matrix.length;zerorow++){
            for(int j=0;j<matrix[zerorow].length;j++){
                if(matrix[zerorow][j]==0) break loop1;
            }
        }
        if(zerorow==matrix.length){
            return;
        }
        for(int i=0;i<matrix[0].length;i++){
            for(int j=zerorow;j<matrix.length;j++){
                if(matrix[j][i]==0){
                    matrix[zerorow][i]=0;
                    break;
                }
            }
        }
        int flag = 0;
        for(int i=zerorow+1;i<matrix.length;i++){
            flag = 0;
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==0){
                    flag = 1;
                    break;
                }
            }
            if(flag==1){
                for(int j=0;j<matrix[0].length;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<matrix[0].length;i++){
            if(matrix[zerorow][i]==0){
                for(int j=0;j<matrix.length;j++){
                    matrix[j][i]=0;
                }
            }
        }
        for(int i=0;i<matrix[0].length;i++){
            matrix[zerorow][i]=0;
        }
    }
}