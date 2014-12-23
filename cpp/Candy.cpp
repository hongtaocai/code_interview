class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if(n<=1) {
            return n;
        }
        vector<int> candies(n, 0);
        candies[0] = 1;
        for(int i=1;i<n;i++) {
            candies[i-1] = max(1, candies[i-1]);
            if(ratings[i]>ratings[i-1]) {
                candies[i] = candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--) {
            candies[i+1] = max(1, candies[i+1]);
            if(ratings[i]>ratings[i+1]) {
                candies[i] = max(candies[i+1]+1, candies[i]);
            } 
        }
        
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += candies[i];
        }
        return sum;
    }
};
