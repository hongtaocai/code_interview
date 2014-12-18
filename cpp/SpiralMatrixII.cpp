class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int m = n;
        if(n==0) {
            return vector<vector<int> >();
        }
        vector<vector<int> > matrix(n);
        for(int i=0;i<n;++i) {
            matrix[i] = vector<int>(n);
            for(int j=0;j<n;++j) {
                matrix[i][j] = 0;
            }
        }
        int count = 1;
        
        int startrow = 0;
        int startcol = 0;
        while(startrow <=m-1-startrow && startcol <= n-1-startcol) {
            if(startrow == m-1-startrow) {
                for(int i=startcol;i<=n-1-startcol;++i) {
                    matrix[startrow][i] = count++;
                }
                break;
            }
            if(startcol == n-1-startcol) {
                for(int i=startrow;i<=m-1-startrow;++i) {
                    matrix[i][startcol] = count++;
                }
                break;
            }
            for(int i=startcol;i<n-1-startcol;++i) {
                matrix[startrow][i] = count++;
            }
            for(int i=startrow;i<m-1-startrow;++i) {
                matrix[i][n-1-startcol] = count++;
            }
            for(int i=n-1-startcol;i>startcol;--i) {
                matrix[m-1-startrow][i] = count++;
            }
            for(int i=m-1-startrow;i>startrow;--i) {
                matrix[i][startcol] = count++;
            }
            startrow++;
            startcol++;
        }
        return matrix;
    }
};
