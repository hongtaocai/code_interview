class Solution {
public:
    int sqrt(int x) {
        double t = 1.0;
        while(true) {
            double t1 = 0.5*(t+x/t);
            if(fabs(t-t1)<1e-6) {
                break;
            }
            t = t1;
        }
        return int(t);
    }
};
