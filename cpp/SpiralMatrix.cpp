class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> spiralnumbers;
        int m = matrix.size();
        if(m==0) {
            return spiralnumbers;
        }
        int n = matrix[0].size();
        if(n==0) {
            return spiralnumbers;
        }
        int startrow = 0;
        int startcol = 0;
        while(startrow <=m-1-startrow && startcol <= n-1-startcol) {
            if(startrow == m-1-startrow) {
                for(int i=startcol;i<=n-1-startcol;++i) {
                    spiralnumbers.push_back(matrix[startrow][i]);
                }
                break;
            }
            if(startcol == n-1-startcol) {
                for(int i=startrow;i<=m-1-startrow;++i) {
                    spiralnumbers.push_back(matrix[i][startcol]);
                }
                break;
            }
            for(int i=startcol;i<n-1-startcol;++i) {
                spiralnumbers.push_back(matrix[startrow][i]);
            }
            for(int i=startrow;i<m-1-startrow;++i) {
                spiralnumbers.push_back(matrix[i][n-1-startcol]);
            }
            for(int i=n-1-startcol;i>startcol;--i) {
                spiralnumbers.push_back(matrix[m-1-startrow][i]);
            }
            for(int i=m-1-startrow;i>startrow;--i) {
                spiralnumbers.push_back(matrix[i][startcol]);
            }
            startrow++;
            startcol++;
        }
        return spiralnumbers;
    }
};
