class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int max = 0;
        for(int i=0;i<n;i++) {
            max = (A[i]>max)? A[i]:max;
        }
        if(max==0) {
            return 1;
        }
        for(int i=0;i<n;i++) {
            if(A[i] <=0) {
                A[i] = max+1;
            }
        }
        int t = 0;
        for(int i=0;i<n;i++) {
            if(abs(A[i])==max+1) {
                continue;
            } else {
                t = abs(A[i])-1;
                if(t<n) {
                    A[t] = -abs(A[t]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(A[i]>0) {
                return i+1;
            }
        }
        return n+1;
    }
};
