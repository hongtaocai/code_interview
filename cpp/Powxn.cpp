class Solution {
public:
    double pow(double x, int n1) {
        long long int n = n1;
        return powll(x, n);
    }
    
    double powll(double x, long long int n) {
        if(x==0.0) {
            return 0.0;
        }
        int neg = (x>0)? 1:-1;
        if(n==0) {
            return 1.0;
        }
        if(n<0) {
            return 1.0/powll(x,-n);
        }
        if(n%2==1) {
            double t = powll(x, n/2);
            return t*t*x;
        }
        else {
            double t = powll(x, n/2);
            return t*t;
        }
    }
};
