class Solution {
public:
    int trailingZeroes(int m) {
        long long int n = m;
        if(n<=4) return 0;
        int sum = 0;
        long long int div = 5;
        while(true) {
            int t= n/div;
            if(t==0) return sum;
            sum += t;
            div *=5;
        }
        return 0;
    }
};
