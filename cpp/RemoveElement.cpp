class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int right = n-1;
        int left = 0;
        while(left<=right) {
            if(A[left] == elem) {
                A[left] = A[right];
                right--;
            }
            else {
                left++;
            }
        }
        return right+1;
    }
};
