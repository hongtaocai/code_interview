class Solution {
public:
    inline int from2dTo1d(int a, int b, int n) {
        return a*n + b;
    }
    
    inline int from1dTo2d(int& a, int &b, int t, int m) {
        a = t/m;
        b = t - a*m;
    }
    
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = m*n-1;
        while(start <= end) {
            int mid = ((end-start)/2) + start;
            int mida = 0;
            int midb = 0;
            from1dTo2d(mida,midb,mid,m);
            int midVal = matrix[mida][midb];
            if(midVal== target) {
                return true;
            }
            if(midVal<target) {
                start = mid+1;
            }
            if(midVal>target) {
                end = mid-1;
            }
        }
        return false;
    }
};
