class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) {
            return dividend;
        }
        long long int dividend_ = dividend;
        long long int divisor_ = divisor;
        bool isNeg = false;
        if( (dividend^divisor) < 0) {
            isNeg = true;
        }
        
        if(dividend<0) {
            dividend_ = -dividend_;
        }
        if(divisor<0) {
            divisor_ = -divisor_;
        }
        
        long long int numdigit = 0;
        while((divisor_ << numdigit) <= dividend_) {
            numdigit++;
        } 
        numdigit--;
        long long int res = 0;
        while(numdigit>=0) {
            if(dividend_ >= (divisor_ << numdigit)) {
                dividend_ -= (divisor_ << numdigit);
                res += (1LL << numdigit);
            }
            numdigit--;
        }
        if(isNeg) {
            return (int)(-res);
        }

        if(res > 0x7fffffffLL) {
            return 0x7fffffff;
        }
        return res;
    }
};
