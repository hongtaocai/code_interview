class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while(start <= end) {
            if(A[start]==target) {
                return start;
            }
            if(A[end]==target) {
                return end;
            }
            int mid = (end-start)/2+start;
            if(A[mid]==target) {
                return mid;
            }
            if(A[start]<A[mid] && A[mid] < A[end]) {
                if(target<A[mid]) {
                    start = start+1;
                    end = mid-1;
                }
                else {
                    start = mid+1;
                    end = end-1;
                }
            } else if(A[start]<A[mid] && A[mid] > A[end]) {
                if(target < A[mid] && target > A[start]) {
                    start = start+1;
                    end = mid-1;
                } else {
                    start = mid+1;
                    end = end-1;
                }
            } else {
                if(target < A[end] && target > A[mid]) {
                    start = mid+1;
                    end = end-1;
                } else {
                    start = start+1;
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};
