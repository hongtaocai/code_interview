class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> minP(prices.size(), INT_MAX);
        int res = 0;
        for(int i=0;i<minP.size();i++) {
            if(i==0) {
                minP[i] = prices[i];
            } else {
                minP[i] = min(minP[i-1], prices[i]);
            }
        }
        int maxP = 0;
        for(int i=minP.size()-1;i>=1;i--) {
            if(i==minP.size()-1) {
                maxP = prices[i];
                res = max(res, maxP-minP[i-1]);
            } else {
                maxP = max(maxP, prices[i]);
                res = max(res, maxP-minP[i-1]);
            }
        }
        return res;
    }
};
