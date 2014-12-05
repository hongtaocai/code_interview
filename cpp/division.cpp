class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long d =0;
        long long n=1;
        long long tmp = b;
        while(tmp <= a){
            n++;
            tmp <<= 1;
        }
        while(n--){
            if(tmp <= a){
                a -= tmp;
                d |= 1<<n;
            }
            tmp >>=1;
        }
        if(dividend<0 && divisor>0) d = -d;
        else if(dividend>0 && divisor<0) d=-d;
        return d;
    }
};