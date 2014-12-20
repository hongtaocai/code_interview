class Solution {
public:
    void sortColors(int A[], int n) {
        int zeroBoundary = 0; // < zeroBoundary is 0
        int twoBoundary = n-1; // > twoBOundary is 2
        int start = 0;
        while(start <= twoBoundary) {
            if(A[start] == 0) {
                A[start] = A[zeroBoundary];
                A[zeroBoundary] = 0;
                zeroBoundary++;
                if(zeroBoundary>start) {
                    start = zeroBoundary;
                }
            } else if(A[start] == 2) {
                A[start] = A[twoBoundary];
                A[twoBoundary] = 2;
                twoBoundary--;
            } else {
                start++;
            }
        }
    }
};
