class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = (int)obstacleGrid.size();
        if(m==0) {
            return 0;
        }
        int n = (int)obstacleGrid[0].size();
        if(n==0) {
            return 0;
        }
        vector<vector<int> > dp(m);
        for(int i=0;i<m;i++) {
            vector<int> rowData(n);
            for(int j=0;j<n;j++){
                rowData[j] = 0;
            }
            dp[i] = rowData;
        }
        
        if(obstacleGrid[0][0] == 1) {
            dp[0][0] = 0;
        } else {
            dp[0][0] = 1;
        }
        
        for(int i=1;i<m;i++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=1;j<n;j++) {
            if(obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(obstacleGrid[i][j]==1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] += dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
