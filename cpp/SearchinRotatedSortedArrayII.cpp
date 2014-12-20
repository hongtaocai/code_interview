class Solution {
public:
    bool search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while(start <= end) {
            int mid = (end-start)/2+start;
            if(A[start]==target || A[mid] == target || A[end]==target) {
                return true;
            }
            if(A[start] > A[mid]) {
                if(target>A[mid] && target < A[start]) {
                    start = mid+1;
                    end = end-1;
                }
                else {
                    start = start+1;
                    end = mid-1;
                }
            } else if(A[start] < A[mid]) {
                if(target>A[start] && target < A[mid]) {
                    start = start+1;
                    end = mid-1;
                } else {
                    start = mid+1;
                    end = end-1;
                }
            } else {
                start++;
            }
        }
        return false;
    }
};
