class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = (int)grid.size();
        if(row==0) {
            return 0;
        }
        int col = (int)grid[0].size();
        if(col==0) {
            return 0;
        }
        int* dp = new int[col];
        for(int i=0;i<col;i++) {
            dp[i] = 0x7fffffff;
        }
        dp[0] = 0;
        for(int i=0;i<row;i++) {
            dp[0] += grid[i][0];
            for(int j=1;j<col;j++) {
                dp[j] = min(dp[j-1],dp[j]) + grid[i][j];
            }
        }
        int res = dp[col-1];
        delete[] dp;
        return res;
    }
};
