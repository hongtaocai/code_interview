public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        int map[][] = new int[m][n];
        map[0][0] = 1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]!=1){
                map[i][0] = map[i-1][0];
            }
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]!=1){
                map[0][j] = map[0][j-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                    map[i][j] = map[i-1][j] + map[i][j-1]; 
                }
            }
        }
        return map[m-1][n-1];
    }
}