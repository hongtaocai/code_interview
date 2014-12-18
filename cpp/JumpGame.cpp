class Solution {
public:
    bool canJump(int A[], int n) {
        int rightmost = 0;
        int start = 0;
        while(start<=rightmost) {
            rightmost = max(start + A[start],rightmost);
            if(rightmost>=n-1) {
                return true;
            }
            start++;
        }
        return false;
    }
    
};
