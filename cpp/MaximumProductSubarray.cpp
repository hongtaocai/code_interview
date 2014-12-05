class Solution {
public:
    inline int min(int a, int b) {
        return (a<b) ? a:b;
    }
    
    inline int max(int a, int b) {
        return (a>b) ? a:b;
    }

    inline int max(int a, int b, int c) {
        return max(a,max(b,c));
    }
    
    inline int min(int a, int b, int c) {
        return min(a,min(b,c));
    }
    
    int maxProduct(int A[], int n) {
        if(n==0) {
            return 0;
        }
        int maxCur = A[0];
        int minCur = A[0];
        int maxP = A[0];
        for(int i=1; i<n; i++) {
            int maxCur_ = maxCur;
            int minCur_ = minCur;
            maxCur = max(A[i], minCur_*A[i], maxCur_*A[i]);
            minCur = min(A[i], minCur_*A[i], maxCur_*A[i]);
            maxP = max(maxP, maxCur, minCur);
        }
        return maxP;
    }
};
