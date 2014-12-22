class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0) {
            return 0;
        }
        vector<int> maxProfitLeft(prices.size(), INT_MIN);
        int minPrice = prices[0];
        maxProfitLeft[0] = 0;
        for(int i=1;i<prices.size();i++) {
            int profitSellNow = prices[i]-minPrice;
            minPrice = min(minPrice, prices[i]);
            maxProfitLeft[i] = max(maxProfitLeft[i-1], profitSellNow);
        }
        int n = prices.size();
        vector<int> maxProfitRight(n, INT_MIN);
        int maxPrice = prices[n-1];
        maxProfitRight[n-1] = 0;
        for(int i=n-2;i>=0;i--) {
            int profitBuyNow = maxPrice - prices[i];
            maxPrice = max(maxPrice, prices[i]);
            maxProfitRight[i] = max(maxProfitRight[i+1], profitBuyNow);
        }
        int maxProfit = 0;
        for(int i=0;i<n-1;i++) {
            maxProfit = max(maxProfit, maxProfitLeft[i] + maxProfitRight[i+1]);
        }
        maxProfit = max(maxProfit, maxProfitLeft[n-1]);
        return maxProfit;
    }
};
