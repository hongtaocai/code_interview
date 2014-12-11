class Solution {
public:
    int reverse(int x1) {
        bool pos = (x1>=0);
        long long int x = x1;
        if(!pos) {
            x = -x;
        }
        long long int y = 0;
        while(x>=10) {
            y += x%10;
            y *= 10;
            x = x/10;
        }
        y += x;
        if (y > 2147483647LL) {
            return 0;
        }
        if(!pos) {
            y = -y;
        }
        return y;
    }
};
