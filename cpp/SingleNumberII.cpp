class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int count[32];
        memset(count, 0, sizeof(int)*32);
        for(int j=0;j<n;j++) {
            for(int i=0;i<32;i++) {
                count[i] += ((A[j]>>i)&1);
                if(count[i]==3) {
                    count[i] = 0;
                }
            }
        }
        int res = 0;
        for(int i=0;i<32;i++) {
            res += (count[i] << i);
        }
        return res;
    }
};
