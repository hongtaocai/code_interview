class Solution {
public:
    int gcd(int a, int b) {
        if(a==0) {
            return b;
        } 
        return gcd(b%a, a);
    }

    void rotate(int nums[], int n, int k) {
        k = k%n;
        k = n-k;
        int g = gcd(k, n);
        int start = 0;
        int temp = 0;
        
        for(start = 0; start < g; start++) {
            int i = start;
            temp = nums[start];
            while((i+k)%n != start) {
                nums[i] = nums[(i+k)%n];
                i = (i+k)%n;
            }
            nums[i] = temp;
        }
    }
};
