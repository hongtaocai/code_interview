class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = (int)matrix.size();
        if(m==0) {
            return;
        }
        int n = (int)matrix[0].size();
        if(n==0) {
            return;
        }
        int zeroRow = -1;
        for(int i=0;i<m;i++) {
            if(zeroRow!=-1) {
                break;
            }
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    zeroRow = i;
                    break;
                }
            }
        }
        if(zeroRow==-1) {
            return;
        }
        for(int j=0;j<n;j++) {
            for(int i=0;i<m;i++) {
                if(matrix[i][j] == 0) {
                    matrix[zeroRow][j] = 0;
                }
            }
        }
        for(int i=zeroRow+1;i<m;i++) {
            bool hasZero = false;
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) {
                    hasZero = true;
                }
            }
            if(hasZero) {
                for(int j=0;j<n;j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=0;j<n;j++) {
            if(matrix[zeroRow][j]==0) {
                for(int i=0;i<m;i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=0;j<n;j++) {
            matrix[zeroRow][j] = 0;
        }
    }
};
