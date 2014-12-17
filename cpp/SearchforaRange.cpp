class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int b = searchFirstBigger(A, n, target);
        int a = searchFirstSmaller(A, n, target);
        if(b-1>=a+1) {
            return vector<int>{a+1,b-1};
        } else {
            return vector<int>{-1,-1};
        }
    }
    
    int searchFirstSmaller(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        if(A[0]>target) {
            return -1;
        }
        while(start<=end) {
            int mid = (end-start)/2 + start;
            if(A[mid] < target && (mid==end || A[mid+1] >= target)) {
                return mid;
            }
            if(A[mid] >= target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
    }
    
    int searchFirstBigger(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        if(A[end] < target) {
            return n;
        }
        while(start<=end) {
            int mid = (end-start)/2 + start;
            if(A[mid] > target && (mid==start || A[mid-1] <= target)) {
                return mid;
            }
            if(A[mid] <= target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return n;
    }
};
