class Solution {
public:
    int jump(int A[], int n) {
        int rightmost = 0;
        int start = 0;
        int* minstep = new int[n];
        for(int i=1;i<n;i++) {
            minstep[i] = 0x7fffffff;
        }
        minstep[0] = 0;
        while(start<=rightmost) {
            if(start + A[start] > rightmost) {
                rightmost = start + A[start];
                if(rightmost>n-1) {
                    rightmost = n-1;
                }
                for(int i=start+1;i<=rightmost;i++) {
                    if (minstep[i] > minstep[start]+1) {
                        minstep[i] = minstep[start]+1;
                    }
                }
            }
            start++;
        }
        return minstep[n-1];
    }
};
