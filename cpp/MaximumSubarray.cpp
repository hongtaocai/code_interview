class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        int sumEndingWithCurrentIndex = A[0];
        int maxSum = A[0];
        for(int i=1;i<n;++i) {
            sumEndingWithCurrentIndex = max(sumEndingWithCurrentIndex+A[i], A[i]);
            maxSum = max(maxSum, sumEndingWithCurrentIndex);
        }
        return maxSum;
    }
};
