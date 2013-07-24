public class Solution {
    public int minPathSum(int[][] grid) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(grid.length==0){
            return 0;
        }
        if(grid[0].length==0){
            return 0;
        }
        
        int [][]m = new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(i==0 && j==0){
                    m[i][j] = grid[i][j];
                }else if(i==0){
                    m[i][j] = grid[i][j] + m[i][j-1];
                }else if(j==0){
                    m[i][j] = grid[i][j]+m[i-1][j];
                }else{
                    m[i][j] = Math.min(m[i][j-1],m[i-1][j])+grid[i][j];
                }
            }
        }
        return m[grid.length-1][grid[0].length-1];
    }
}