class Solution {
public:
    int tmp;
    int n;
    int start;
    int i;
    
    inline void swap(vector<vector<int> > &matrix, int i1, int j1, int i2, int j2) {
        tmp = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = tmp;
    }
    
    inline void swap(int& a, int&  b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void rotate(vector<vector<int> > &matrix) {
        n = matrix.size();
        if(n<=1) {
            return;
        }
        for(start = 0; start < n-1-start; start++) {
            for(i=start;i<n-1-start;i++) {
                swap(matrix[start][i], matrix[i][n-1-start]);
            }
            for(i=start;i<n-1-start;i++) {
                swap(matrix[start][i], matrix[n-1-start][n-1-i]);
            }
            for(i=start;i<n-1-start;i++) {
                swap(matrix[start][i], matrix[n-1-i][start]);
            }
        }
    }
};
