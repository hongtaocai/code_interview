class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while(start <= end) {
            int mid = (end-start)/2+start;
            if(A[mid] == target) {
                return mid;
            } else if(A[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return start;
    }
};
