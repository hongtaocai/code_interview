class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int* steps = new int[n+1];
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;
        for(int i=3;i<n+1;i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        int res = steps[n];
        delete[] steps;
        return res;
    }
};
