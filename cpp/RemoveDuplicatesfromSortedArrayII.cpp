class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) {
            return 0;
        }
        int count = 1;
        int last = A[0];
        int j = 1;
        for(int i=1;i<n;i++) {
            if(A[i]==last) {
                count++;
            } else {
                count = 1;
                last = A[i];
            }
            if(count<3) {
                A[j] = A[i];
                j++;
            }
        }
        return j;
    }
};
