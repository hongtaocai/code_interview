class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(n+m,m)
        if(m==0 || n==0) {
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
        
        for(int i=0;i<m;i++) {
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++) {
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
