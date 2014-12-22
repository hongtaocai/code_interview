class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        int curL = -1;
        int curH = -1;
        int res = 0;
        for(int i=1;i<n;i++) {
            if(prices[i]>prices[i-1]) {
                if(curL<0 && curH<0) {
                    curL = prices[i-1];
                    curH = prices[i];
                } else {
                    curH = prices[i];
                }
            } else {
                if(curL>=0 && curH>=0) {
                    res += (curH-curL);
                    curH = -1;
                    curL = -1;
                }
            }
        }
        if(curL>=0 && curH>=0) {
            res += (curH-curL);
        }
        return res;
    }
};
