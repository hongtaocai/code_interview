class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((n+m)%2==0) {
            return (findKthFromSortedArrays(A, m, B, n, (n+m)/2)
                    + findKthFromSortedArrays(A, m, B, n, (n+m)/2+1))/2.0;
        }
        else {
            return findKthFromSortedArrays(A, m, B, n, (n+m)/2+1);
        }
    }
    
    // k start from 0
    double findKthFromSortedArrays(int A[], int m, int B[], int n, int k) {
        while(true) {
            if (m==0) {
                return B[k-1];
            }
            if (n==0) {
                return A[k-1];
            }
            if (k==1) {
                return A[0] < B[0] ? A[0]:B[0];
            }
            int kA = k/2;
            if (m<kA) {
                kA = m;
            }
            int kB = k - kA;
            if (n<kB) {
                kB = n;
                kA = k - kB;
            }
            int midA = kA-1;
            int midB = kB-1;
            if(A[midA] == B[midB]) {
                return A[midA];
            }
            if(A[midA] < B[midB]) {
                A = A + kA;
                m = m - kA;
                n = kB;
                k = kB;
                //return findKthFromSortedArrays(A + kA , m - kA, B,  kB, kB);
            }
            else{
                m = kB;
                B = B + kB;
                n = n - kB;
                k = kA;
            }
        }
    }
};
