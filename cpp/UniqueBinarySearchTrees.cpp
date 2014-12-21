class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> catalan(n+1);
        catalan[0] = 1;
        catalan[1] = 1;
        catalan[2] = 2;
        for(int i=3;i<=n;i++) {
            catalan[i] = 0;
            for(int j=0;j<=i-1;j++) {
                catalan[i] += catalan[j]*catalan[i-1-j];
            }
        }
        return catalan[n];
    }
};
