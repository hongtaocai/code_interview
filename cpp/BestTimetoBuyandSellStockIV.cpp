class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        // lMaxP(k,n) = max(g(k-1,n-1) + diff, l(k, n-1) + diff)
        // gMaxP(k,n) = max(l(k,n) , g(k,n-1))
        int n = prices.size();
        if (k>n) {
            return maxProfitWithAnyTran(prices);
        }
        vector<int> l((k+1)*(n+1));
        vector<int> g((k+1)*(n+1));
        for(int i=0;i<(k+1)*(n+1);i++) {
            l[i] = 0;
            g[i] = 0;
        }
        for(int i=1;i<=k;i++) {
            for(int j=1;j<=n;j++) {
                int diff = 0;
                if (j > 1 ) {
                    diff = prices[j-1] - prices[j-2];
                }
                l[i*(n+1)+j] = max(g[(i-1)*(n+1)+j-1] + diff, l[i*(n+1) + j-1] + diff);
                g[i*(n+1)+j] = max(l[i*(n+1)+j] , g[(i)*(n+1)+j-1]);
            }
        }
        return g[(k+1)*(n+1)-1];
    }
    
    int maxProfitWithAnyTran(const vector<int> &prices) {
        int n = (int) prices.size();
        int s = 0;
        for(int i=1;i<n;i++) {
            if (prices[i] > prices[i-1]) {
                s+= (prices[i] - prices[i-1]);
            }
        }
        return s;
    }
};
